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
    *err = TEX_ENULL_FIGURE;
    return NULL;
  }
  fig->image_path = '\0';
  fig->position   = '\0';
  return fig;
}

tex_error_t figure_delete(tex_figure *fig)
{
  if (fig == NULL)
  {
    return 0;
  }
  free(fig->image_path);
  free(fig);
  return TEX_ENONE;
}
tex_figure *figure_fs_create(const char *path, tex_error_t *err)
{
  return NULL;
}

tex_error_t figure_set_size(tex_figure *fig, int width, int height)
{
  return TEX_ENONE;
}

tex_error_t figure_set_scale(tex_figure *fig, float scale)
{
  return TEX_ENONE;
}

tex_error_t
figure_write(const tex_figure *fig, char *buffer, size_t buffer_size)
{
  if (fig == NULL)
  {
    return -1;
  }
  return TEX_ENONE;
}
