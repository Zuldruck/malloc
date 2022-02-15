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

typedef struct __attribute__((__packed__)) metadata_s {
  size_t size;
  bool free;
} metadata_t;

extern void *memory;

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

void *get_best_fit_block(size_t size);
metadata_t *get_metadata_from_ptr(void *ptr);
metadata_t *to_metadata(void *block);
void *memory_allocation(size_t size);
void *init_malloc(size_t size);
void *get_last_block(void);
void create_block(void *block, size_t *size);
void split_block(void *block, size_t size);

#endif /* !MALLOC_H_ */
