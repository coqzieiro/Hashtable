#include <stdio.h>
#include "conjunto.h"

int main(void) {
    unsigned tam1, tam2;
    scanf("%u", &tam1);
    scanf("%u", &tam2);
    
    CONJUNTO* conj1 = conj_criar(tam1); 
    CONJUNTO* conj2 = conj_criar(tam2); 

    while(tam1--){
        int tmp;
        scanf("%d", &tmp); 
        conj_inserir(conj1, tmp);
    }
    while(tam2--){
        int tmp;
        scanf("%d", &tmp); 
        conj_inserir(conj2, tmp);
    }
    
    int op;
    scanf("%d", &op);

    switch(op){
        case 1: {
            int num;
            scanf("%d", &num);
            if(conj_pertence(conj1, num)) 
                printf("Pertence.");
            else
                printf("Não Pertence.");
            break;
        }
        case 2: {
            CONJUNTO* conj3 = conj_uniao(conj1, conj2);
            conj_imprimir(conj3);
            conj_liberar(conj3);
            break;
        }
        case 3: {
            CONJUNTO* conj3 = conj_interseccao(conj1, conj2);
            conj_imprimir(conj3);
            conj_liberar(conj3);
            break;
        }
        case 4: {
            int num;
            scanf("%d", &num);
            conj_remover(conj1, num);
            conj_imprimir(conj1); 
        }
    }


    conj_liberar(conj1);
    conj_liberar(conj2);
}
