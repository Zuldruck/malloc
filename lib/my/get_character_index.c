/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-lucas.sanchez
** File description:
** get_character_index
*/

#include "my.h"

int get_character_index(char *str, char c)
{
  int i = 0;

  while (str[i] != '\0') {
    if (str[i] == c)
      return i;
    i++;
  }
  return -1;
}
