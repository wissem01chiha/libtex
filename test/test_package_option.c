// SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
// SPDX-License-Identifier: BSD-2-Clause

#include "tex.h"
#include <stdio.h>
#include <check.h>
#include <stdlib.h>

START_TEST(test_package_option_create_delete)
{
  tex_error_t         err = TEX_ENONE;
  tex_package_option *c   = package_option_create(&err);
  ck_assert_ptr_nonnull(c);
  ck_assert_int_eq(err, TEX_ENONE);

  tex_error_t derr = package_option_delete(c);
  ck_assert_int_eq(derr, TEX_ENONE);
}
END_TEST

Suite *list_suite(void)
{
  Suite *s       = suite_create("test_package_option");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_package_option_create_delete);

  suite_add_tcase(s, tc_core);
  return s;
}

int main(void)
{
  int      number_failed;
  Suite   *s  = list_suite();
  SRunner *sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}