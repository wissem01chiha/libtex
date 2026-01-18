/**
    BSD 2-Clause License

    Copyright (c) 2026, wissem chiha 

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef LIBTEX_DOCUMENT_H
#define LIBTEX_DOCUMENT_H

#include "type.h"
#include "section.h"

#ifdef __cplusplus 
extern "C" { 
#endif

typedef struct tex_document tex_document;

tex_document* document_create(tex_document_t type,
                                const char* title,
                                const char* author,
                                const char* date,
                                int language, int err);

int document_destroy(tex_document* doc);

int document_set_title(tex_document* doc, const char* title);
int document_set_author(tex_document* doc, const char* author);
int document_set_date(tex_document* doc, const char* date);
int document_set_language(tex_document* doc, tex_language_t language);
int document_add_package(tex_document* doc,
                         const char* package,
                         const char* options);
int document_add_section(tex_document* doc,
                         const tex_section* sec);

int document_bf_write(const tex_document* doc,
                    char* buffer, 
                    size_t buffer_size);

int document_fs_write(const tex_document* doc,
                    const char* file);


#ifdef __cplusplus
}; // extern "C"
#endif

#endif // LIBTEX_DOCUMENT_H
