// SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
// SPDX-License-Identifier: BSD-2-Clause

#pragma once

#include "texerrno.h"
#include "texexport.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

  typedef struct
  {
    size_t size;
    size_t capacity;
    char  *content;
  } tex_table_row;

  typedef struct
  {
    char          *label;
    char          *caption;
    tex_table_row *row;
  } tex_table;

  TEX_EXTERN tex_table_row *tex_table_row_create(size_t size, tex_error_t *err);

  TEX_EXTERN tex_table *table_create(const char *title, tex_error_t *err);

  TEX_EXTERN tex_error_t table_delete(tex_table *tab);

  TEX_EXTERN tex_error_t table_set_caption(tex_table *tab, const char *caption);
  TEX_EXTERN tex_error_t table_set_label(tex_table *tab, const char *label);

  TEX_EXTERN tex_error_t table_add_row(tex_table *tab, tex_table_row *rw);

  TEX_EXTERN int table_write(const tex_table *tab,
                             char            *buffer,
                             size_t           buffer_size,
                             tex_error_t     *err);

#ifdef __cplusplus
};
#endif
