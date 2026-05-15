#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // for strdup
#include "tex.h"

tex_section* section_create(const char* title, tex_section_t level, int err) {
  tex_section* sec = calloc(1, sizeof(tex_section));
  if (sec == NULL) {
    err = TEX_NOMEM;
    return NULL;
  }
  sec->title = strdup(title);
  sec->level = level;
  err = TEX_ERROR_NONE;
  return sec;
}

int section_delete(tex_section* sec) {
  if (sec == NULL) {
    return TEX_EINVAL;
  }
  free(sec->title);
  free(sec->content);
  free(sec);
  return TEX_ERROR_NONE;
}

int section_add_content(tex_section* sec, const char* content) {
  if (sec == NULL || content == NULL) {
    return TEX_EINVAL;
  }
  sec->content = content;
  return TEX_ERROR_NONE;
}

int section_write(const tex_section* sec, char* buffer, size_t buffer_size) {
  if (sec == NULL || buffer == NULL) {
    return TEX_EINVAL;
  }
  if (sec->level == CHAPTER) {
    snprintf(buffer, buffer_size, "\\chapter{%s}\n", sec->title);
  } else if (sec->level == SECTION) {
    snprintf(buffer, buffer_size, "\\section{%s}\n", sec->title);
  } else if (sec->level == SUBSECTION) {
    snprintf(buffer, buffer_size, "\\subsection{%s}\n", sec->title);
  } else if (sec->level == SUBSUBSECTION) {
    snprintf(buffer, buffer_size, "\\subsubsection{%s}\n", sec->title);
  }
  return TEX_ERROR_NONE;
}
