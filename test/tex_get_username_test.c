#include "tex.h"
#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
  tex_error_t err = TEX_ERROR_NONE;
  const char *username = tex_get_username (&err);

  if (err != TEX_ERROR_NONE)
    {
      fprintf (stderr, "getusername failed with error code %d\n", err);
      return 1;
    }

  if (username == NULL || username[0] == '\0')
    {
      return 2;
    }

  printf ("getusername returned: %s\n", username);
  return 0;
}
