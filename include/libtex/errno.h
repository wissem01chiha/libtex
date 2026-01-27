/**
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

#ifndef LIBTEX_ERRNO_H
#define LIBTEX_ERRNO_H

#include <errno.h>

#if EDOM > 0
# define LIBTEX_ERR(x) (-(x))
#else
# define LIBTEX_ERR(x) (x)
#endif

#define LIBTEX_OK      0

#define LIBTEX_EOF     (-4095)
#define LIBTEX_UNKNOWN (-4094)
#define LIBTEX_NOMEM  (-4093)
#define LIBTEX_IOERR  (-4092)
#define LIBTEX_FORMAT (-4091)
#define LIBTEX_RANGE  (-4090)
#define LIBTEX_EXIST  (-4089)
#define LIBTEX_INTR   (-4088)
#define LIBTEX_PERM   (-4087)
#define LIBTEX_BUSY   (-4086)
#define LIBTEX_NOTSUP (-4085)
#define LIBTEX_EACCES  (-4084)
#define LIBTEX_ENOENT  (-4083)
#define LIBTEX_EINVAL  (-4082)
#define LIBTEX_ENUPTR  (-4081)
#define LIBTEX_ERANGE  (-4080)
#define LIBTEX_EOVERFLOW (-4079)

#define LIBTEX_EDOCUMENT (-5200)
#define LIBTEX_ESECTION  (-5100)
#define LIBTEX_EFIGURE  (-5300)
#define LIBTEX_ETABLE  (-5400)
#define LIBTEX_ELIST  (-5500)
#define LIBTEX_EBOOK  (-5600)
#define LIBTEX_EPTT  (-5700)
#define LIBTEX_EREPORT  (-5800)

#define LIBTEX_ECITE  (-6000)
#define LIBTEX_ELABEL (-6100)

#define LIBTEX_EUTF8  LIBTEX_ERR(EILSEQ)
#define LIBTEX_ECHARSET     (-9400)

#endif // LIBTEX_ERRNO_H