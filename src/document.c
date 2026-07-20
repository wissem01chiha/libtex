// SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
// SPDX-License-Identifier: BSD-2-Clause

#include "tex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tex_document *document_create(tex_error_t *err)
{
  tex_document *doc = calloc(1, sizeof(tex_document));
  if (doc == NULL)
  {
    if (err)
      *err = TEX_EFAIL_MEMALLOC;
    return NULL;
  }

  doc->type     = Article;
  doc->language = English;
  doc->title    = NULL;
  doc->author   = NULL;
  doc->date     = NULL;
  doc->content  = NULL;
  if (err)
    *err = TEX_ENONE;
  return doc;
}

tex_error_t document_delete(tex_document *doc)
{
  if (doc == NULL)
  {
    return TEX_ENULL_DOCUMENT;
  }
  free(doc->title);
  free(doc->author);
  free(doc->date);
  free(doc);
  return TEX_ENONE;
}

tex_error_t document_set_class(tex_document *doc, tex_document_t doc_t)
{
  if (doc == NULL)
  {
    return TEX_ENULL_DOCUMENT;
  }
  doc->type = doc_t;
  return TEX_ENONE;
}

tex_error_t document_set_title(tex_document *doc, const char *title)
{
  if (doc == NULL)
  {
    return TEX_ENULL_DOCUMENT;
  }
  doc->title = tex_strdup(title);
  return TEX_ENONE;
}

tex_error_t document_set_author(tex_document *doc, const char *author)
{
  if (doc == NULL || author == NULL)
  {
    return TEX_ENULL_DOCUMENT;
  }
  doc->author = tex_strdup(author);
  return TEX_ENONE;
}

tex_error_t document_set_date(tex_document *doc, const char *date)
{
  if (doc == NULL)
  {
    return TEX_ENULL_DOCUMENT;
  }
  if (date == NULL)
  {
    return TEX_EINVAL_INPUT;
  }
  doc->date = tex_strdup(date);
  return TEX_ENONE;
}

tex_error_t document_set_language(tex_document *doc, tex_language_t language)
{
  if (doc == NULL)
  {
    return TEX_ENULL_DOCUMENT;
  }
  doc->language = language;
  return TEX_ENONE;
}

tex_error_t document_add_content(tex_document *doc, const char *content)
{
  if (doc == NULL)
  {
    return TEX_ENULL_DOCUMENT;
  }
  if (content == NULL)
  {
    return TEX_EINVAL_INPUT;
  }
  if (doc->content == NULL)
  {
    doc->content = tex_strdup(content);
  }
  else
  {
    size_t len  = strlen(doc->content);
    size_t nlen = strlen(content);
    char  *buff = malloc(len + nlen + 1);
    if (buff == NULL)
    {
      return TEX_EFAIL_MEMALLOC;
    }
    memcpy(buff, doc->content, len);
    memcpy(buff + len, content, nlen);
    buff[len + nlen] = '\0';

    free(doc->content);
    doc->content = buff;
  }

  return TEX_ENONE;
}

tex_error_t document_add_fs_content(tex_document *doc, const char *filename)
{
  if (doc == NULL)
  {
    return TEX_ENULL_DOCUMENT;
  }
  if (filename == NULL)
  {
    return TEX_EINVAL_INPUT;
  }
  FILE *f = fopen(filename, "rb");
  if (f == NULL)
  {
    return TEX_EFAIL_FOPEN;
  }
  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  fseek(f, 0, SEEK_SET);
  char *buffer = malloc(fsize + 1);
  if (buffer == NULL)
  {
    return TEX_EFAIL_MEMALLOC;
  }
  size_t read  = fread(buffer, 1, fsize, f);
  buffer[read] = '\0';
  fclose(f);
  tex_error_t err = document_add_content(doc, buffer);
  if (err != TEX_ENONE)
  {
    return err;
  }
  free(buffer);
  return TEX_ENONE;
}

tex_error_t document_add_figure(tex_document *doc, tex_figure *fig)
{
  if (doc)
  {
    return TEX_ENULL_DOCUMENT;
  }
  if (fig)
  {
    return TEX_ENULL_FIGURE;
  }

  return TEX_ENONE;
}

tex_error_t document_add_section(tex_document *doc, const tex_section *sec)
{
  if (doc == NULL)
  {
    return TEX_ENULL_DOCUMENT;
  }
  if (sec == NULL)
  {
    return TEX_ENULL_SECTION;
  }
  return TEX_ENONE;
}

tex_section *document_find_section(tex_document *doc, const char *sectitle)
{
  if (doc)
  {
    return NULL;
  }
  if (sectitle)
  {
    return NULL;
  }
  return NULL;
}

tex_error_t
document_write(const tex_document *doc, char *buffer, size_t buffer_size)
{
  if (doc == NULL)
  {
    return TEX_ENULL_DOCUMENT;
  }
  if (buffer == NULL)
  {
    return TEX_ENULL_BUFFER;
  }

  tex_error_t err = TEX_ENONE;

  const char *title   = doc->title ? doc->title : "";
  const char *author  = doc->author ? doc->author : tex_get_username(&err);
  const char *date    = doc->date ? doc->date : tex_get_date(&err);
  const char *content = doc->content ? doc->content : "";

  if (err != TEX_ENONE)
  {
    return err;
  }

  int written = snprintf(buffer,
                         buffer_size,
                         "\\documentclass{%s}\n"
                         "\\begin{document}\n"
                         "\\title{%s}\n"
                         "\\author{%s}\n"
                         "\\date{%s}\n"
                         "\\maketitle\n"
                         "%s\n"
                         "\\end{document}\n",
                         document_get_class(doc->type),
                         title,
                         author,
                         date,
                         content);

  if (written < 0 || (size_t) written >= buffer_size)
  {
    return TEX_EOVERFLOW_BUFFER;
  }

  return TEX_ENONE;
}

tex_error_t document_fs_write(const tex_document *doc, const char *filename)
{
  if (doc == NULL)
  {
    return TEX_ENULL_DOCUMENT;
  }
  char        buffer[2048];
  tex_error_t bufferr = document_write(doc, buffer, sizeof(buffer));
  if (bufferr != TEX_ENONE)
  {
    return bufferr;
  }

  FILE *fptr = fopen(filename, "w");
  if (fptr == NULL)
  {
    return TEX_EFAIL_FOPEN;
  }

  if (fputs(buffer, fptr) == EOF)
  {
    fclose(fptr);
    return TEX_EFAIL_FOPEN;
  }

  fclose(fptr);
  return TEX_ENONE;
}

tex_error_t document_add_package(tex_document *doc, tex_package *package)
{
  if (doc)
  {
    return TEX_ENULL_DOCUMENT;
  }
  if (package)
  {
    return TEX_ENULL_PACKAGE;
  }
  return TEX_ENONE;
}

const char *document_get_class(tex_document_t doc_t)
{
  switch (doc_t)
  {
    case Article:
      return "article";
    case Book:
      return "book";
    case Report:
      return "report";
    case Beamer:
      return "beamer";
    default:
      return "";
  }
}
