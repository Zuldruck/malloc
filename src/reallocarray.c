/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-malloc-lucas.sanchez
** File description:
** reallocarray
*/

#include "malloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
  if (!ptr)
    return NULL;
  return realloc(ptr, nmemb * size);
}
