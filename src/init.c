/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-malloc-lucas.sanchez
** File description:
** init
*/

#include "malloc.h"

void *init_malloc(size_t size)
{
  void *break_ptr = NULL;
  size_t metadata_size = sizeof(metadata_t);
  size_t rest_size = 0;

  // my_printf("Initializing malloc...\n");
  memory = memory_allocation(size);
  // my_printf("Memory allocated\n");
  if (!memory)
    return NULL;
  if (((size_t)memory + metadata_size) % 2 == 1)
    memory += 1;
  break_ptr = sbrk(0);
  // my_printf("Before creating blocks\n");
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
  // my_printf("After creating blocks\n");
  to_metadata(memory)->free = false;
  // my_printf("Returning ptr %u\n", memory + metadata_size);
  return memory + metadata_size;
}
