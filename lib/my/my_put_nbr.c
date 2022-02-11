/*
** EPITECH PROJECT, 2021
** PSU_my_ls_2021
** File description:
** my_put_nbr
*/

#include "my.h"

void my_put_nbr(int nb)
{
  if (nb == -2147483648) {
    my_putstr("-2147483648");
    return;
  }
  if (nb < 0) {
    my_putchar('-');
    nb = -nb;
  }
  if (nb >= 10)
    my_put_nbr(nb / 10);
  my_putchar(nb % 10 + '0');
}
