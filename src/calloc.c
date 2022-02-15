/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-malloc-lucas.sanchez
** File description:
** calloc
*/

#include "malloc.h"

void *calloc(size_t nmemb, size_t size)
{
  // my_printf("calloc(%d)\n", size * nmemb);
  void *ptr = malloc(size * nmemb);

  if (!ptr)
    return NULL;
  return (memset(ptr, 0, size * nmemb));
}
