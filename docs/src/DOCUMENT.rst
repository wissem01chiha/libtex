Document API Documentation
===============================

.. c:enum:: tex_document_t

  Supported LaTeX document classes:

  - ``Article`` default 
  - ``Report``
  - ``Book``
  - ``Beamer``

.. c:struct:: tex_document

  Represents a LaTeX document.

    - ``tex_document_t type``
    - ``tex_language_t language``
    - ``tex_element *elements``
    - ``char *title``
    - ``char *author``
    - ``char *date``

.. c:function:: tex_document *document_create(tex_error_t *err)

  Create a new document object. Default type is ``Article``.

.. c:function:: tex_error_t document_delete(tex_document *doc)

  Delete and free a document object.

.. c:function:: tex_error_t document_set_class(tex_document *doc, tex_document_t doc_t)

  Set the document class (Article, Report, Book, Beamer).

.. c:function:: tex_error_t document_set_title(tex_document *doc, const char *title)

  Set the document title.

.. c:function:: tex_error_t document_set_author(tex_document *doc, const char *author)

  Set the document author. Default is system user name.

.. c:function:: tex_error_t document_set_date(tex_document *doc, const char *date)

  Set the document date. Default is today's date.

.. c:function:: tex_error_t document_set_language(tex_document *doc, tex_language_t language)

  Set the document language. Default is English.

.. c:function:: const char *document_get_class(tex_document_t doc_t)

  Convert a document class enum to string.

.. c:function:: tex_error_t document_add_section(tex_document *doc, tex_section *sec)

  Add a section to the document. Sections form a linked list.

.. c:function:: tex_error_t document_add_content(tex_document *doc, tex_content *content)

  Add explicit content from memory.

.. c:function:: tex_error_t document_add_fs_content(tex_document *doc, const char *filename)

  Append content from a file.

.. c:function:: tex_error_t document_add_figure(tex_document *doc, tex_figure *fig)

  Add a figure to the document.

.. c:function:: tex_error_t document_add_list(tex_document *doc, tex_list *list)

  Add a list to the document.

.. c:function:: tex_error_t document_add_package(tex_document *doc, tex_package *package)

  Internal API: append required LaTeX packages automatically.

.. c:function:: tex_error_t document_write(const tex_document *doc, char *buffer, size_t buffer_size)

  Write document to a memory buffer.

.. c:function:: tex_error_t document_fs_write(const tex_document *doc, const char *file)

  Write document to a file.

.. c:function:: tex_error_t document_fs_write_default(const tex_document *doc)

  Write document to ``main.tex`` in the current directory.