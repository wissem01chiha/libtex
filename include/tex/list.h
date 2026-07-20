// SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
// SPDX-License-Identifier: BSD-2-Clause

#pragma once

#include "texerrno.h"
#include "texexport.h"
#include "figure.h"

#ifdef __cplusplus
extern "C"
{
#endif

  /**
   * Latex list levels
   */
  typedef enum tex_list_t
  {
    Itemize     = 0,
    Enumerate   = 1,
    Description = 2
  } tex_list_t;

  typedef struct tex_list
  {
    tex_list_t type;
  } tex_list;

  TEX_EXTERN tex_list   *list_create(tex_error_t *err);
  TEX_EXTERN tex_error_t list_delete(tex_list *lst);

  TEX_EXTERN tex_error_t list_add_item(tex_list   *lst,
                                       const char *item,
                                       const char *label);

  TEX_EXTERN tex_error_t list_write(const tex_list *lst,
                                    char           *buffer,
                                    size_t          buffer_size);

#ifdef __cplusplus
};
#endif
