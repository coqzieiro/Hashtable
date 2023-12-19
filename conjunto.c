#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"
#include "hashtable.h"

#define MIN(x, y) ((x) < (y) ? (x) : (y))

struct _conj {
    icmc_hashtbl* conjunto;
    size_t tam;
    bool zeroflag;
};

// Função de comparação para o qsort
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

// Cria novo conjunto
CONJUNTO* conj_criar(size_t tam) {
    icmc_hashtbl* tbl = icmc_hashtbl_criar(tam);

    CONJUNTO* novo = malloc(sizeof(CONJUNTO));
    assert(novo); // checa falha de alocação
    novo->conjunto = tbl;
    novo->tam = tam;
    novo->zeroflag = false;
    
    return novo;
}

// Insere elemento no conjunto
bool conj_inserir(CONJUNTO* pA, int elemento){
    if(elemento == 0) pA->zeroflag = true;
    return icmc_hashtbl_inserir(pA->conjunto, elemento);
}

// Verifica se elemento pertence ao conjunto
bool conj_pertence(CONJUNTO* pA, int elemento){
    return icmc_hashtbl_pertence(pA->conjunto, elemento);
}

// Remove elemento do conjunto
bool conj_remover(CONJUNTO* pA, int elemento){
    return icmc_hashtbl_remover(pA->conjunto, elemento);
}

// Retorna novo conjunto com a união dos conjuntos pA e pB
CONJUNTO* conj_uniao(CONJUNTO* pA, CONJUNTO* pB) {
    CONJUNTO* pC = conj_criar(pA->tam + pB->tam);

    // Cria arrays com os elementos dos conjuntos pA e pB e insere no conjunto pC
    
    int* tmparr = icmc_hashtbl_flatten(pA->conjunto);
    if(pA->zeroflag) conj_inserir(pC, 0);

    for (int i = 0; i < pA->tam; i++){
        if(tmparr[i]) conj_inserir(pC, tmparr[i]);
    }
    free(tmparr);
    
    tmparr = icmc_hashtbl_flatten(pB->conjunto);
    if(pB->zeroflag) conj_inserir(pC, 0);
    for (int i = 0; i < pB->tam; i++){
        if(tmparr[i]) conj_inserir(pC, tmparr[i]);
    }
    free(tmparr);

    return pC; // Retorna a união dos conjuntos pA e pB em pC
}

// Retorna novo conjunto com a interseção dos conjuntos pA e pB
CONJUNTO* conj_interseccao(CONJUNTO* pA, CONJUNTO* pB) {
    CONJUNTO* pC = conj_criar(MIN(pA->tam, pB->tam));
   
    // Pega o menor e o maior conjunto
    icmc_hashtbl* maior = pA->tam >= pB->tam ? pA->conjunto : pB->conjunto;
    icmc_hashtbl* menor = pA->tam < pB->tam ? pA->conjunto : pB->conjunto;

    // Cria um array com os elementos do menor conjunto
    int* tmparr = icmc_hashtbl_flatten(menor);

    // Insere no conjunto de interseção os elementos que pertencem ao maior conjunto
    for (int i = 0; i < pA->tam; i++) {
        if (icmc_hashtbl_pertence(maior, tmparr[i])) conj_inserir(pC, tmparr[i]);
    }

    free(tmparr);
    return pC; 
}

// Libera memória alocada para o conjunto
void conj_liberar(CONJUNTO* pA) {
    icmc_hashtbl_liberar(pA->conjunto);
    free(pA);
}

// Imprime o conjunto
void conj_imprimir(CONJUNTO* pA){ 
    int* arr = icmc_hashtbl_flatten(pA->conjunto);
    qsort(arr, pA->tam, sizeof(int), cmpfunc);

    for(int i = 0; i < pA->tam; i++){
        if(arr[i]) printf("%d, ", arr[i]);
        else if (arr[i] == 0 && pA->zeroflag) printf("%d, ", arr[i]), pA->zeroflag = false;
    }
    free(arr);
}
