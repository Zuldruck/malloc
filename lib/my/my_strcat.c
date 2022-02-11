/*
** EPITECH PROJECT, 2021
** PSU_my_ls_2021
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *dest, char *src)
{
  int i = 0;
  int j = 0;
  char *result = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

  while (dest[i] != '\0') {
    result[i] = dest[i];
    i++;
  }
  while (src[j] != '\0') {
    result[i + j] = src[j];
    j++;
  }
  result[i + j] = '\0';
  return (result);
}
