/*
** EPITECH PROJECT, 2021
** PSU_my_ls_2021
** File description:
** tab_len
*/

#include "my.h"

size_t tab_len(char **tab)
{
  size_t i = 0;

  if (tab == NULL)
    return 0;
  while (tab[i])
    i++;
  return i;
}
