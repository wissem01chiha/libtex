/*
 * SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

  typedef enum tex_section_t
  {
    CHAPTER       = 0,
    SECTION       = 1,
    SUBSECTION    = 2,
    SUBSUBSECTION = 3
  } tex_section_t;

  typedef struct tex_section
  {
    char               *title;
    tex_section_t       level;
    struct tex_section *subsection;
    char               *content;
    struct tex_section *next;
  } tex_section;

  tex_section *section_create(const char *title, tex_section_t level, int err);
  int          section_delete(tex_section *sec);

  int section_add_content(tex_section *sec, const char *content);

  // Append the contents of a file to the section body same spirt of
  // document_add_fs_content
  tex_error_t section_add_fs_content(tex_section *sec, const char *filename);

  tex_error_t section_write(const tex_section *sec, char *buffer, size_t buffer_size);

#ifdef __cplusplus
};
#endif
