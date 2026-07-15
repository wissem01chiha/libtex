/** Copyright (c) 2026, wissem chiha

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

  1. Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.

  2. Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.
*/

#include "tex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tex_figure *figure_create(const char *image_path, const char *position)
{
  tex_figure *fig = calloc(1, sizeof(tex_figure));
  if (fig == NULL)
  {
    return NULL;
  }
  fig->image_path = strdup(image_path);
  fig->position   = strdup(position);
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
  return TEX_ERROR_NONE;
}

tex_error_t figure_set_caption(tex_figure *fig, const char *caption)
{
  if (fig == NULL || caption == NULL)
  {
    return TEX_ERROR_INVALID_FIGURE;
  }
  fig->caption = strdup(caption);
  return TEX_ERROR_NONE;
}

tex_error_t figure_set_label(tex_figure *fig, const char *label)
{
  if (fig == NULL)
  {
    return TEX_ERROR_INVALID_FIGURE;
  }
  fig->label = label;
  return TEX_ERROR_NONE;
}

tex_error_t figure_set_width(tex_figure *fig, const char *width)
{
  if (fig == NULL)
  {
    return TEX_ERROR_INVALID_FIGURE;
  }
  return TEX_ERROR_NONE;
}

tex_error_t figure_write(const tex_figure *fig, char *buffer, size_t buffer_size)
{
  if (fig == NULL)
  {
    return -1;
  }
  return TEX_ERROR_NONE;
}
