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

#include "errno.h"
#include "document.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

  typedef enum tex_bibstyle_t
  {
    PLAIN           = 0,
    ALPHA           = 1,
    ABBRV           = 2,
    ACM             = 3,
    IEEE            = 4,
    APA             = 5,
    CHICAGO         = 6,
    MLA             = 7,
    HARVARD         = 8,
    CUSTOM_BIBSTYLE = 9
  } tex_bibstyle_t;

  typedef enum tex_bib_t
  {
    ARTICLE       = 0,
    BOOK          = 1,
    INPROCEEDINGS = 2,
    TECHREPORT    = 3,
    PHDTHESIS     = 4,
    MASTERSTHESIS = 5,
    MISC          = 6
  } tex_bib_t;

  typedef struct
  {
    int e;
  } tex_bibliography;

  tex_bibliography *bibliography_create(tex_error_t *err);
  tex_error_t       bibliography_delete(tex_bibliography *bibliography);

  tex_error_t bibliography_set_bib_file(tex_bibliography *bibliography,
                                        const char       *bib_file,
                                        int               use_external_file);
  tex_error_t bibliography_add_entry(tex_bibliography *bibliography,
                                     const char       *entry_type,
                                     const char       *key,
                                     const char      **fields,
                                     const char      **values,
                                     size_t            field_count);
  tex_error_t bibliography_set_style(tex_bibliography *bibliography, int style);
  tex_error_t bibliography_set_custom_style(tex_bibliography *bibliography,
                                            const char       *custom_style);
  tex_error_t bibliography_generate(tex_bibliography *bibliography,
                                    const char       *output_dir);

#ifdef __cplusplus
}; /* extern "C" { */
#endif
