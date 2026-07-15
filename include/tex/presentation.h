/** Copyright (c) 2026, wissem chiha

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

  1. Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.

  2. Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#include "document.h"
#include "errno.h"

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

  int presentation_set_institute(tex_presentation *presentation, const char *institute);
  int presentation_set_subtitle(tex_presentation *presentation, const char *subtitle);
  int presentation_set_navigation(tex_presentation *presentation, int show);
  int presentation_set_transition(tex_presentation *presentation, int transition);
  int presentation_add_slide(tex_presentation *presentation,
                             const char       *title,
                             const char       *content);
  int presentation_generate(tex_presentation *presentation,
                            char            **output,
                            size_t           *output_size);

#ifdef __cplusplus
};
#endif
