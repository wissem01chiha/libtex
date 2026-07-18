/*
 * SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

// utility helper functions definition.

#pragma once

#include "texerrno.h"

#ifdef __cplusplus
extern "C"
{
#endif
  // Get the username of the user running the program.
  const char *tex_get_username(tex_error_t *err);

  // Get the current system date formatted as YYYY-MM-DD (e.g., "2026-07-18").
  const char *tex_get_date(tex_error_t *err);

  // Get the current local time. eg  HH:MM:SS
  const char *tex_get_time(tex_error_t *err);

#ifdef __cplusplus
};
#endif
