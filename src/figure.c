// SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
// SPDX-License-Identifier: BSD-2-Clause

#include "tex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tex_figure *figure_create(tex_error_t *err)
{
  tex_figure *fig = calloc(1, sizeof(tex_figure));
  if (fig == NULL)
  {
    *err = TEX_EFAIL_MEMALLOC;
    return NULL;
  }
  fig->image_path = NULL;
  fig->position   = 0;
  fig->next       = NULL;
  return fig;
}

tex_error_t figure_delete(tex_figure *fig)
{
  if (fig == NULL)
  {
    return TEX_ENONE;
  }
  if (fig->image_path != NULL)
  {
    free(fig->image_path);
  }
  free(fig);
  return TEX_ENONE;
}

tex_figure *figure_fs_create(const char *path, tex_error_t *err)
{
  return NULL;
}

tex_error_t figure_set_size(tex_figure *fig, int width, int height)
{
  if (fig == NULL)
  {
    return TEX_ENULL_FIGURE;
  }
  if (width <= 0)
  {
    return TEX_EINVAL_FIGURE_WIDTH;
  }
  if (height <= 0)
  {
    return TEX_EINVAL_FIGURE_HEIGHT;
  }
  fig->width  = width;
  fig->height = height;
  return TEX_ENONE;
}

tex_error_t figure_set_scale(tex_figure *fig, float scale)
{
  return TEX_ENONE;
}

int figure_write(const tex_figure *fig,
                 char             *buffer,
                 size_t            buffer_size,
                 tex_error_t      *err)
{
  if (fig == NULL)
  {
    *err = TEX_ENULL_FIGURE;
    return -1;
  }
  int written = 0;
  return written;
}
