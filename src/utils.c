/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-malloc-lucas.sanchez
** File description:
** utils
*/

#include "malloc.h"

metadata_t *get_metadata_from_ptr(void *ptr)
{
  return (metadata_t *)(ptr - sizeof(metadata_t));
}

metadata_t *to_metadata(void *block)
{
  return (metadata_t *)(block);
}

// Returns NULL if cannot fit size into the actual memory
// Returns a pointer to the best fit memory block
void *get_best_fit_block(size_t size)
{
  void *best_fit = NULL;
  size_t best_fit_size = 0xFFFFFFFFFFFFFFFF;
  metadata_t *meta = NULL;
  size_t memory_end = (size_t)sbrk(0) - (sizeof(metadata_t) + 1);

  if (!memory)
    return NULL;
  for (size_t i = 0; (size_t)memory + i < memory_end;
  i += to_metadata(memory + i)->size + sizeof(metadata_t)) {
    meta = to_metadata(memory + i);
    if (meta->free && meta->size >= size && meta->size < best_fit_size) {
      best_fit = memory + i;
      best_fit_size = meta->size;
    }
  }
  return best_fit;
}

void *get_last_block(void)
{
  size_t memory_end = (size_t)sbrk(0) - (sizeof(metadata_t) + 1);
  void *last_block = NULL;

  if (!memory)
    return NULL;
  for (size_t i = 0; (size_t)memory + i < memory_end;
  i += to_metadata(memory + i)->size + sizeof(metadata_t))
    last_block = memory + i;
  return last_block;
}

void *get_next_block(void *block)
{
  metadata_t *meta = to_metadata(block);
  size_t next_block_size = meta->size + sizeof(metadata_t);

  if (block + next_block_size >= (void *)sbrk(0) - (sizeof(metadata_t) + 1))
    return NULL;
  return block + next_block_size;
}
