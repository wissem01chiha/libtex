/*
 * SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "tex.h"
#include <stdio.h>
#include <check.h>

START_TEST(test_document_add_fs_content)
{
    tex_error_t err = TEX_ENONE;
    tex_document *doc = document_create(&err);

 
    document_delete(doc);
}
END_TEST

Suite *tex_suite(void)
{
    Suite *s = suite_create("test-document");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_document_add_fs_content);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s = tex_suite();
    SRunner *sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}