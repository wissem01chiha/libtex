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
    char *image_path;
    char *caption;
    char *label;
    int   width;
    int   height;
    float scale;
    int   rotation;
    int   position;
    int   alignment;
  } tex_figure;

  TEX_EXTERN tex_figure *figure_create(tex_error_t *err);
  TEX_EXTERN tex_error_t figure_delete(tex_figure *fig);

  /**
   * Create the figure from a given file path
   * the figure label is automaticly genarted from filename
   * eg  fig:diagram_png
   */
  TEX_EXTERN tex_figure *figure_fs_create(const char *path, tex_error_t *err);

  /**
   * Adjust figure size
   */
  TEX_EXTERN tex_error_t figure_set_size(tex_figure *fig,
                                         int         width,
                                         int         height);
  /**
   * Adjsut figure scale
   */
  TEX_EXTERN tex_error_t figure_set_scale(tex_figure *fig, float scale);
  
  /**
   * Write figure to a memeory buffer 
   */
  TEX_EXTERN tex_error_t figure_write(const tex_figure *fig,
                                      char             *buffer,
                                      size_t            buffer_size);

#ifdef __cplusplus
};
#endif
