#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "includes/list.h"

typedef struct ANIMAL_STRUCT
{
  char* name;
  int age;
} animal_t;

animal_t* animal_create(char* name, int age)
{
  animal_t* a = calloc(1, sizeof(struct ANIMAL_STRUCT));
  a->name = calloc(strlen(name), sizeof(char));
  strcpy(a->name, name);
  a->age = age;

  return a;
}

void animal_free(void* v)
{
  animal_t* a = (animal_t*) v;

  free(a->name);
  free(a);
}

int main(void)
{
  int i;
  animal_t* a1;
  animal_t* a2;
  animal_t* a3;
  animal_t* a4;
  animal_t* a5;
  animal_t* a6;
  list_t* ls = list_create(sizeof(animal_t*), &animal_free);

  a1 = list_add_item(ls, animal_create("Cow", 3));
  a2 = list_add_item(ls, animal_create("Cat", 5));
  a3 = list_add_item(ls, animal_create("Dog", 7));
  a4 = list_add_item(ls, animal_create("Chicken",23));
  a5 = list_add_item(ls, animal_create("Lamb", 1));
  a6 = animal_create("Turkey", 21);

  printf("Before removal:\n");
  for (i = 0; i < ls->size; i++)
    printf("\t%s\n", ((animal_t*) ls->items[i])->name);

  list_insert_item(ls, a6, 0);
  list_remove_item(ls, a3);
  list_remove_index(ls, 0);

  printf("After removal:\n");
  for (i = 0; i < ls->size; i++)
    printf("\t%s\n", ((animal_t*) ls->items[i])->name);

  list_free(ls);

  return 0;
}