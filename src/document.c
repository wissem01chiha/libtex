#include "tex.h"
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
document_create (tex_document_t type, const char *title, int *err)
{
  tex_document *doc = calloc (1, sizeof (tex_document));
  if (doc == NULL)
    {
      if (err)
        *err = TEX_ENUPTR;
      return NULL;
    }

  doc->type = type;
  doc->language = ENGLISH;

  doc->title = title ? strdup (title) : NULL;
  doc->author = strdup (getusername (err));
  doc->date = strdup (getdate (err));

  doc->content = NULL;

  if (err)
    *err = TEX_OK;
  return doc;
}

int
document_delete (tex_document *doc)
{
  if (doc == NULL)
    {
      return TEX_OK;
    }
  free (doc->title);
  free (doc->author);
  free (doc->date);
  free (doc);
  return TEX_OK;
}

int
document_set_title (tex_document *doc, const char *title)
{
  if (doc == NULL || title == NULL)
    {
      return TEX_ENUPTR;
    }
  doc->title = strdup (title);
  return TEX_OK;
}

int
document_set_author (tex_document *doc, const char *author)
{
  if (doc == NULL || author == NULL)
    {
      return TEX_ENUPTR;
    }
  doc->author = strdup (author);
  return TEX_OK;
}

int
document_set_date (tex_document *doc, const char *date)
{
  if (doc == NULL || date == NULL)
    {
      return TEX_ENUPTR;
    }
  doc->date = strdup (date);
  return TEX_OK;
}

int
document_set_language (tex_document *doc, tex_language_t language)
{
  if (doc == NULL)
    {
      return TEX_ENUPTR;
    }
  doc->language = language;
  return TEX_OK;
}

int
document_add_content (tex_document *doc, const char *content)
{
  if (doc == NULL || content == NULL)
    {
      return TEX_ENUPTR;
    }
  doc->content = strdup (content);
  return TEX_OK;
}

int
document_write (const tex_document *doc, char *buffer, size_t buffer_size)
{
  if (doc == NULL)
    {
      return TEX_ENUPTR;
    }

  if (buffer == NULL)
    {
      return TEX_EINVAL;
    }

  int written
      = snprintf (buffer, buffer_size,
                  "\\documentclass{%s}\n"
                  "\\begin{document}\n"
                  "\\title{%s}\n"
                  "\\author{%s}\n"
                  "\\date{%s}\n"
                  "\\maketitle\n"
                  "%s\n"
                  "\\end{document}\n",
                  document_get_class (doc->type), doc->title ? doc->title : "",
                  doc->author, doc->date, doc->content ? doc->content : "");

  if (written < 0 || (size_t)written >= buffer_size)
    {
      return TEX_EOVERFLOW;
    }

  return TEX_OK;
}

int
document_fs_write (const tex_document *doc, const char *filename)
{
  if (doc == NULL)
    {
      return TEX_ENUPTR;
    }
  char buffer[2048];
  int bufferr = document_write (doc, buffer, sizeof (buffer));
  if (bufferr != TEX_OK)
    {
      return bufferr;
    }

  FILE *fptr = fopen (filename, "w");
  if (fptr == NULL)
    {
      return TEX_IOERR;
    }

  if (fputs (buffer, fptr) == EOF)
    {
      fclose (fptr);
      return TEX_IOERR;
    }

  fclose (fptr);
  return TEX_OK;
}

const char *
document_get_class (tex_document_t doc_t)
{
  switch (doc_t)
    {
    case ARTICLE_DOC:
      return "article";
    case BOOK_DOC:
      return "book";
    case REPORT_DOC:
      return "report";
    case PRESENTATION_DOC:
      return "beamer";
    default:
      return "";
    }
}

const char *
document_get_language (tex_language_t lang_t)
{
  switch (lang_t)
    {
    case ENGLISH:
      return "english";
    case FRENCH:
      return "french";
    case GERMAN:
      return "ngerman";
    case SPANISH:
      return "spanish";
    case ITALIAN:
      return "italian";
    case PORTUGUESE:
      return "portuguese";
    case DUTCH:
      return "dutch";
    case RUSSIAN:
      return "russian";
    case CHINESE:
      return "chinese";
    case JAPANESE:
      return "japanese";
    case ARABIC:
      return "arabic";
    default:
      return "english";
    }
}