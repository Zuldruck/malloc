/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-malloc-lucas.sanchez
** File description:
** init
*/

#include "malloc.h"

void init_blocks(size_t size)
{
  size_t rest_size = 0;
  void *break_ptr = sbrk(0);
  size_t metadata_size = sizeof(metadata_t);

  if ((size_t)break_ptr
  - ((size_t)memory + metadata_size + size) < metadata_size + 1) {
    size = (size_t)break_ptr - ((size_t)memory + metadata_size);
    create_block(memory, &size);
  } else {
    create_block(memory, &size);
    rest_size = (size_t)break_ptr -
    ((size_t)memory + metadata_size + size + metadata_size);
    create_block(memory + metadata_size + size, &rest_size);
  }
}

void *init_malloc(size_t size)
{
  size_t metadata_size = sizeof(metadata_t);

  memory = memory_allocation(size);
  if (!memory)
    return NULL;
  if (((size_t)memory + metadata_size) % 2 == 1)
    memory += 1;
  init_blocks(size);
  to_metadata(memory)->free = false;
  return memory + metadata_size;
}
