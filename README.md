# Simple Dynamic List in C

> - A very simple, dynamic list implementation in C.
> - Compiled with `-ansi` and `-pedantic` options.

---

## How to use?

> ### Setup
> 
> - Clone the repo
> 
> - Insert the header file and the C file into your project
> 
> - Include it where you need it
> 
> - Done!

---

> ### Usage
> 
> - First, a list must be created using the `list_create()` function.
>   
>   *Parameters*: **int item_size, (void) (\*free_func)(void\*)**
>   
>   > The **free_func** is a pointer to the function that is going to be used for freeing up memory space when removing an item from the list. It is also used when the list is 'destroyed'.
>   
>   ---
> 
> - Items can be added to the list using the `list_add_item()` function.
>   
>   *Parameters*: **list_t\* ls, void\* item**
>   
>   ---
> 
> - Items can be inserted into the list using the `list_insert_item()` function.
>   
>   *Parameters*: **list_t\* ls, void\* item, int index**
>   
>   > Note that if the index is out of the range of the list, the method returns immediately.
>   
>   ---
> 
> - The index of an item can be queried using the `list_index_of()` function.
>   
>   *Parameters*: **list_t\* ls, void\* item**
>   
>   > If the item is not in the list, **-1** is returned.
>   
>   ---
> 
> - An item can be removed from a list using the `list_remove_item()` function.
>   
>   *Parameters*: **list_t* ls, void\* item**
>   
>   ---
> 
> - An item can be remove from a list by index using the `list_remove_index()` function.
>   
>   *Parameters*: **list_t\* ls, void\* item, int index**
>   
>   ---
> 
> - A list can be freed using the `list_free()` function.
>   
>   *Parameters*: **list_t\* ls**
>   
>   > This will release every resource related to the list making it unusable!

Note that the `list_shift_left()` is not mentioned above. That is because it is only used as a helper function during the removing process. It should not be used anywhere else in normal situations as it does not act in a way a 'normal' shift does.

The header file contains more informations about the list its self and about the functions.
