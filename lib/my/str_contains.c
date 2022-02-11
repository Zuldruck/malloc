/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-lucas.sanchez
** File description:
** str_contains
*/

#include "my.h"

bool str_contains(char *str, char c)
{
  for (size_t i = 0; str[i] != '\0'; i++) {
    if (str[i] == c)
      return true;
  }
  return false;
}
