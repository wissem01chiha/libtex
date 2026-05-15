project('libtex', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

  inc = include_directories('include', 'include/tex')

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

libtex = library('libtex', sources,
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
    link_with : autotex
  )
  test(testname, exe)
endforeach
