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

#ifndef Algorithm_h_
#define Algorithm_h_

#include "errno.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tex_algorithm tex_algorithm;

struct tex_algorithm {
  char caption;
  char label;
};

tex_algorithm* algorithm_create(tex_error_t* err);
void alorithm_set_caption(tex_algorithm* algorithm, const char* caption);
int algorithm_add_line(tex_algorithm* algorithm, const char* line, int indent);
int algorithm_add_comment(tex_algorithm* algorithm, const char* comment,
                          int indent);
int algorithm_add_for_loop(tex_algorithm* algorithm, const char* condition,
                           int indent);
int algorithm_add_while_loop(tex_algorithm* algorithm, const char* condition,
                             int indent);
int algorithm_add_if(tex_algorithm* algorithm, const char* condition,
                     int indent);
int algorithm_add_else(tex_algorithm* algorithm, int indent);
int algorithm_add_else_if(tex_algorithm* algorithm, const char* condition,
                          int indent);
int algorithm_add_end(tex_algorithm* algorithm, const char* statement,
                      int indent);
int algorithm_add_return(tex_algorithm* algorithm, const char* value,
                         int indent);
int algorithm_add_break(tex_algorithm* algorithm, int indent);
int algorithm_add_continue(tex_algorithm* algorithm, int indent);
int algorithm_add_function(tex_algorithm* algorithm, const char* name,
                           const char* args, int indent);
int algorithm_add_function_end(tex_algorithm* algorithm, int indent);

#ifdef __cplusplus
}; /* extern "C" { */
#endif

#endif  // Algorithm_h_