// SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
// SPDX-License-Identifier: BSD-2-Clause

#include "tex.h"
#include <stdio.h>
#include <stdlib.h>

tex_list *list_create(tex_error_t *err)
{
  *err           = 0;
  tex_list *list = malloc(sizeof(tex_list));
  if (list == NULL)
  {
    *err = TEX_EFAIL_MEMALLOC;
    return NULL;
  }
  return list;
}

tex_error_t list_delete(tex_list *lst)
{
  if (lst == NULL)
  {
    return TEX_ENULL_LIST;
  }
  free(lst);
  return TEX_ENONE;
}

tex_error_t list_add_item(tex_list *lst, const char *item, const char *label)
{
  if (lst == NULL)
  {
    return TEX_ENULL_LIST;
  }
  if (item == NULL)
  {
    return TEX_EINVAL_INPUT;
  }
  if (label == NULL)
  {
    return TEX_EINVAL_INPUT;
  }
  return 0;
}

tex_error_t list_write(const tex_list *lst, char *buffer, size_t buffer_size)
{
  if (lst == NULL)
  {
    return TEX_ENULL_LIST;
  }
  if (buffer == NULL)
  {
    return TEX_ENULL_BUFFER;
  }
  return 0;
}
