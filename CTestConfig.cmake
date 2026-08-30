# SPDX-FileCopyrightText: 2026 Wissem Chiha <chihawissem08@gmail.com>
# SPDX-License-Identifier: BSD-2-Clause

set(CTEST_PROJECT_NAME libtex)
set(CTEST_NIGHTLY_START_TIME 00:00:00)

if(CMAKE_VERSION VERSION_GREATER 3.14)
  set(CTEST_SUBMIT_URL https://my.cdash.org/submit.php?project=libtex)
else()
  set(CTEST_DROP_METHOD "https")
  set(CTEST_DROP_SITE "my.cdash.org")
  set(CTEST_DROP_LOCATION "/submit.php?project=libtex")
endif()

set(CTEST_DROP_SITE_CDASH TRUE)
