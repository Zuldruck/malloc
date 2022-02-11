/*
** EPITECH PROJECT, 2021
** PSU_my_ls_2021
** File description:
** my
*/

#ifndef MY_H_
  #define MY_H_

  #include <unistd.h>
  #include <stdlib.h>
  #include <stdarg.h>
  #include <stdbool.h>

  #define ABS(x) ((x) < 0 ? -(x) : (x))

void my_putchar(char c);
void my_putstr(const char *str);
void my_put_nbr(int nb);
size_t my_strlen(const char *str);
int my_strcmp(const char *s1, const char *s2);
void my_printf(const char *str, ...);
size_t tab_len(char **tab);
char *my_strcat(char *dest, char *src);
char **my_str_to_word_array(char *str, char *delimitors);
char *to_lowercase(char *str);
void my_swap(void **a, void **b);
char *my_strdup(char *str);
int my_getnbr(char *str);
bool my_str_isnum(char *str);
void free_tab(char **tab);
int get_character_index(char *str, char c);
char *my_strndup(char *str, int n);
bool str_contains(char *str, char c);

#endif /* !MY_H_ */
