#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tex.h"

tex_list* list_create(tex_list_t type, tex_error_t* err) {
  return NULL;
}

tex_error_t list_delete(tex_list* lst) {
  if(lst==NULL){
    return TEX_ERROR_INVALID_LIST;
  }
  free(lst);
  return  TEX_ERROR_NONE;
}
