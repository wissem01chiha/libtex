#include "libtex.h"
#include <stdio.h>
#include <stdlib.h>

int main (){

  int err;
  tex_document *doc = document_create (REPORT_DOC, "Sample Title",
                                       NULL, "today", ENGLISH, &err);
  if (doc == NULL)
    {
      return -1;
    }
  const char *filename = "document_fs_write_test.tex";

  int write_err = document_fs_write (doc, filename);
  if (write_err != LIBTEX_OK)
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
  int delerr = document_delete (doc);
  return 0;
}
