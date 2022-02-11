/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-malloc-lucas.sanchez
** File description:
** realloc
*/

#include "malloc.h"

void* realloc(void *ptr, size_t size)
{
  void *new_ptr = NULL;

  new_ptr = malloc(size);
  if (!new_ptr)
    return NULL;
  memcpy(new_ptr, ptr, size);
  free(ptr);
  return new_ptr;
}
