#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tex.h"

const char* tex_language_to_string(tex_language_t lang){
switch (lang) {
    case ENGLISH:
      return "english";
    case FRENCH:
      return "french";
    case GERMAN:
      return "german";
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