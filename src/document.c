#include "libtex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tex_document
{

  tex_document_t type;
  tex_language_t language;
  tex_section *sec;
  char *title;
  char *author;
  char *date;
  char *content;
};

tex_document *
document_create(tex_document_t type,
                const char *title,
                const char *author,
                const char *date,
                int language,
                int *err)   
{
    tex_document *doc = calloc(1, sizeof(tex_document));
    if (doc == NULL) {
        if (err) *err = LIBTEX_ENUPTR;
        return NULL;
    }

    doc->type = type;
    doc->language = (tex_language_t)language;

    doc->title  = title  ? strdup(title)  : NULL;
    doc->author = author ? strdup(author) : NULL;
    doc->date   = date   ? strdup(date)   : NULL;

    doc->content = NULL; 

    if (err) *err = LIBTEX_OK;
    return doc;
}

int
document_delete (tex_document *doc)
{
  if (doc == NULL)
    {
      return LIBTEX_OK;
    }
  free (doc->title);
  free (doc->author);
  free (doc->date);
  free (doc);
  return LIBTEX_OK;
}

int
document_set_title (tex_document *doc, const char *title)
{
  if (doc == NULL || title == NULL)
    {
      return LIBTEX_ENUPTR;
    }
  doc->title = strdup (title);
  return LIBTEX_OK;
}

int
document_set_author (tex_document *doc, const char *author)
{
  if (doc == NULL || author == NULL)
    {
      return LIBTEX_ENUPTR;
    }
  doc->author = strdup (author);
  return LIBTEX_OK;
}

int
document_set_date (tex_document *doc, const char *date)
{
      if (doc == NULL || date == NULL)
    {
      return LIBTEX_ENUPTR;
    }
    doc->date = strdup (date);
  return LIBTEX_OK;
}

int
document_set_language (tex_document *doc, tex_language_t language)
{
    return LIBTEX_OK;
}

int
document_add_content (tex_document *doc, const char *content)
{
  if (doc == NULL || content == NULL)
    {
      return LIBTEX_ENUPTR;
    }
  doc->content = strdup (content);
  return LIBTEX_OK;
}

int
document_write (const tex_document *doc, char *buffer, size_t buffer_size)
{
  if (doc == NULL)
    {
      return LIBTEX_ENUPTR;
    }

  if (buffer == NULL)
    {
      return LIBTEX_EINVAL;
    }
    int err=0;

    int written = snprintf(buffer, buffer_size,
        "\\documentclass{%s}\n"
        "\\begin{document}\n"
        "\\title{%s}\n"
        "\\author{%s}\n"
        "\\maketitle\n"
        "%s\n"
        "\\end{document}\n",
        getdocumentclass(doc->type),
        doc->title ? doc->title : "",
        doc->author ? doc->author : getusername(err),   
        doc->content ? doc->content : ""
    );

  if (written < 0 || (size_t)written >= buffer_size)
    {
      return LIBTEX_EOVERFLOW;
    }

  return LIBTEX_OK;
}

int
document_fs_write (const tex_document *doc, const char *filename)
{
  if (doc == NULL)
    {
      return LIBTEX_ENUPTR;
    }
  char buffer[2048];
  int bufferr = document_write (doc, buffer, sizeof (buffer));
  if (bufferr != LIBTEX_OK)
    {
      return bufferr;
    }

  FILE *fptr = fopen (filename, "w");
  if (fptr == NULL)
    {
      return LIBTEX_IOERR;
    }

  if (fputs (buffer, fptr) == EOF)
    {
      fclose (fptr);
      return LIBTEX_IOERR;
    }

  fclose (fptr);
  return LIBTEX_OK;
}
