/*
 * SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include "texerrno.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

  typedef struct
  {
    char *image_path;
    char *caption;
    char *label;
    char *width;
    char *position;
  } tex_figure;

  tex_figure *figure_create(tex_error_t *err);
  tex_error_t figure_delete(tex_figure *fig);

  tex_error_t figure_set_caption(tex_figure *fig, const char *caption);
  tex_error_t figure_set_label(tex_figure *fig, const char *label);
  tex_error_t figure_set_width(tex_figure *fig, const char *width);

  tex_error_t figure_write(const tex_figure *fig, char *buffer, size_t buffer_size);

#ifdef __cplusplus
}; /* extern "C" { */
#endif
