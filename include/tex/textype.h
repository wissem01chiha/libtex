// SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
// SPDX-License-Identifier: BSD-2-Clause

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

  typedef enum tex_transition_t
  {
    NONE    = 0,
    FADE    = 1,
    PUSH    = 2,
    COVER   = 3,
    UNCOVER = 4,
    SPLIT   = 5,
    BLINDS  = 6,
    WIPE    = 7
  } tex_transition_t;

  typedef enum tex_theme_t
  {
    DEFAULT_THEME = 0,
    BERKELEY      = 1,
    MADRID        = 2,
    ANTIBES       = 3,
    COPENHAGEN    = 4,
    BERLIN        = 5,
    MANHATTAN     = 6,
    WARSAW        = 7,
    SINGAPORE     = 8
  } tex_theme_t;

#ifdef __cplusplus
};
#endif
