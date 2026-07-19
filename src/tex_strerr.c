/***************************************************************************
 * SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 ***************************************************************************/

#include "tex.h"
#include <stdlib.h>
#include <string.h>

TEX_EXTERN const char *tex_strerr(int err)
{
  if(err >= UV__EOF){
    return uv_strerror(err);
  }
    return NULL;
}