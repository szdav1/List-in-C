#include <stdlib.h>
#include "includes/list.h"

list_t* list_create(const unsigned int item_size, void (*free_func)(void*))
{
  list_t* ls = calloc(1, sizeof(struct LIST_STRUCT));
  ls->size = 0;
  ls->item_size = item_size;
  ls->last_index = 0;
  ls->free_item = free_func;

  return ls;
}

void* list_add_item(list_t* ls, void* item)
{
  ls->size++;
  ls->last_index = ls->size-1;
  ls->items = ls->items == NULL ? calloc(ls->size, ls->item_size) : realloc(ls->items, ls->size*ls->item_size);
  ls->items[ls->last_index] = item;

  return item;
}

int list_index_of(list_t* ls, void* item)
{
  int i = 0;
  while (ls->items[i] != item && i < ls->size)
    i++;

  return i >= ls->size ? -1 : i;
}

void list_shift_left(list_t* ls, const unsigned int start)
{
  int i;
  for (i = start; i < ls->size-1; i++)
  {
    ls->items[i] = ls->items[i+1];
  }
}

void list_remove_item(list_t* ls, void* item)
{
  int item_index = list_index_of(ls, item);

  if (item_index < 0)
    return;


  list_shift_left(ls, item_index);
  ls->free_item(item);
  ls->size--;
  ls->last_index = ls->size-1;
  ls->items = realloc(ls->items, ls->size*ls->item_size);
}

void list_remove_index(list_t* ls, const unsigned int index)
{
  if (index >= ls->size)
    return;

  list_remove_item(ls, ls->items[index]);
}

void list_free(list_t* ls)
{
  int i;
  for (i = 0; i < ls->size; i++)
    ls->free_item(ls->items[i]);

  free(ls->items);
  free(ls);
}