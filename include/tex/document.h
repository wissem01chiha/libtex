/*
 * SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include "texerrno.h"
#include "language.h"
#include "package.h"
#include "figure.h"
#include "section.h"

#ifdef __cplusplus
extern "C"
{
#endif

  typedef enum tex_document_t
  {
    Article = 0,
    Report  = 1,
    Book    = 2,
    Beamer  = 3
  } tex_document_t;

  typedef struct
  {
    tex_document_t type;
    tex_language_t language;
    tex_section   *section;
    tex_figure    *figure;
    char          *title;
    char          *author;
    char          *date;
    char          *content;
  } tex_document;

  tex_document *document_create(tex_error_t *err);
  tex_error_t   document_delete(tex_document *doc);

  tex_error_t document_set_class(tex_document *doc, tex_document_t doc_t);
  tex_error_t document_set_title(tex_document *doc, const char *title);

  // Set the document author, default is user name on target machine
  tex_error_t document_set_author(tex_document *doc, const char *author);

  // Set the document write date, defaul is today date
  tex_error_t document_set_date(tex_document *doc, const char *date);
  tex_error_t document_set_language(tex_document *doc, tex_language_t language);
  const char *document_get_class(tex_document_t doc_t);

  tex_error_t document_add_section(tex_document *doc, const tex_section *sec);

  // Adding explict content from memory, for adding content from filesystem
  // see  document_add_fs_content
  tex_error_t document_add_content(tex_document *doc, const char *content);

  // Append the contents of a file to the document body.
  tex_error_t document_add_fs_content(tex_document *doc, const char *filename);

  // Add a tex_figure to the document body.
  tex_error_t document_add_figure(tex_document *doc, tex_figure *fig);

  // Internal api call used by libtex to automatically append required latex packages
  // to a document when needed. This function is not intended for direct use by end users,
  // package declarations are managed internally and should not be handled manually.
  tex_error_t document_add_package(tex_document *doc, tex_package *package);

  // Write the document to a buffer in memory
  tex_error_t document_write(const tex_document *doc, char *buffer, size_t buffer_size);

  // Write the document to a file in the filesystem
  tex_error_t document_fs_write(const tex_document *doc, const char *file);

#ifdef __cplusplus
};
#endif
