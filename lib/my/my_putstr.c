/*
** EPITECH PROJECT, 2021
** PSU_my_ls_2021
** File description:
** my_putstr
*/

#include "my.h"

void my_putstr(const char *str)
{
  write(1, str, my_strlen(str));
}
