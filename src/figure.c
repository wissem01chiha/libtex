#include "libtex.h"
#include <stdlib.h> 
#include <string.h> 
#include <stdio.h>

struct tex_figure { 

    char* image_path;
    char* caption;
    char* label;
    char* width;
    char* position;
};

tex_figure *figure_create(const char *image_path, const char *position)
{
    tex_figure* fig = calloc(1, sizeof(tex_figure));
    if (fig == NULL) {
        return NULL;
    }
    fig->image_path = _strdup(image_path);
    fig->position = _strdup(position);
    return fig;
}

int figure_destroy(tex_figure *fig)
{
    if (fig == NULL) {
        return 0;
    }
    free(fig->image_path);
    free(fig->position);
    free(fig);
    return LIBTEX_OK;
}

int figure_set_caption(tex_figure *fig, const char *caption)
{
    if(fig == NULL || caption == NULL) {
        return LIBTEX_EINVAL;
    }
    fig->caption = _strdup(caption);
    return LIBTEX_OK;
}

int figure_set_label(tex_figure *fig, const char *label)
{
    return LIBTEX_OK;
}

int figure_set_width(tex_figure *fig, const char *width)
{
    return LIBTEX_OK;
}

int figure_write(const tex_figure *fig, char *buffer, size_t buffer_size)
{
    return LIBTEX_OK;
}