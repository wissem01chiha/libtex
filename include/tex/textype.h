/**
    Copyright (c) 2026, wissem chiha

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

#ifndef TEX_TEXTYPE_H
#define TEX_TEXTYPE_H

#ifdef __cplusplus
extern "C" {
#endif







typedef enum tex_transition_t {
  NONE = 0,
  FADE = 1,
  PUSH = 2,
  COVER = 3,
  UNCOVER = 4,
  SPLIT = 5,
  BLINDS = 6,
  WIPE = 7
} tex_transition_t;

typedef enum tex_color_theme_t {
  DEFAULT_COLOR = 0,
  BEAVER = 1,
  CRANE = 2,
  DOLPHIN = 3,
  DOVE = 4,
  FLY = 5,
  SEAGULL = 6,
  WOLVERINE = 7
} tex_color_theme_t;

typedef enum tex_theme_t {
  DEFAULT_THEME = 0,
  BERKELEY = 1,
  MADRID = 2,
  ANTIBES = 3,
  COPENHAGEN = 4,
  BERLIN = 5,
  MANHATTAN = 6,
  WARSAW = 7,
  SINGAPORE = 8
} tex_theme_t;

#ifdef __cplusplus
};
#endif

#endif  // TEX_TEXTYPE_H
