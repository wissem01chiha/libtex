#include "libtex.h"
#include <stdlib.h>

struct tex_document {

    tex_document_t type;
    tex_language_t language;
    char* title;
    char* author;
    char* date;
};

tex_document* document_create(tex_document_t type,
                                const char* title,
                                const char* author,
                                const char* date,
                                int language, int err)
{
    tex_document* doc = calloc(1, sizeof(tex_document));
    if (doc == NULL) {
        return NULL;
    }
    doc->type = (tex_document_t)type;
    doc->language = (tex_language_t)language;
    doc->title = _strdup(title);
    doc->author = _strdup(author);
    doc->date = _strdup(date);
    err = LIBTEX_OK;
    return doc;
}

int document_destroy(tex_document *doc)
{   
    if( doc == NULL) {
        return 0;
    }
    free(doc->title);
    free(doc->author);
    free(doc->date);
    free(doc);
    return LIBTEX_OK;
}

int document_set_title(tex_document *doc, const char *title)
{
    if(doc == NULL || title == NULL) {
        return LIBTEX_EINVAL;
    }
    doc->title = _strdup(title);
    return LIBTEX_OK;
}

int document_set_author(tex_document *doc, const char *author)
{
    if(doc == NULL || author == NULL) {
        return LIBTEX_EINVAL;
    }
    doc->author = _strdup(author);
    return LIBTEX_OK;
}

int document_write(const tex_document *doc, char *buffer, size_t buffer_size) 
{
    if(doc == NULL || buffer == NULL) {
        return LIBTEX_EINVAL;
    }   
    return LIBTEX_OK;
}

int document_fs_write(const tex_document *doc, const char *file)
{
    return LIBTEX_OK;
}