#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <stdbool.h>
#include <stddef.h>

typedef struct _hashtbl icmc_hashtbl;

icmc_hashtbl* icmc_hashtbl_criar(size_t tam);
bool icmc_hashtbl_pertence(icmc_hashtbl* tbl, int elemento);
bool icmc_hashtbl_inserir(icmc_hashtbl* tbl, int elemento);
bool icmc_hashtbl_remover(icmc_hashtbl* tbl, int elemento);
void icmc_hashtbl_liberar(icmc_hashtbl* tbl);
int* icmc_hashtbl_nth(icmc_hashtbl* tbl, size_t n);
size_t icmc_hashtbl_size(icmc_hashtbl* tbl);
int* icmc_hashtbl_flatten(icmc_hashtbl* tbl);
void icmc_hashtbl_imprimir(icmc_hashtbl* tbl);

#endif
