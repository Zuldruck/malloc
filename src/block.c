/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-malloc-lucas.sanchez
** File description:
** block
*/

#include "malloc.h"

void create_block(void *block, size_t *size)
{
  // my_printf("Creating block with size %u\n", *size);
  metadata_t *meta = to_metadata(block);

  if (((size_t)block + sizeof(metadata_t)
  + *size + sizeof(metadata_t)) % 2 == 1)
    *size += 1;
  if ((size_t)block + sizeof(metadata_t) + *size > (size_t)sbrk(0))
    *size -= 2;
  // my_printf("Block ckecks done\n");
  meta->size = *size;
  meta->free = true;
}

void split_block(void *block, size_t size)
{
  metadata_t *meta = to_metadata(block);
  void *next_block = block + sizeof(metadata_t) + meta->size;
  void *new_block = block + sizeof(metadata_t) + size;
  size_t new_block_size = 0;

  // my_printf("Splitting block with size %u\n", size);
  if (((size_t)new_block + sizeof(metadata_t)) % 2 == 1) {
    size += 1;
    new_block += 1;
  }
  meta->size = size;
  meta->free = false;
  if ((size_t)next_block - (size_t)new_block < sizeof(metadata_t) + 1) {
    meta->size = meta->size + (size_t)next_block - (size_t)new_block;
    return;
  }
  new_block_size = (size_t)next_block - (size_t)new_block - sizeof(metadata_t);
  // my_printf("Splitted with %u / %u\n", size, new_block_size);
  create_block(new_block, &new_block_size);
}
