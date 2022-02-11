/*
** EPITECH PROJECT, 2021
** PSU_my_ls_2021
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(char *str)
{
  int len = my_strlen(str);
  char *dest = NULL;

  if (!str)
    return NULL;
  dest = malloc(sizeof(char) * (len + 1));
  for (int i = 0; str[i]; ++i)
    dest[i] = str[i];
  dest[len] = 0;
  return dest;
}
