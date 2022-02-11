/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-malloc-lucas.sanchez
** File description:
** reallocarray
*/

#include "malloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
  void *new_ptr = NULL;

  new_ptr = malloc(nmemb * size);
  if (!new_ptr)
    return NULL;
  memcpy(new_ptr, ptr, nmemb * size);
  free(ptr);
  return new_ptr;
}