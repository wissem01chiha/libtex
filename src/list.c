#include "tex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  return 0;
}

tex_error_t list_write(const tex_list *lst, char *buffer, size_t buffer_size)
{
  return 0;
}
