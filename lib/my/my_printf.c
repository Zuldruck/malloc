/*
** EPITECH PROJECT, 2021
** PSU_my_ls_2021
** File description:
** my_printf
*/

#include "my.h"

void print_format(const char *str, int i, va_list ap)
{
  if (str[i] == 'd') {
    my_put_nbr(va_arg(ap, int));
  }
  if (str[i] == 's') {
    my_putstr(va_arg(ap, char *));
  }
  if (str[i] == 'c') {
    my_putchar(va_arg(ap, int));
  }
  if (str[i] == '%') {
    my_putchar('%');
  }
}

void my_printf(const char *str, ...)
{
  va_list ap;
  int i = 0;

  va_start(ap, str);
  while (str[i] != '\0') {
    if (str[i] == '%') {
      ++i;
      print_format(str, i, ap);
    } else
      my_putchar(str[i]);
    ++i;
  }
  va_end(ap);
}
