#include <stdlib.h>
#include <stdio.h>
#include "kcomp.h"

void main()
{
  int input, k;
  List *list = NULL;

  do {
    printf("Insira um valor a ser inserido na lista >>> ");
    scanf("%d", &input);
  } while (input && (list = list_add(list, input)));

  do {
    printf("Insira o valor a ser avaliado >>> ");
    scanf("%d", &k);
  } while (k <= 0);

  k_complementares_varredura(list, k);
  k_complementares_hash(list, k);
  list_clear(list);
}
