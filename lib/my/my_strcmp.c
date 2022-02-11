/*
** EPITECH PROJECT, 2021
** PSU_my_ls_2021
** File description:
** my_strcmp
*/

int my_strcmp(const char *dest, const char *src)
{
  int i = 0;

  while (dest[i] != '\0' && src[i] != '\0') {
    if (dest[i] != src[i])
      return dest[i] - src[i];
    i++;
  }
  return dest[i] - src[i];
}
