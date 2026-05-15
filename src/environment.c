#include <stdlib.h>
#include <string.h>
#include "tex.h"

struct tex_environment {
  char* name;
};

int environment_create(const char* name, tex_environment** env, int err) {
  tex_environment* environment = calloc(1, sizeof(tex_environment));
  if (environment == NULL) {
    err = TEX_NOMEM;
    return err;
  }
  environment->name = strdup(name);
  *env = environment;
  err = TEX_ERROR_NONE;
  return err;
}

int environment_delete(tex_environment* env) {
  if (env != NULL) {
    free(env->name);
    free(env);
  }
  return TEX_ERROR_NONE;
}

int environment_begin_write(const tex_environment* env, char* buffer,
                            size_t buffer_size) {
  if (env == NULL || buffer == NULL) {
    return TEX_EINVAL;
  }

  size_t name_len = strlen(env->name);
  if (name_len >= buffer_size) {
    return TEX_EINVAL;
  }

  strcpy(buffer, "\\begin{");
  strcat(buffer, env->name);
  strcat(buffer, "}\n");

  return TEX_ERROR_NONE;
}

int environment_end_write(const tex_environment* env, char* buffer,
                          size_t buffer_size) {
  if (env == NULL || buffer == NULL) {
    return TEX_EINVAL;
  }

  size_t name_len = strlen(env->name);
  if (name_len >= buffer_size) {
    return TEX_EINVAL;
  }

  strcpy(buffer, "\\end{");
  strcat(buffer, env->name);
  strcat(buffer, "}\n");

  return TEX_ERROR_NONE;
}

int environment_write(const tex_environment* env, char* buffer,
                      size_t buffer_size) {
  if (env == NULL || buffer == NULL) {
    return TEX_EINVAL;
  }
  int env_bg_wrt_err = 0;
  int env_end_wrt_err = 0;

  env_bg_wrt_err = environment_begin_write(env, buffer, buffer_size);
  if (env_bg_wrt_err != TEX_ERROR_NONE) {
    return env_bg_wrt_err;
  }
  size_t buffer_size_ = buffer_size - strlen(buffer);
  env_end_wrt_err =
      environment_end_write(env, buffer + strlen(buffer), buffer_size_);
  if (env_end_wrt_err != TEX_ERROR_NONE) {
    return env_end_wrt_err;
  }

  return TEX_ERROR_NONE;
}
