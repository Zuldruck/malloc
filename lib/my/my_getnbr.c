/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-pushswap-lucas.sanchez
** File description:
** my_getnbr
*/

int my_getnbr(char *str)
{
  int nb = 0;
  int neg = 1;
  int i = 0;

  while (str[i] && (str[i] == '+' || str[i] == '-')) {
    if (str[i] == '-')
      neg *= -1;
    i++;
  }
  while (str[i] >= '0' && str[i] <= '9') {
    nb = nb * 10 + (str[i] - '0');
    i++;
  }
  return nb * neg;
}
