#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

void k_complementares_varredura(List *list, const int k)
{
  int count = list_count(list);
  int i, j, arr[count];

  for (i = 0; i < count; i++) {
    arr[i] = list->value;
    list = list->next;
  }

  printf("\nAlgoritmo de varredura simples:\n");
  for (i = 0; i < count; i++) {
    for (j = 0; j < count; j++) {
      if (arr[i] <= arr[j] && arr[i] + arr[j] == k) {
        printf("{%d, %d}\n", arr[i], arr[j]);
      }
    }
  }
}

void k_complementares_hash(List *list, const int k)
{
  int tableSize = list_count(list) / 0.5; // Definir tamanho da tabela hash
  HashTable *hash = hash_create(tableSize);
  List *aux = list;

  while (aux) {
    hash_insert(hash, aux->value);
    aux = aux->next;
  }

  printf("\nAlgoritmo com tabela hash:\n");
  aux = list;
  while (aux) {
    int targetValue = k - aux->value;
    if (aux->value <= targetValue && hash_search(hash, targetValue)) {
      printf("{%d, %d}\n", aux->value, targetValue);
    }
    aux = aux->next;
  }

  hash_free(hash);
}
