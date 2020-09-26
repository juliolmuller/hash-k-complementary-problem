#include <stdlib.h>
#include <stdio.h>

typedef struct _list {
  int value;
  struct _list *next;
} List;

List *list_create_node(int value)
{
  List *list = (List *) malloc(sizeof(List));
  list->value = value;
  list->next = NULL;
  return list;
}

List *list_add(List *list, int value)
{
  if (!list) {
    return list_create_node(value);
  }
  List *aux = list;
  while (aux->next) {
    aux = aux->next;
  }
  aux->next = list_create_node(value);
  return list;
}

int list_count(List *list)
{
  int count = 0;
  List *aux = list;
  while (aux) {
    aux = aux->next;
    count++;
  }
  return count;
}

void list_print(List *list)
{
  List *aux = list;
  int i, count = list_count(list);
  printf("[");
  for (i = 0; i < count; i++) {
    printf("%d", aux->value);
    aux = aux->next;
    if (i < count - 1) {
      printf(", ");
    }
  }
  printf("]");
}

void list_clear(List *list)
{
  List *aux = list;
  while (list) {
    aux = list->next;
    free(list);
    list = aux;
  }
}
