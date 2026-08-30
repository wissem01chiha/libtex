Code Samples
==================

- Writing your first LaTeX document

.. code-block:: c

   #include <tex/tex.h>
   #include <stdio.h>

   tex_error_t   err = TEX_ENONE;
   tex_document *doc = document_create(&err);

   tex_error_t write_err = document_fs_write_default(doc);
   if (write_err != TEX_ENONE) {
       printf("Failed to write document: error code %d\n", write_err);
   }
