#ifndef CONJUNTO_H
#define CONJUNTO_H
#include <stdbool.h>
#include <stddef.h>

typedef struct _conj CONJUNTO;

CONJUNTO* conj_criar(size_t tam);
CONJUNTO* conj_uniao(CONJUNTO* pA, CONJUNTO* pB);
CONJUNTO* conj_interseccao(CONJUNTO* pA, CONJUNTO* pB);
bool conj_pertence(CONJUNTO* pA, int elemento);
bool conj_inserir(CONJUNTO* pA, int elemento);
bool conj_remover(CONJUNTO* pA, int elemento);
void conj_liberar(CONJUNTO* pA);
void conj_imprimir(CONJUNTO* pA);

#endif
