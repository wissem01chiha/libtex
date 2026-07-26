// SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
// SPDX-License-Identifier: BSD-2-Clause

#include "tex.h"
#include <stdio.h>
#include <check.h>

START_TEST(test_document_section_write)
{
  tex_error_t   err = TEX_ENONE;
  tex_document *doc = document_create(&err);
  document_set_title(doc, "test-document-with-section");

  //create some sections with subsections 
  tex_section *sec = section_create(&err);
  sec->title = tex_strdup("section1");
  sec->content = tex_strdup("Zorim eptrum falix nodera, quistal venor daplum.");

  tex_section *subsec = section_create(&err);
  subsec->level = Subsection;
  subsec->title = tex_strdup("subsection1.1");
  subsec->content = tex_strdup("Fexor mitralo sunep, dravix coltur anem.");

  sec->subsection = subsec;

  // add the section to the doc
  doc->section = sec;

  const char *filename  = "document_with_section_write.tex";
  ck_assert_int_eq(document_fs_write(doc, filename), TEX_ENONE);


  document_delete(doc);
}
END_TEST


Suite *tex_suite(void)
{
  Suite *s       = suite_create("test-document");
  TCase *tc_core = tcase_create("core");
  tcase_add_test(tc_core, test_document_section_write);
  suite_add_tcase(s, tc_core);

  return s;
}

int main(void)
{
  int      number_failed;
  Suite   *s  = tex_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}