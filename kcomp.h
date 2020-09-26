#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void k_complementares_varredura(List *list, int k)
{
  int count = list_count(list);
  int i, j, arr[count];

  for (i = 0; i < count; i++) {
    arr[i] = list->value;
    list = list->next;
  }

  printf("\nAlgoritmo de varredura simples:\n");
  for (i = 0; i < count; i++) {
    if (arr[i] >= k) continue;
    for (j = 0; j < count; j++) {
      if (arr[i] + arr[j] == k) {
        printf("{%d, %d}\n", arr[i], arr[j]);
      }
    }
  }
}

void k_complementares_hash(List *list, int k)
{
  printf("\nAlgoritmo com tabela hash:\n");
}
