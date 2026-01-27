#include "libtex.h"
#include <stdio.h>
#include <stdlib.h>

int
main (void)
{
  int err = 0;
  const char *username = getusername (&err);

  if (err != LIBTEX_OK)
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
