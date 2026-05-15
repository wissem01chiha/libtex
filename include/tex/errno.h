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

#ifndef ERRNO_H
#define ERRNO_H

#include <errno.h>

#if EDOM > 0
#define TEX_ERR(x) (-(x))
#else
#define TEX_ERR(x) (x)
#endif

#define TEX_OK 0

#define TEX_EOF (-4095)
#define TEX_UNKNOWN (-4094)
#define TEX_NOMEM (-4093)
#define TEX_IOERR (-4092)
#define TEX_FORMAT (-4091)
#define TEX_RANGE (-4090)
#define TEX_EXIST (-4089)
#define TEX_INTR (-4088)
#define TEX_PERM (-4087)
#define TEX_BUSY (-4086)
#define TEX_NOTSUP (-4085)
#define TEX_EACCES (-4084)
#define TEX_ENOENT (-4083)
#define TEX_EINVAL (-4082)
#define TEX_ENUPTR (-4081)
#define TEX_ERANGE (-4080)
#define TEX_EOVERFLOW (-4079)

#define TEX_EDOCUMENT (-5200)
#define TEX_ESECTION (-5100)
#define TEX_EFIGURE (-5300)
#define TEX_ETABLE (-5400)
#define TEX_ELIST (-5500)
#define TEX_EBOOK (-5600)
#define TEX_EPTT (-5700)
#define TEX_EREPORT (-5800)

#define TEX_ECITE (-6000)
#define TEX_ELABEL (-6100)

#define TEX_EUTF8 TEX_ERR(EILSEQ)
#define TEX_ECHARSET (-9400)

#endif  // ERRNO_H