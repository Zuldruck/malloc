/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-malloc-lucas.sanchez
** File description:
** free
*/

#include "malloc.h"

void free(void *ptr)
{
  metadata_t *meta = NULL;
  
  if (!ptr)
    return;
  // my_printf("free(%u)\n", ptr);
  meta = get_metadata_from_ptr(ptr);
  meta->free = true;
}
