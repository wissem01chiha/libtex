// SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
// SPDX-License-Identifier: BSD-2-Clause

#include "tex.h"
#include <stdio.h>
#include <stdlib.h>

tex_element *element_create(tex_error_t *err)
{
  tex_element *el = malloc(sizeof(tex_element));
    if (!el) { *err= TEX_EFAIL_MEMALLOC;
        return NULL;
    }
    el->next = NULL;
    el->data =NULL;
    return el;
}

TEX_EXTERN tex_error_t element_delete(tex_element *ele)
{
   if (ele == NULL)
  {
    return TEX_ENULL_ELEMENT;
  }
 free(ele->data);
  free(ele->next);
  free(ele);
return TEX_ENONE;
}


element_writer  element_write[] = {
    [TEX_ELE_FIGURE]  = (element_writer)figure_write,
    [TEX_ELE_LIST]    = (element_writer)list_write,
    [TEX_ELE_TABLE]   = (element_writer)table_write,
    [TEX_ELE_CONTENT] = (element_writer)content_write
};