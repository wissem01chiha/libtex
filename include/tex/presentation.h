/*
 * SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include "document.h"
#include "texerrno.h"

#ifdef __cplusplus
extern "C"
{
#endif

  typedef struct tex_presentation tex_presentation;

  int presentation_create(tex_presentation **presentation,
                          const char        *title,
                          const char        *author,
                          const char        *date,
                          int                language,
                          int                theme,
                          int                color_theme,
                          int                err);
  int presentation_delete(tex_presentation *presentation);

  int presentation_set_institute(tex_presentation *presentation,
                                 const char       *institute);
  int presentation_set_subtitle(tex_presentation *presentation,
                                const char       *subtitle);
  int presentation_set_navigation(tex_presentation *presentation, int show);
  int presentation_set_transition(tex_presentation *presentation,
                                  int               transition);
  int presentation_add_slide(tex_presentation *presentation,
                             const char       *title,
                             const char       *content);
  int presentation_generate(tex_presentation *presentation,
                            char            **output,
                            size_t           *output_size);

#ifdef __cplusplus
};
#endif
