#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tex.h"

tex_document* document_create(tex_document_t type, const char* title,
                              tex_error_t* err) {
  tex_document* doc = calloc(1, sizeof(tex_document));
  if (doc == NULL) {
    if (err)
      *err = TEX_ERROR_MEMALLOC_FAILED;
    return NULL;
  }

  doc->type = type;
  doc->language = ENGLISH;

  doc->title = title ? strdup(title) : NULL;
  doc->author = strdup(tex_get_username(err));
  doc->date = strdup(tex_get_date(err));

  doc->content = NULL;

  if (err)
    *err = TEX_ERROR_NONE;
  return doc;
}

tex_error_t document_delete(tex_document* doc) {
  if (doc == NULL) {
    return TEX_ERROR_INVALID_DOCUMENT;
  }
  free(doc->title);
  free(doc->author);
  free(doc->date);
  free(doc);
  return TEX_ERROR_NONE;
}

tex_error_t document_set_title(tex_document* doc, const char* title) {
  if (doc == NULL || title == NULL) {
    return TEX_ERROR_INVALID_DOCUMENT;
  }
  doc->title = strdup(title);
  return TEX_ERROR_NONE;
}

tex_error_t document_set_author(tex_document* doc, const char* author) {
  if (doc == NULL || author == NULL) {
    return TEX_ERROR_INVALID_DOCUMENT;
  }
  doc->author = strdup(author);
  return TEX_ERROR_NONE;
}

tex_error_t document_set_date(tex_document* doc, const char* date) {
  if (doc == NULL || date == NULL) {
    return TEX_ERROR_INVALID_DOCUMENT;
  }

  doc->date = strdup(date);
  return TEX_ERROR_NONE;
}

tex_error_t document_set_language(tex_document* doc, tex_language_t language) {
  if (doc == NULL) {
   return TEX_ERROR_INVALID_DOCUMENT;
  }
  doc->language = language;
  return TEX_ERROR_NONE;
}

tex_error_t document_add_content(tex_document* doc, const char* content) {
  if (doc == NULL || content == NULL) {
    return TEX_ERROR_INVALID_DOCUMENT;
  }
  doc->content = strdup(content);
  return TEX_ERROR_NONE;
}

tex_error_t document_add_section(tex_document* doc, const tex_section* sec) {
  if (doc == NULL) {
    return TEX_ERROR_INVALID_DOCUMENT;
  }
  if(sec==NULL){
    return TEX_ERROR_INVALID_SECTION;
  }
  return TEX_ERROR_NONE;
}

tex_error_t document_write(const tex_document* doc, char* buffer, size_t buffer_size) {
  if (doc == NULL) {
    return TEX_ERROR_INVALID_DOCUMENT;
  }

  if (buffer == NULL) {
    return TEX_ERROR_INVALID_BUFFER;
  }

  int written =
      snprintf(buffer, buffer_size,
               "\\documentclass{%s}\n"
               "\\begin{document}\n"
               "\\title{%s}\n"
               "\\author{%s}\n"
               "\\date{%s}\n"
               "\\maketitle\n"
               "%s\n"
               "\\end{document}\n",
               document_get_class(doc->type), doc->title ? doc->title : "",
               doc->author, doc->date, doc->content ? doc->content : "");

  if (written < 0 || (size_t)written >= buffer_size) {
    return TEX_ERROR_BUFFER_OVERFLOW;
  }

  return TEX_ERROR_NONE;
}

tex_error_t document_fs_write(const tex_document* doc, const char* filename) {
  if (doc == NULL) {
   return TEX_ERROR_INVALID_DOCUMENT;
  }
  char buffer[2048];
  tex_error_t bufferr = document_write(doc, buffer, sizeof(buffer));
  if (bufferr != TEX_ERROR_NONE) {
    return bufferr;
  }

  FILE* fptr = fopen(filename, "w");
  if (fptr == NULL) {
    return TEX_IOERR;
  }

  if (fputs(buffer, fptr) == EOF) {
    fclose(fptr);
    return TEX_IOERR;
  }

  fclose(fptr);
  return TEX_ERROR_NONE;
}

tex_error_t document_add_package(tex_document* doc, const char* package,
                         const char* options) {
  return TEX_ERROR_NONE;
}

const char* document_get_class(tex_document_t doc_t) {
  switch (doc_t) {
    case TEXDOC_ARTICLE:
      return "article";
    case TEXDOC_BOOK:
      return "book";
    case TEXDOC_REPORT:
      return "report";
    case TEXDOC_PRESENTATION:
      return "beamer";
    default:
      return "";
  }
}
