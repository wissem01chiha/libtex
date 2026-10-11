// SPDX-FileCopyrightText: 2026 Wissem Chiha
// SPDX-License-Identifier: BSD-2-Clause

#include "tex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tex_package *package_create(tex_error_t *err)
{
  tex_package *pk = (tex_package *) malloc(sizeof(tex_package));
  if (!pk)
  {
    if (err)
    {
      *err = TEX_EFAIL_MEMALLOC;
    }
    return NULL;
  }
  pk->name     = NULL;
  pk->options  = NULL;
  pk->enabled  = true;
  pk->priority = 0;
  pk->engine   = TEX_ENGINE_ANY;
  pk->next     = NULL;

  if (err)
  {
    *err = TEX_ENONE;
  }

  return pk;
}

tex_error_t package_delete(tex_package *pkg)
{
  if (pkg == NULL)
  {
    return TEX_ENONE;
  }
  free(pkg);
  return TEX_ENONE;
}

tex_package_option *package_option_create(tex_error_t *err)
{
  tex_package_option *opt =
      (tex_package_option *) malloc(sizeof(tex_package_option));
  if (!opt)
  {
    if (err)
    {
      *err = TEX_EFAIL_MEMALLOC;
    }
    return NULL;
  }

  opt->name  = NULL;
  opt->value = NULL;
  opt->next  = NULL;

  if (err)
  {
    *err = TEX_ENONE;
  }

  return opt;
}

tex_error_t package_option_delete(tex_package_option *opt)
{
  if (opt == NULL)
  {
    return TEX_ENONE;
  }
  free(opt);
  return TEX_ENONE;
}

tex_error_t package_add_option(tex_package *pkg, tex_package_option *opt)
{
  if (!pkg)
  {
    return TEX_EINVAL_PACKAGE;
  }

  if (!opt)
  {
    return TEX_EINVAL_PACKAGE_OPTION;
  }
  tex_package_option *cur = pkg->options;
  while (cur)
  {
    if (cur->name && opt->name && strcmp(cur->name, opt->name) == 0)
    {
      return TEX_ENONE;
    }
    cur = cur->next;
  }

  opt->next    = pkg->options;
  pkg->options = opt;

  return TEX_ENONE;
}

tex_error_t package_add_package(tex_package *pkg, tex_package *npkg)
{
  if (!pkg || !npkg)
  {
    return TEX_EINVAL_PACKAGE;
  }

  tex_package *cur = pkg;
  while (cur->next)
  {
    cur = cur->next;
  }
  cur->next  = npkg;
  npkg->next = NULL;

  return TEX_ENONE;
}

tex_error_t package_option_set_value(tex_package_option *opt, const char *value)
{
  if (!opt)
  {
    return TEX_EINVAL_PACKAGE_OPTION;
  }
  if (!value)
  {
    return TEX_ENULL_STRING;
  }
  if (opt->value)
  {
    free(opt->value);
  }

  opt->value = strdup(value);
  if (!opt->value)
  {
    return TEX_EFAIL_MEMALLOC;
  }

  return TEX_ENONE;
}

tex_error_t package_option_set_name(tex_package_option *opt, const char *name)
{
  if (!opt)
  {
    return TEX_EINVAL_PACKAGE_OPTION;
  }

  if (!name)
  {
    return TEX_ENULL_STRING;
  }
  if (opt->name)
  {
    free(opt->name);
  }

  opt->name = strdup(name);
  if (!opt->name)
  {
    return TEX_EFAIL_MEMALLOC;
  }

  return TEX_ENONE;
}

int package_write(const tex_package *pkg, char *buffer, size_t buffer_size)
{
  if (!pkg || !buffer)
  {
    return -1;
  }

  size_t written = 0;
  int    n       = 0;

  if (pkg->name)
  {
    if (pkg->options)
    {
      n = snprintf(buffer + written, buffer_size - written, "\\usepackage[");
      if (n < 0 || (size_t) n >= buffer_size - written)
        return -1;
      written += n;

      tex_package_option *cur = pkg->options;
      while (cur)
      {
        if (cur->name)
        {
          if (cur->value)
          {
            n = snprintf(buffer + written,
                         buffer_size - written,
                         "%s=%s",
                         cur->name,
                         cur->value);
          }
          else
          {
            n = snprintf(
                buffer + written, buffer_size - written, "%s", cur->name);
          }

          if (n < 0 || (size_t) n >= buffer_size - written)
            return -1;
          written += n;

          if (cur->next)
          {
            n = snprintf(buffer + written, buffer_size - written, ",");
            if (n < 0 || (size_t) n >= buffer_size - written)
              return -1;
            written += n;
          }
        }
        cur = cur->next;
      }

      // close options and add package name
      n = snprintf(
          buffer + written, buffer_size - written, "]{%s}\n", pkg->name);
    }
    else
    {
      // no options
      n = snprintf(buffer + written,
                   buffer_size - written,
                   "\\usepackage{%s}\n",
                   pkg->name);
    }

    if (n < 0 || (size_t) n >= buffer_size - written)
      return -1;
    written += n;
  }

  // sibling packages
  if (pkg->next)
  {
    int written_next =
        package_write(pkg->next, buffer + written, buffer_size - written);
    if (written_next < 0)
      return -1;
    written += written_next;
  }

  return (int) written;
}
