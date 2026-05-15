#include <stdlib.h>
#include <time.h>
#include "tex.h"

#if defined(_WIN32) || defined(_MSC_VER)
#include <Lmcons.h>
#include <windows.h>
#else
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>
#endif

const char* tex_get_username(tex_error_t* err) {
#ifndef _MSC_VER
  uid_t uid = getuid();
  struct passwd* pw = getpwuid(uid);
  if (pw == NULL) {
    if (err)
      *err = TEX_ENUPTR;
    return "";
  }
  if (err)
    *err = TEX_ERROR_NONE;
  return pw->pw_name;
#else
  static char username[UNLEN + 1];
  DWORD username_len = UNLEN + 1;
  if (!GetUserName(username, &username_len)) {
    *err = TEX_ENUPTR;
    return "";
  }
  *err = TEX_ERROR_NONE;
  return username;
#endif
}

const char* tex_get_date(tex_error_t* err) {
  static char buffer[64];
  time_t t;
  struct tm* tm_info;

  t = time(NULL);
  if (t == ((time_t)-1)) {
    *err = TEX_IOERR;
    return NULL;
  }

  tm_info = localtime(&t);
  if (tm_info == NULL) {
    *err = TEX_IOERR;
    return NULL;
  }

  if (strftime(buffer, sizeof(buffer), "%Y-%m-%d", tm_info) == 0) {
    *err = TEX_IOERR;
    return NULL;
  }

  *err = TEX_ERROR_NONE;
  return buffer;
}
