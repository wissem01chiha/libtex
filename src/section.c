/***************************************************************************
 * SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 ***************************************************************************/

#include "tex.h"
#include <stdio.h>
#include <stdlib.h>

tex_section *section_create(const char *title, tex_section_t level, int err)
{
  tex_section *sec = calloc(1, sizeof(tex_section));
  if (sec == NULL)
  {
    err = TEX_EFAIL_MEMALLOC;
    return NULL;
  }
  sec->title = tex_strdup(title);
  sec->level = level;
  err        = TEX_ENONE;
  return sec;
}

tex_error_t section_delete(tex_section *sec)
{
  if (sec == NULL)
  {
    return TEX_EINVAL_INPUT;
  }
  free(sec->title);
  free(sec->content);
  free(sec);
  return TEX_ENONE;
}

tex_section *section_find_subsection(tex_section *sec, const char *sectitle)
{
  return NULL;
}

tex_error_t section_add_content(tex_section *sec, const char *_content)
{
  if (sec == NULL || _content == NULL)
  {
    return TEX_EINVAL_INPUT;
  }
  sec->content = tex_strdup(_content);
  return TEX_ENONE;
}

tex_error_t section_add_fs_content(tex_section *sec, const char *filename)
{
  if (sec)
  {
    return TEX_ENULL_SECTION;
  }
  if (filename)
  {
    return TEX_EINVAL_INPUT;
  }
  return TEX_ENONE;
}

tex_error_t
section_write(const tex_section *sec, char *buffer, size_t buffer_size)
{
  if (sec == NULL || buffer == NULL)
  {
    return TEX_EINVAL_INPUT;
  }
  if (sec->level == Chapter)
  {
    snprintf(buffer, buffer_size, "\\chapter{%s}\n", sec->title);
  }
  else if (sec->level == Section)
  {
    snprintf(buffer, buffer_size, "\\section{%s}\n", sec->title);
  }
  else if (sec->level == Subsection)
  {
    snprintf(buffer, buffer_size, "\\subsection{%s}\n", sec->title);
  }
  else if (sec->level == Subsubsection)
  {
    snprintf(buffer, buffer_size, "\\subsubsection{%s}\n", sec->title);
  }
  return TEX_ENONE;
}
