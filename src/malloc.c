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

  if (size == 0)
    return 0;
  if (nb_pages % 2 == 1)
    nb_pages += 1;
  return nb_pages * page_size;
}

void *memory_allocation(size_t size)
{
  // my_printf("Allocating memory...\n");
  size_t sbrk_allocation = get_sbrk_allocation(size);
  // my_printf("Allocating %d bytes\n", sbrk_allocation);
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
  // my_printf("Allocating more memory...\n");
  // my_printf("last_block %u\n", last_block);
  // my_printf("last_block_metadata->size %u\n", last_block_metadata->size);
  void *new_block = last_block + sizeof(metadata_t) + last_block_metadata->size;
  size_t new_block_size = 0;

  // my_printf("break %u\n", sbrk(0));
  if (!memory_allocation(size))
    return NULL;
  // my_printf("break %u\n", sbrk(0));
  // my_printf("Allocated more memory\n");
  if (!last_block_metadata->free) {
    // my_printf("Last block is not free\n");
    new_block_size = sbrk(0) - (new_block + sizeof(metadata_t));
    create_block(new_block, &new_block_size);
    // my_printf("Created new block\n");
    split_block(new_block, size);
    // my_printf("Split new block\n");
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

  // my_printf("malloc(%d)\n", size);
  if (size == 0)
    return NULL;
  if (!memory)
    return init_malloc(size);
  // my_printf("Searching for a block\n");
  block = get_best_fit_block(size);
  // my_printf("Found a block\n");
  if (block) {
    // my_printf("Splitting block\n");
    split_block(block, size);
    // my_printf("Block splitted\n");
    // my_printf("Returning block:\n%u\nBreak:\n%u\n", block + sizeof(metadata_t), sbrk(0));
    return block + sizeof(metadata_t);
  }
  return allocate_more_memory(size);
}
