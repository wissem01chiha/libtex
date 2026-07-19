/***************************************************************************
 * SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 ***************************************************************************/

#pragma once

#include <errno.h>
#include <uv/errno.h>

#ifdef __cplusplus
extern "C"
{
#endif

  // standard error codes used in libtex.
  typedef enum tex_error_t
  {
    TEX_ENONE = 0,
    TEX_EFAIL_MEMALLOC,
    TEX_EFAIL_FOPEN,
    TEX_EFAIL_GETPWUID,
    TEX_EFAIL_GETUSERNAME,
    TEX_EFAIL_TIME,
    TEX_EFAIL_LOCALTIME,
    TEX_ENULL_DOCUMENT,
    TEX_ENULL_SECTION,
    TEX_ENULL_REPORT,
    TEX_ENULL_BUFFER,
    TEX_ENULL_FIGURE,
    TEX_ENULL_TABLE,
    TEX_ENULL_LIST,
    TEX_ENULL_PACKAGE,
    TEX_EOVERFLOW_BUFFER,
    TEX_EINVAL_INPUT,
    TEX_EUNKNOWN,

    // libuv error codes
    TEX_EEOF            = UV__EOF,
    TEX_EUNKNOWNUV      = UV__UNKNOWN,
    TEX_E2BIG           = UV__E2BIG,
    TEX_EACCES          = UV__EACCES,
    TEX_EADDRINUSE      = UV__EADDRINUSE,
    TEX_EADDRNOTAVAIL   = UV__EADDRNOTAVAIL,
    TEX_EAFNOSUPPORT    = UV__EAFNOSUPPORT,
    TEX_EAGAIN          = UV__EAGAIN,
    TEX_EALREADY        = UV__EALREADY,
    TEX_EBADF           = UV__EBADF,
    TEX_EBUSY           = UV__EBUSY,
    TEX_ECANCELED       = UV__ECANCELED,
    TEX_ECHARSET        = UV__ECHARSET,
    TEX_ECONNABORTED    = UV__ECONNABORTED,
    TEX_ECONNREFUSED    = UV__ECONNREFUSED,
    TEX_ECONNRESET      = UV__ECONNRESET,
    TEX_EDESTADDRREQ    = UV__EDESTADDRREQ,
    TEX_EEXIST          = UV__EEXIST,
    TEX_EFAULT          = UV__EFAULT,
    TEX_EHOSTUNREACH    = UV__EHOSTUNREACH,
    TEX_EINTR           = UV__EINTR,
    TEX_EINVAL          = UV__EINVAL,
    TEX_EIO             = UV__EIO,
    TEX_EISCONN         = UV__EISCONN,
    TEX_EISDIR          = UV__EISDIR,
    TEX_ELOOP           = UV__ELOOP,
    TEX_EMFILE          = UV__EMFILE,
    TEX_EMSGSIZE        = UV__EMSGSIZE,
    TEX_ENAMETOOLONG    = UV__ENAMETOOLONG,
    TEX_ENETDOWN        = UV__ENETDOWN,
    TEX_ENETUNREACH     = UV__ENETUNREACH,
    TEX_ENFILE          = UV__ENFILE,
    TEX_ENOBUFS         = UV__ENOBUFS,
    TEX_ENODEV          = UV__ENODEV,
    TEX_ENOENT          = UV__ENOENT,
    TEX_ENOMEM          = UV__ENOMEM,
    TEX_ENONET          = UV__ENONET,
    TEX_ENOSPC          = UV__ENOSPC,
    TEX_ENOSYS          = UV__ENOSYS,
    TEX_ENOTCONN        = UV__ENOTCONN,
    TEX_ENOTDIR         = UV__ENOTDIR,
    TEX_ENOTEMPTY       = UV__ENOTEMPTY,
    TEX_ENOTSOCK        = UV__ENOTSOCK,
    TEX_ENOTSUP         = UV__ENOTSUP,
    TEX_EPERM           = UV__EPERM,
    TEX_EPIPE           = UV__EPIPE,
    TEX_EPROTO          = UV__EPROTO,
    TEX_EPROTONOSUPPORT = UV__EPROTONOSUPPORT,
    TEX_EPROTOTYPE      = UV__EPROTOTYPE,
    TEX_EROFS           = UV__EROFS,
    TEX_ESHUTDOWN       = UV__ESHUTDOWN,
    TEX_ESPIPE          = UV__ESPIPE,
    TEX_ESRCH           = UV__ESRCH,
    TEX_ETIMEDOUT       = UV__ETIMEDOUT,
    TEX_ETXTBSY         = UV__ETXTBSY,
    TEX_EXDEV           = UV__EXDEV,
    TEX_EFBIG           = UV__EFBIG,
    TEX_ENOPROTOOPT     = UV__ENOPROTOOPT,
    TEX_ERANGE          = UV__ERANGE,
    TEX_ENXIO           = UV__ENXIO,
    TEX_EMLINK          = UV__EMLINK,
    TEX_EHOSTDOWN       = UV__EHOSTDOWN,
    TEX_EREMOTEIO       = UV__EREMOTEIO,
    TEX_ENOTTY          = UV__ENOTTY,
    TEX_EFTYPE          = UV__EFTYPE,
    TEX_EILSEQ          = UV__EILSEQ,
    TEX_EOVERFLOW       = UV__EOVERFLOW,
    TEX_ESOCKTNOSUPPORT = UV__ESOCKTNOSUPPORT,
    TEX_ENODATA         = UV__ENODATA,
    TEX_EUNATCH         = UV__EUNATCH,
    TEX_ENOEXEC         = UV__ENOEXEC

  } tex_error_t;

#ifdef __cplusplus
};
#endif