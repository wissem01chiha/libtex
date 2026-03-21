# SPDX-FileCopyrightText: Copyright (c) Wissem Chiha
# SPDX-License-Identifier: BSD 2-Clause
project('texio',
 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

  inc = include_directories('include', 'include/texio')

  sources = [
  'src/figure.c',
  'src/version.c',
  'src/document.c',
  'src/section.c',
  'src/environment.c',
  'src/theorem.c',
  'src/book.c',
  'src/texutil.c',
  'src/equation.c',
]

texio = library('texio', sources,
  include_directories : inc,
  install : true
)

test_sources = [
  'test/document_fs_write_test.c',
  'test/getusername_test.c',
]

foreach t : test_sources
  testname = t.split('/')[-1].split('.')[0]
  exe = executable(testname, t,
    include_directories : inc,
    link_with : texio
  )
  test(testname, exe)
endforeach
