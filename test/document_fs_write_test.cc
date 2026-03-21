#include "tex.h"
#include <stdio.h>
#include <stdlib.h>

int main (){

  int err;
  tex_document *doc = document_create (REPORT_DOC, "Document Title",
                                        &err);
  if (doc == NULL)
    {
      return -1;
    }
  const char *filename = "document_fs_write_test.tex";

  int write_err = document_fs_write (doc, filename);
  if (write_err != TEX_OK)
    {
      fprintf (stderr, "document_fs_write failed with code %d\n", write_err);
      document_delete (doc);
      return 2;
    }

  FILE *f = fopen (filename, "r");
  if (f == NULL)
    {
      fprintf (stderr, "file %s not created\n", filename);
      document_delete (doc);
      return 3;
    }
  fclose (f);
  document_delete (doc);
  return 0;
}
