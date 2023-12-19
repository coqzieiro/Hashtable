#include "hashtable.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_SIZE 52 // 52/0.8 = 65
#define LOAD_FACTOR_THRESHOLD 0.8

typedef struct node {
    int value;
    struct node* next;
} node;

struct _hashtbl {
    node** table;
    size_t tam;
};

// Função de hash
uint32_t murmurhash3_32(uint32_t key, size_t size) {
    key ^= key >> 16;
    key *= 0x85ebca6b;
    key ^= key >> 13;
    key *= 0xc2b2ae35;
    key ^= key >> 16;
    return key % size;
}

// Cria um novo nó com o valor passado
node* new_node(int value) {
    node* novo = malloc(sizeof(node));
    
    assert(novo); // checa falha de alocação

    novo->value = value;
    novo->next = NULL;

    return novo;
}

// Cria uma nova tabela, com no mínimo MIN_SIZE elementos
icmc_hashtbl* icmc_hashtbl_criar(size_t tam) {
    icmc_hashtbl* novo = malloc(sizeof(icmc_hashtbl));
    assert(novo); // checa falha de alocação

    // Para evitar colisões em tabelas pequenas
    tam = tam < MIN_SIZE ? MIN_SIZE : tam; 
    
    size_t load = (double)tam/LOAD_FACTOR_THRESHOLD;

    novo->table = calloc(load, sizeof(node*)); // ou item, tenho que ver
    assert(novo->table); // checa falha de alocação
    
    novo->tam = load;
    return novo;
}

// Verifica se elemento pertence à hashtable
bool icmc_hashtbl_pertence(icmc_hashtbl* tbl, int elemento) {
    uint32_t hash = murmurhash3_32(elemento, tbl->tam);

    node* cur = tbl->table[hash];

    // Percorre a lista até encontrar o elemento ou chegar ao fim
    while(cur){
        if(cur->value == elemento) return true;
        cur = cur->next;
    }

    return false;
}

// Insere elemento na hashtable
bool icmc_hashtbl_inserir(icmc_hashtbl* tbl, int elemento) {
    if(!tbl) return false;
    uint32_t hash = murmurhash3_32(elemento, tbl->tam);

    node* novo = new_node(elemento);

    if(tbl->table[hash]){
        // Não insere se o elemento já estiver na tabela
        if(icmc_hashtbl_pertence(tbl, elemento)){
            free(novo);
            return true;
        }
        novo->next = tbl->table[hash];
    }

    tbl->table[hash] = novo;

    return true;
}

// Remove elemento da hashtable
bool icmc_hashtbl_remover(icmc_hashtbl* tbl, int elemento) {
    if(!tbl) return false;
    uint32_t hash = murmurhash3_32(elemento, tbl->tam);

    node* cur = tbl->table[hash];
    if(!cur) return false;

    node* prev = NULL;
    while(cur){
        if(cur->value == elemento){
            if(prev) prev->next = cur->next;
            else tbl->table[hash] = cur->next;
            free(cur);
            return true;
        }
        prev = cur;
        cur = cur->next;
    }

    return false;
}

int* icmc_hashtbl_flatten(icmc_hashtbl* t){ 
    if(!t && !t->table) return NULL;

    // Aloca um array com o tamanho máximo de inserções possíveis
    int* tmp = calloc(t->tam * LOAD_FACTOR_THRESHOLD, sizeof(int));
    assert(tmp);

    int j = 0;
    for(int i = 0; i < t->tam; i++){
        node* cur = t->table[i];
        // Para cada nó, insere no vetor
        while(cur) {
            tmp[j++] = cur->value;
            cur = cur->next;
        }
    }

    return tmp; 
}

// Libera a memória alocada pela hashtable
void icmc_hashtbl_liberar(icmc_hashtbl* tbl) {
    for (int i = 0; i < tbl->tam; i++) {
        node* cur = tbl->table[i];
        // Libera cada nó da lista
        while (cur) {
            node* tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    free(tbl->table);
    free(tbl);
}

size_t icmc_hashtbl_size(icmc_hashtbl* t){ return t->tam; }
