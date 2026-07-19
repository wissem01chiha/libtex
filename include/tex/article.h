/***************************************************************************
 * SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 ***************************************************************************/

#pragma once

#include "document.h"
#include "texerrno.h"
#include "texexport.h"

#ifdef __cplusplus
extern "C"
{
#endif

  typedef struct
  {
    tex_document *document;
  } tex_article;

  tex_article *article_create(tex_error_t *err);
  tex_error_t  article_delete(tex_article *art);

  /* Inherited member functions from text_document */

  tex_error_t article_set_title(tex_article *doc, const char *title);
  tex_error_t article_set_author(tex_article *doc, const char *author);
  tex_error_t article_set_date(tex_article *doc, const char *date);
  tex_error_t article_set_language(tex_article *doc, tex_language_t language);
  tex_error_t article_add_content(tex_article *doc, const char *content);
  tex_error_t article_add_section(tex_article *doc, const tex_section *sec);

  tex_error_t article_enable_index(tex_article *doc);

#ifdef __cplusplus
};
#endif
