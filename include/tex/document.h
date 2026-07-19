/***************************************************************************
 * SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 ***************************************************************************/

#pragma once

#include "texerrno.h"
#include "language.h"
#include "package.h"
#include "figure.h"
#include "texexport.h"
#include "section.h"

#ifdef __cplusplus
extern "C"
{
#endif

  /**
   * Supported latex documents types
   */
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

  TEX_EXTERN tex_document *document_create(tex_error_t *err);
  TEX_EXTERN tex_error_t   document_delete(tex_document *doc);

  /**
   * By default the document is set to Article type, however it can be changed
   * using this routine.
   */
  TEX_EXTERN tex_error_t document_set_class(tex_document  *doc,
                                            tex_document_t doc_t);

  /**
   * Set the document title.
   */
  TEX_EXTERN tex_error_t document_set_title(tex_document *doc,
                                            const char   *title);

  /**
   * Set the document author, default is the user name on the target machine.
   */
  TEX_EXTERN tex_error_t document_set_author(tex_document *doc,
                                             const char   *author);

  /**
   * Set the document write date, default is today's date.
   * No special formatting is handled.
   */
  TEX_EXTERN tex_error_t document_set_date(tex_document *doc, const char *date);

  /**
   * Set the document language, default is English.
   */
  TEX_EXTERN tex_error_t document_set_language(tex_document  *doc,
                                               tex_language_t language);

  /**
   * Convert document enumeration class to string representation.
   */
  TEX_EXTERN const char *document_get_class(tex_document_t doc_t);

  /**
   * Add a section to the document.
   */
  TEX_EXTERN tex_error_t document_add_section(tex_document      *doc,
                                              const tex_section *sec);

  /**
   * Find a given section in the document using its title.
   */
  TEX_EXTERN tex_section *document_find_section(tex_document *doc,
                                                const char   *sectitle);

  /**
   * Add explicit content from memory. For adding content from filesystem
   * see document_add_fs_content.
   */
  TEX_EXTERN tex_error_t document_add_content(tex_document *doc,
                                              const char   *content);

  /**
   * Append the contents of a file to the document body.
   */
  TEX_EXTERN tex_error_t document_add_fs_content(tex_document *doc,
                                                 const char   *filename);

  /**
   * Add a tex_figure to the document body.
   */
  TEX_EXTERN tex_error_t document_add_figure(tex_document *doc,
                                             tex_figure   *fig);

  /**
   * Internal API call used by libtex to automatically append required LaTeX
   * packages to a document when needed. This function is not intended for
   * direct use by end users. Package declarations are managed internally and
   * should not be handled manually.
   */
  TEX_EXTERN tex_error_t document_add_package(tex_document *doc,
                                              tex_package  *package);

  /**
   * Write the document to a buffer in memory.
   */
  TEX_EXTERN tex_error_t document_write(const tex_document *doc,
                                        char               *buffer,
                                        size_t              buffer_size);

  /**
   * Write the document to a file in the filesystem.
   */
  TEX_EXTERN tex_error_t document_fs_write(const tex_document *doc,
                                           const char         *file);

#ifdef __cplusplus
};
#endif
