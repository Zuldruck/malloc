/*
** EPITECH PROJECT, 2021
** PSU_my_ls_2021
** File description:
** my_strlen
*/

#include "my.h"

size_t my_strlen(const char *str)
{
  size_t i = 0;

  while (str && str[i] != '\0')
    ++i;
  return i;
}
