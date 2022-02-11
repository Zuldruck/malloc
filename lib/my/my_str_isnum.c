/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-pushswap-lucas.sanchez
** File description:
** my_str_isnum
*/

#include "my.h"

bool my_str_isnum(char *str)
{
  int i = 0;

  if (str == NULL)
    return false;
  while (str[i] != '\0') {
    if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+')
      return false;
    i++;
  }
  return true;
}
