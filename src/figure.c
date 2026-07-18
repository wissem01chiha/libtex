/*
 * SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "tex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tex_figure *figure_create(int *err)
{
  tex_figure *fig = calloc(1, sizeof(tex_figure));
  if (fig == NULL)
  {
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
  free(fig->position);
  free(fig);
  return TEX_ENONE;
}

tex_error_t figure_set_caption(tex_figure *fig, const char *caption)
{
  if (fig == NULL || caption == NULL)
  {
    return TEX_ENULL_FIGURE;
  }
  fig->caption = strdup(caption);
  return TEX_ENONE;
}

tex_error_t figure_set_label(tex_figure *fig, const char *label)
{
  if (fig == NULL)
  {
    return TEX_ENULL_FIGURE;
  }
  fig->label = strdup(label);
  return TEX_ENONE;
}

tex_error_t figure_set_width(tex_figure *fig, const char *width)
{
  if (fig == NULL)
  {
    return TEX_ENULL_FIGURE;
  }
  return TEX_ENONE;
}

tex_error_t figure_write(const tex_figure *fig, char *buffer, size_t buffer_size)
{
  if (fig == NULL)
  {
    return -1;
  }
  return TEX_ENONE;
}
