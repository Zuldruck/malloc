/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-lucas.sanchez
** File description:
** minishell1
*/

#ifndef MALLOC_H_
  #define MALLOC_H_

  #include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h>
  #include <sys/types.h>
  #include <sys/wait.h>
  #include <sys/stat.h>
  #include <fcntl.h>
  #include <signal.h>
  #include <string.h>
  #include "../lib/my/include/my.h"

  #define UNUSED __attribute__((unused))

typedef struct metadata_s {
  size_t size;
  bool free;
} metadata_t;

extern char *memory;

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

#endif /* !MALLOC_H_ */
