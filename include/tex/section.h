// SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
// SPDX-License-Identifier: BSD-2-Clause

#pragma once

#include <stddef.h>
#include "texexport.h"
#include "figure.h"
#include "list.h"
#include "table.h"

#ifdef __cplusplus
extern "C"
{
#endif

  typedef struct tex_section tex_section;

  /**
   * Document section types.
   */
  typedef enum tex_section_t
  {
    Chapter       = 0,
    Section       = 1,
    Subsection    = 2,
    Subsubsection = 3
  } tex_section_t;

  struct tex_section
  {
    char         *title;
    tex_section_t level;
    tex_section  *subsection;
    char         *content;
    tex_figure   *figure;
    tex_list     *list;
    tex_section  *next;
  };

  TEX_EXTERN tex_section *
  section_create(const char *title, tex_section_t level, int err);

  TEX_EXTERN tex_error_t section_delete(tex_section *sec);

  /**
   * Find a given subsection in the given section using its title.
   */
  TEX_EXTERN tex_section *section_find_subsection(tex_section *sec,
                                                  const char  *sectitle);

  /**
   * Append content to the section body.
   */
  TEX_EXTERN tex_error_t section_add_content(tex_section *sec,
                                             const char  *content);

  /**
   * Append the contents of a file to the section body,
   * same spirit as document_add_fs_content.
   */
  TEX_EXTERN tex_error_t section_add_fs_content(tex_section *sec,
                                                const char  *filename);

  /**
   * Write the section to a memory buffer.
   */
  TEX_EXTERN tex_error_t section_write(const tex_section *sec,
                                       char              *buffer,
                                       size_t             buffer_size);

#ifdef __cplusplus
};
#endif
