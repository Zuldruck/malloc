/*
** EPITECH PROJECT, 2021
** PSU_my_ls_2021
** File description:
** my_swap
*/

void my_swap(void **a, void **b)
{
  void *tmp = *a;

  *a = *b;
  *b = tmp;
}
