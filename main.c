#include <stdlib.h>
#include <stdio.h>
#include "list.h"

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

  list_print(list);
}
