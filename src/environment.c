#include "libtex.h"

struct tex_environment {
    char* name;
};

int environment_create(const char* name, tex_environment** env, int err)
{
    tex_environment* environment = calloc(1, sizeof(tex_environment));
    if (environment == NULL) {
        err = LIBTEX_NOMEM;
        return err;
    }
    environment->name = _strdup(name);
    *env = environment;
    err = LIBTEX_OK;
    return err;
}

int environment_destroy(tex_environment *env)
{
    if (env != NULL) {
        free(env->name);
        free(env);
    }
    return LIBTEX_OK;
}

int environment_begin_write(const tex_environment *env, char *buffer, size_t buffer_size)
{
    if (env == NULL || buffer == NULL) {
        return LIBTEX_EINVAL;
    }

    size_t name_len = strlen(env->name);
    if (name_len >= buffer_size) {
        return LIBTEX_EINVAL;
    }

    strcpy(buffer, "\\begin{");
    strcat(buffer, env->name);
    strcat(buffer, "}\n");

    return LIBTEX_OK;
}

int environment_end_write(const tex_environment *env, char *buffer, size_t buffer_size)
{
    if (env == NULL || buffer == NULL) {
        return LIBTEX_EINVAL;
    }

    size_t name_len = strlen(env->name);
    if (name_len >= buffer_size) {
        return LIBTEX_EINVAL;
    }

    strcpy(buffer, "\\end{");
    strcat(buffer, env->name);
    strcat(buffer, "}\n");

    return LIBTEX_OK;
}

int environment_write(const tex_environment *env, char *buffer, size_t buffer_size)
{
    if (env == NULL || buffer == NULL) {
        return LIBTEX_EINVAL;
    }
    int env_bg_wrt_err = 0;
    int env_end_wrt_err = 0;

    env_bg_wrt_err = environment_begin_write(env, buffer, buffer_size);
    if(env_bg_wrt_err != LIBTEX_OK) {
        return env_bg_wrt_err;
    }
    size_t buffer_size =  buffer_size - strlen(buffer);
    env_end_wrt_err = environment_end_write(env, buffer + strlen(buffer),buffer_size);
    if(env_end_wrt_err != LIBTEX_OK) {
        return env_end_wrt_err;
    }

    return LIBTEX_OK;
}