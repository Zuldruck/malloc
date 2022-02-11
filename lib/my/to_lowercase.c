/*
** EPITECH PROJECT, 2021
** PSU_my_ls_2021
** File description:
** to_lowercase
*/

char *to_lowercase(char *str)
{
  int i = 0;

  while (str[i] != '\0') {
    if (str[i] >= 'A' && str[i] <= 'Z')
      str[i] = str[i] + 32;
    i++;
  }
  return (str);
}
