#include <stdlib.h>
#include "tex.h"

tex_table_row* tex_table_row_create(size_t size, tex_error_t* err) {

  tex_table_row* row = calloc(1, sizeof(tex_table_row));
  err = TEX_ERROR_NONE;
  return row;
}

tex_table* table_create(const char* caption, tex_error_t* err) {

  tex_table* tab = calloc(1, sizeof(tex_table));
  if(tab==NULL){
    *err =TEX_ERROR_MEMALLOC_FAILED;
  }
  if (caption != NULL) {
    tab->caption = strdup(caption);
  }
  *err = TEX_ERROR_NONE;
  return tab;
}

tex_error_t table_delete(tex_table* tab) {

  if (tab == NULL) {
    return TEX_ERROR_INVALID_TABLE;
  }

  free(tab);
  return TEX_ERROR_NONE;
}

tex_error_t table_set_caption(tex_table* tab, const char* caption) {

  if (tab == NULL) {
    return TEX_ERROR_INVALID_TABLE;
  }

  return TEX_ERROR_NONE;
}
