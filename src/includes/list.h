#ifndef _LIST_H
#define _LIST_H

/*
/=======================================================\
| Dynamically growing list implementation in C.         |
| The code was compiled using -ansi and -pedantic.      |
| (No mixed declarations and code)                      |
\=======================================================/

/============================================================================================\
| A list (struct) is created using the list_create() function.                               |
| There's a typedef list_t for the struct LIST_STRUCT for easier                             |
| use. Items are added to a list using the list_add_item() function.                         |
| Items are removed from a list using the list_remove_item() function.                       |
| Items are removed from a list based on their index using the list_remove_index()           |
| function. The index of a specific item can be queired using the list_index_of()            |
| fucntion. After a list is no longer needed, the list_free() function should be called,     |
| to release all resources related to it.                                                    |
| Note that the items in a list are freed when removing. For this reason, a function pointer |
| is required that points to a desired free method that will be used when removing. This     |
| function will also be used during the releasing of the list.                               |
\============================================================================================/

@author szd
*/
typedef struct LIST_STRUCT
{
  int size;
  int item_size;
  int last_index;
  void** items;
  void (*free_item)(void*);
} list_t;

/*
Used to create a list.
@param int: Item size
@param function pointer: The free method of the list
*/
list_t* list_create(const unsigned int, void (*free_func)(void*));

/*
Used to add an item to a list.
@param list_t*: The list the item should be added to
@param void*: The item the should be added to the list
*/
void* list_add_item(list_t*, void*);

/*
Used to find the index of a specific item inside a list.
@param list_t*: The list the item should be looked up in
@param void*: The item that's index should be found
*/
int list_index_of(list_t*, void*);

/*
Used to shift the items of the list one to the left.
This function is a helper function of the list_remove_item()
and list_remove_index() functions.
@param list_t*: The list the shift should be performed on
@param int: The starting index the shift
*/
void list_shift_left(list_t*, const unsigned int);

/*
Used to remove an item from a list.
@param list_t*: The list the item should be removed from
@param void*: The item that should be removed from the list
*/
void list_remove_item(list_t*, void*);

/*
Used to remove an item from a list via its index.
@param list_t*: The list the shift should be performed on
@param int: The index of the item that should be removed from the list
*/
void list_remove_index(list_t*, const unsigned int);

/*
Used to free the entire list.
@param list_t*: The list that should be freed.
*/
void list_free(list_t*);

#endif