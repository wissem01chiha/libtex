#include "libtex.h"
#include <stdlib.h>

#ifdef _MSC_VER
#include <Lmcons.h>
#include <windows.h>
#endif

const char *
getusername (int err)
{
#ifndef _MSC_VER
  uid_t uid = getuid ();
  struct passwd *pw = getpwuid (uid);
  if (pw == NULL)
    {
      if (err)
        *err = LIBTEX_ENUPTR;
      return "";
    }
  if (err)
    *err = LIBTEX_OK;
  return pw->pw_name;
#else
  static char username[UNLEN + 1];
  DWORD username_len = UNLEN + 1;
  if (!GetUserName (username, &username_len))
    {
        err = LIBTEX_ENUPTR;
      return "";
    }
    err = LIBTEX_OK;
  return username;
#endif
}

const char *
getdocumentclass (tex_document_t doc_t)
{
  switch (doc_t)
    {
    case ARTICLE_DOC:
      return "article";
    case BOOK_DOC:
      return "book";
    case REPORT_DOC:
      return "report";
    case PRESENTATION_DOC:
      return "beamer";
    default:
      return "";
    }
}

const char *
getdocumentlang(tex_language_t lang_t)
{
    switch (lang_t) {
    case ENGLISH:
        return "english";      
    case FRENCH:
        return "french";      
    case GERMAN:
        return "ngerman";      
    case SPANISH:
        return "spanish";      
    case ITALIAN:
        return "italian";      
    case PORTUGUESE:
        return "portuguese";   
    case DUTCH:
        return "dutch";       
    case RUSSIAN:
        return "russian";     
    case CHINESE:
        return "chinese";      
    case JAPANESE:
        return "japanese";     
    case ARABIC:
        return "arabic";       
    default:
        return "english";    
    }
}

const char *
getdate (int err)
{
    err =LIBTEX_OK;
  return NULL;
}
