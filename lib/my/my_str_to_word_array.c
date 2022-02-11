/*
** EPITECH PROJECT, 2021
** PSU_my_ls_2021
** File description:
** my_str_to_word_array
*/

#include "my.h"

size_t get_word_number(char const *str, char *delimitors)
{
  size_t word_number = 0;

  for (size_t i = 0; str[i] != '\0'; i++) {
    if (str_contains(delimitors, str[i]))
      word_number++;
  }
  return word_number;
}

size_t get_word_length(char const *str, char *delimitors)
{
  size_t word_length = 0;

  for (size_t i = 0; str[i] != '\0'; i++) {
    if (str_contains(delimitors, str[i]))
      return word_length;
    word_length++;
  }
  return word_length;
}

size_t get_delimitors_number(char const *str, char *delimitors)
{
  size_t delimitors_number = 0;
  bool delimitor_found = false;

  for (size_t i = 0; str[i] != '\0'; i++) {
    if (str_contains(delimitors, str[i]))
      delimitor_found = true;
    if (!delimitor_found)
      return delimitors_number;
    ++delimitors_number;
    delimitor_found = false;
  }
  return delimitors_number;
}

char **my_str_to_word_array(char *str, char *delimitors)
{
  size_t j = 0;
  size_t k = 0;
  char **tab = NULL;

  if (!str)
    return NULL;
  tab = malloc(sizeof(char *) * (get_word_number(str, delimitors) + 2));
  for (size_t i = 0; str[i] != '\0';
  i += get_delimitors_number(str + i, delimitors)) {
    i += get_delimitors_number(str + i, delimitors);
    j = get_word_length(str + i, delimitors);
    i += j;
    tab[k] = malloc(sizeof(char) * (j + 1));
    for (size_t l = 0; l < j; l++)
      tab[k][l] = str[i - j + l];
    tab[k][j] = '\0';
    k++;
  }
  tab[k] = NULL;
  return tab;
}
