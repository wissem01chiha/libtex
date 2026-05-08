#include "tex.h"
#include <stdlib.h>

struct tex_table_row
{
  size_t size;
  size_t capacity;
  char *content;
};

struct tex_table
{
  char *label;
  char *caption;
  tex_table_row *row;
};

tex_table_row *
tex_table_row_create (size_t size, int err)
{

  tex_table_row *row = calloc (1, sizeof (tex_table_row));
  err = TEX_OK;
  return row;
}

tex_table *
table_create (const char *caption, int err)
{

  tex_table *tab = calloc (1, sizeof (tex_table));

  if (caption != NULL)
    {
      tab->caption = _strdup (caption);
    }
  err = TEX_OK;
  return tab;
}

int
table_delete (tex_table *tab)
{

  if (tab == NULL)
    {
      return TEX_OK;
    }

  free (tab);
  return TEX_OK;
}

int
table_set_caption (tex_table *tab, const char *caption)
{

  return TEX_OK;
}