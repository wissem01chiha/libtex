// SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
// SPDX-License-Identifier: BSD-2-Clause

#pragma once

#include "texerrno.h"
#include "texexport.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Enumeration of all element types supported in a TeX/LaTeX document.
 * This enumeration defines the different kinds of elements that can appear
 * inside a document section. The set of supported elements will be progressively
 * increased according to the release roadmap.
 */
typedef enum tex_element_type {
    TEX_ELE_CONTENT,
    TEX_ELE_SECTION,
    TEX_ELE_FIGURE,
    TEX_ELE_TABLE,
    TEX_ELE_LIST
} tex_element_type;

typedef struct tex_element tex_element;

struct tex_element {
    tex_element_type type;
    void *data;              
    struct tex_element *next;
};

  /**
   * Create a generic tex_element based object
   */
  TEX_EXTERN tex_element *element_create(tex_error_t *err);

  /**
   * Delete a tex_element based object
   */
  TEX_EXTERN tex_error_t element_delete(tex_element *ele);

/**
 * A generic function pointer for writing an element into a memory buffer.
 * All elements must implement the same signature. Each element callback
 * is registered into a static compile-time structure (see element_write)
 * for dispatching. For more information, refer to the element serialization API.
 */
  typedef  int (*element_writer)(const void *element,
                                  char       *buffer,
                                  size_t      buffer_size,
                                  tex_error_t *err);

 extern element_writer element_write[];


#ifdef __cplusplus
};
#endif