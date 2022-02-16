/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-malloc-lucas.sanchez
** File description:
** malloc
*/

#include "malloc.h"

void *memory = NULL;

size_t get_sbrk_allocation(size_t size)
{
  const size_t page_size = getpagesize();
  void *last_block = get_last_block();
  metadata_t *last_block_metadata = last_block
    ? to_metadata(last_block)
    : NULL;
  size_t available_space = last_block_metadata && last_block_metadata->free
    ? last_block_metadata->size
    : 0;
  size_t nb_pages = (size + sizeof(metadata_t) - available_space)
  / page_size + 1;

  if (nb_pages % 2 == 1)
    nb_pages += 1;
  return nb_pages * page_size;
}

void *memory_allocation(size_t size)
{
  size_t sbrk_allocation = get_sbrk_allocation(size);
  void *ptr = NULL;

  if (sbrk_allocation == 0)
    return NULL;
  ptr = sbrk(sbrk_allocation);
  if (ptr == (void *)-1)
    return NULL;
  return ptr;
}

void *allocate_more_memory(size_t size)
{
  void *last_block = get_last_block();
  metadata_t *last_block_metadata = to_metadata(last_block);
  void *new_block = last_block + sizeof(metadata_t) + last_block_metadata->size;
  size_t new_block_size = 0;

  if (!memory_allocation(size))
    return NULL;
  if (!last_block_metadata->free) {
    new_block_size = sbrk(0) - (new_block + sizeof(metadata_t));
    create_block(new_block, &new_block_size);
    split_block(new_block, size);
    return new_block + sizeof(metadata_t);
  }
  new_block_size = sbrk(0) - (last_block + sizeof(metadata_t));
  create_block(last_block, &new_block_size);
  to_metadata(last_block)->free = false;
  return last_block + sizeof(metadata_t);
}

void *malloc(size_t size)
{
  void *block = NULL;

  if (!memory)
    return init_malloc(size);
  block = get_best_fit_block(size);
  if (block) {
    split_block(block, size);
    return block + sizeof(metadata_t);
  }
  return allocate_more_memory(size);
}
