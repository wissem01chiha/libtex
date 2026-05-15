#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tex.h"

tex_figure* figure_create(const char* image_path, const char* position) {
  tex_figure* fig = calloc(1, sizeof(tex_figure));
  if (fig == NULL) {
    return NULL;
  }
  fig->image_path = strdup(image_path);
  fig->position = strdup(position);
  return fig;
}

int figure_delete(tex_figure* fig) {
  if (fig == NULL) {
    return 0;
  }
  free(fig->image_path);
  free(fig->position);
  free(fig);
  return TEX_ERROR_NONE;
}

int figure_set_caption(tex_figure* fig, const char* caption) {
  if (fig == NULL || caption == NULL) {
    return TEX_ERROR_INVALID_FIGURE;
  }
  fig->caption = strdup(caption);
  return TEX_ERROR_NONE;
}

int figure_set_label(tex_figure* fig, const char* label) {
  if(fig==NULL){
    return TEX_ERROR_INVALID_FIGURE;
  }
  fig->label = label;
  return TEX_ERROR_NONE;
}

int figure_set_width(tex_figure* fig, const char* width) {
    if(fig==NULL){
    return TEX_ERROR_INVALID_FIGURE;
  }
  return TEX_ERROR_NONE;
}

int figure_write(const tex_figure* fig, char* buffer, size_t buffer_size) {
  if (fig==NULL){
    return -1;
  }
  return TEX_ERROR_NONE;
}
