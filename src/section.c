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
  sec->next    = NULL;
  err          = TEX_ENONE;
  return sec;
}

tex_error_t section_delete(tex_section *sec)
{
  if (sec == NULL)
  {
    return TEX_ENULL_SECTION;
  }
  if (sec->title != NULL)
  {
    free(sec->title);
  }
  if (sec->content != NULL)
  {
    free(sec->content);
  }
  if (sec->figure != NULL)
  {
    free(sec->figure);
  }
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
  if (sec == NULL)
  {
    return TEX_ENULL_SECTION;
  }
  if (_content == NULL)
  {
    return TEX_EINVAL_INPUT;
  }
  if (sec->content == NULL)
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
  if (sec == NULL)
  {
    return TEX_ENULL_SECTION;
  }
  if (filename == NULL)
  {
    return TEX_EINVAL_INPUT;
  }
  return TEX_ENONE;
}

int section_write(const tex_section *sec,
                  char              *buffer,
                  size_t             buffer_size,
                  tex_error_t       *err)
{
  if (buffer == NULL)
  {
    *err = TEX_EINVAL_INPUT;
  }
  if (sec == NULL)
  {
    *err = TEX_ENULL_SECTION;
  }

  size_t written = 0;
  int    n       = 0;

  // write section header
  const char *fmt = NULL;
  switch (sec->level)
  {
    case Chapter:
      fmt = "\\chapter{%s}\n";
      break;
    case Section:
      fmt = "\\section{%s}\n";
      break;
    case Subsection:
      fmt = "\\subsection{%s}\n";
      break;
    case Subsubsection:
      fmt = "\\subsubsection{%s}\n";
      break;
    default:
      fmt = "\\section*{%s}\n";
      break;
  }

  n = snprintf(buffer + written, buffer_size - written, fmt, sec->title);

  if (n < 0 || (size_t) n >= buffer_size - written)
  {
    *err = TEX_EOVERFLOW_BUFFER;
  }
  written += n;

  // write content if available
  if (sec->content != NULL)
  {
    n = snprintf(buffer + written, buffer_size - written, "%s\n", sec->content);
    if (n < 0 || (size_t) n >= buffer_size - written)
      *err = TEX_EOVERFLOW_BUFFER;
    written += n;
  }

  // handle substections
  if (sec->subsection != NULL)
  {
    int written_subs = section_write(
        sec->subsection, buffer + written, buffer_size - written, err);
    written += written_subs;
  }

  // sibling sections
  if (sec->next != NULL)
  {
    int written_next =
        section_write(sec->next, buffer + written, buffer_size - written, err);
    written += written_next;
  }
  return written;
}
