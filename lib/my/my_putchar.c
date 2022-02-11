/*
** EPITECH PROJECT, 2021
** PSU_my_ls_2021
** File description:
** my_putchar
*/

#include "my.h"

void my_putchar(char c)
{
  write(1, &c, 1);
}
