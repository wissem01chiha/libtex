// SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
// SPDX-License-Identifier: BSD-2-Clause

#include "tex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tex_section *section_create(tex_error_t *err)
{
  tex_section *sec = calloc(1, sizeof(tex_section));
  if (sec == NULL)
  {
    *err = TEX_EFAIL_MEMALLOC;
    return NULL;
  }
  sec->title   = NULL;
  sec->level   = Section;
  sec->content = NULL;
  err          = TEX_ENONE;
  return sec;
}

tex_error_t section_delete(tex_section *sec)
{
  if (sec == NULL)
  {
    return TEX_ENULL_SECTION;
  }
  free(sec->title);
  free(sec->content);
  free(sec);
  return TEX_ENONE;
}

tex_section *section_find_subsection(tex_section *sec, const char *sectitle)
{
  if (sec == NULL)
  {
    return NULL;
  }
  if (sectitle == NULL)
  {
    return NULL;
  }
  return NULL;
}

tex_error_t section_add_content(tex_section *sec, const char *_content)
{
  if (sec==NULL)
  {
    return TEX_ENULL_SECTION;
  }
  if (_content == NULL)
  {
    return TEX_EINVAL_INPUT;
  }
  if (sec->content==NULL)
  {
    sec->content = tex_strdup(_content);
  }
  else
  {
    size_t len  = strlen(sec->content);
    size_t nlen = strlen(_content);
    char  *buff = malloc(len + nlen + 1);
    if (buff == NULL)
    {
      return TEX_EFAIL_MEMALLOC;
    }
    memcpy(buff, sec->content, len);
    memcpy(buff + len, _content, nlen);
    buff[len + nlen] = '\0';

    free(sec->content);
    sec->content = buff;
  }

  return TEX_ENONE;
}

tex_error_t section_add_fs_content(tex_section *sec, const char *filename)
{
  if (sec==NULL)
  {
    return TEX_ENULL_SECTION;
  }
  if (filename==NULL)
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
