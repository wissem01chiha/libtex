<p align="center">
  <img src="docs/src/image/banner.png" alt="libtex" height="200"/>
</p>

[![Ubuntu](https://github.com/wissem01chiha/libtex/actions/workflows/ubuntu.yml/badge.svg)](https://github.com/wissem01chiha/libtex/actions/workflows/ubuntu.yml)
[![MacOS](https://github.com/wissem01chiha/libtex/actions/workflows/macos.yml/badge.svg)](https://github.com/wissem01chiha/libtex/actions/workflows/macos.yml)
[![Windows](https://github.com/wissem01chiha/libtex/actions/workflows/windows.yml/badge.svg)](https://github.com/wissem01chiha/libtex/actions/workflows/windows.yml)
[![codecov](https://codecov.io/gh/wissem01chiha/libtex/branch/develop/graph/badge.svg?token=DAKZZFFS9N)](https://codecov.io/gh/wissem01chiha/libtex)
[![CodeFactor](https://www.codefactor.io/repository/github/wissem01chiha/libtex/badge)](https://www.codefactor.io/repository/github/wissem01chiha/libtex)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/2534ce683b5145b4baec68209f620c48)](https://app.codacy.com/gh/wissem01chiha/libtex/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade)
![GitHub License](https://img.shields.io/github/license/wissem01chiha/libtex)
[![pre-commit.ci status](https://results.pre-commit.ci/badge/github/wissem01chiha/libtex/master.svg)](https://results.pre-commit.ci/latest/github/wissem01chiha/libtex/master)

## Overview

libtex is a C99 library for writing [LaTeX](https://www.latex-project.org/) `.tex` files, designed to be a small utility library for C or C++ projects needing a standardized way to write scientific reports with minimal code. libtex aims to provide features that simplify document formatting and integration of external sources into the document. However, this depends on community contributions and may progress slowly, as it is currently maintained with low priority.

## Feature highlights

- Convert Json files directly into LaTeX list environments.
- Retrieve author, date, and location details to save editing time.
- Generate LaTeX‑compatible tables from row data or [csv](https://en.wikipedia.org/wiki/Comma-separated_values) input.
- Provide built‑in plotting and advanced figure handling for LaTeX documents.
- Create Latex‑compatible [Tikz](https://tikz.dev/editor/) graphs directly from row input data.

## Versioning

libtex follows the [semantic versioning](http://semver.org/) scheme. The API change and backwards compatibility rules are those indicated by SemVer. The library will keep a stable ABI across major releases.

## Documentation

Located in the [docs](docs/) subdirectory. We use the [Sphinx](https://www.sphinx-doc.org/) framework.

To build documentation as HTML run:

```bash
make html
```

This may require [Sphinx](https://www.sphinx-doc.org/en/master/index.html) installed on your system:

```bash
pip install -U sphinx
```

> > [!NOTE]  
> Windows users need to use `make.bat` instead of plain `make`.

### Official documentation

## Supported Platforms

| **System** | **Supported Versions** | **Supported Compilers** | **Notes** |
|------------|-------------------------|--------------------------|-----------|
| **Lubuntu (Linux)** | 20.04 LTS, 22.04 LTS | GCC 9–11, Clang 12–14 | GCC is default; Clang optional for cross-platform consistency |
| **MacOS** | 12 (Monterey), 13 (Ventura), 14 (Sonoma) | Clang (Xcode toolchain) | Apple ships Clang by default; GCC rarely used |
| **Windows** | Windows 10, Windows 11 | MSVC 2019–2022, Clang (LLVM for Windows) | MSVC is standard; Clang support recently added in CI |


Other platforms or compilers have not yet been tested. Please open an issue on [GitHub Issues](https://github.com/wissem01chiha/libtex/issues) for any suspected bugs.

## Downloading

libtex can be downloaded from the [GitHub repository](https://github.com/wissem01chiha/libtex)

For quick integration, the easiest way is to download the precompiled installation package for your platform, available on the release page.

## Build Instructions

libtex uses [cmake](https://cmake.org/) as its main build system.Support for other build systems or workflows may be subject to discussion.

To build libtex from source you need a version of CMake (3.12–3.31) and [Git]().

###  Configure Options

| Option                | Description                                               | Default | Supported Since |
|------------------------|-----------------------------------------------------------|---------|-----------------|
| LIBTEX_BUILD_SHARED    | Build libtex as a shared library                          | OFF     |   0.1.0         |
| LIBTEX_BUILD_TOOLS     | Build command-line tools distributed with libtex          | ON      |   0.1.0         |
| LIBTEX_BUILD_TESTS     | Build unit and integration tests                          | ON      |   0.1.0         |
| LIBTEX_INSTALL         | Enable installation targets                               | OFF     |    0.1.0        |
| LIBTEX_COVER           | Enable code coverage reporting (GCC/Clang)                | OFF     |    0.1.0        |
| LIBTEX_ASAN            | Enable AddressSanitizer (ASan) for runtime checks         | ON      |    0.1.0        |

### Running tests

In order to run all unit and regression libtex tests, using [CTest](https://cmake.org/cmake/help/latest/manual/ctest.1.html)

```bash
ctest -C Release --output-on-failure --max-width 120
```

## Contributing

See [Contributing](.github/CONTRIBUTING.md) guide for more informations.

## Licensing

libtex source code is licensed under the BSD 2-Clause License. Check the [LICENSE](LICENSE.md)
file for full terms.

Additional copyright and licensing information for non‑code materials is maintained in the [COPYRIGHTS](./COPYRIGHTS.md) file