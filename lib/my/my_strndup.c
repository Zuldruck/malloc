/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-lucas.sanchez
** File description:
** my_strndup
*/

#include "my.h"

char *my_strndup(char *str, int n)
{
  char *new = malloc(sizeof(char) * (n + 1));
  int i = 0;

  if (new == NULL)
    return NULL;
  while (str[i] != '\0' && i < n) {
    new[i] = str[i];
    i++;
  }
  new[i] = '\0';
  return new;
}
