/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-malloc-lucas.sanchez
** File description:
** realloc
*/

#include "malloc.h"

void *merge_and_split_with_new_size(void *block1, void *block2, size_t size)
{
  metadata_t *meta1 = NULL;
  metadata_t *meta2 = NULL;

  if (!block1 || !block2)
    return NULL;
  meta1 = to_metadata(block1);
  meta2 = to_metadata(block2);
  meta1->size = meta1->size + meta2->size + sizeof(metadata_t);
  split_block(block1, size);
  return block1 + sizeof(metadata_t);
}

void *realloc(void *ptr, size_t size)
{
  void *new_ptr = NULL;
  void *next_block = NULL;
  metadata_t *meta = NULL;

  if (!ptr)
    return malloc(size);
  meta = get_metadata_from_ptr(ptr);
  next_block = get_next_block(meta);
  if (meta->size >= size)
    return ptr;
  else if (next_block && to_metadata(next_block)->free)
    return merge_and_split_with_new_size(meta, next_block, size);
  new_ptr = malloc(size);
  if (!new_ptr)
    return NULL;
  memcpy(new_ptr, ptr, size);
  free(ptr);
  return new_ptr;
}
