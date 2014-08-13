# [Extension of the C++ standard library](http://kolyunya.github.io/xtd/namespacextd.html)

## Description

This library is an extension of the C++ standard library which contains general purpose, commonly used tools.

## Documentation
The project employs the [Doxygen](http://www.doxygen.org/) documentation generator. The HTML version of the documentation is hosted on [GitHub Pages](http://kolyunya.github.io/xtd/namespacextd.html).

## Structure

Library root directory contains `include`, `sources` and `sytem` sub-directories. The `include` directory contains library header files which are supposed to be included in you projects. The "sources" directory contains project sources with tests and build scripts. The `system` directory contains system files e.g. build scripts, Git hooks and Doxygen configuration.

Each library unit is contained in a separate directory. Each unit directory contains `build`, `sources` and `tests` sub-directories. The `build` directory contains GYP script which is used for building the unit. The `sources` directory contains unit source files. The `tests` directory contains unit tests.

## Usage

### Prerequisites.
  + C++11 compatible compiler.
  + [GYP](http://en.wikipedia.org/wiki/GYP_(software)) program.

### Library usage.
  + Set the `XTD_HOME` environment variable to the location of this library root directory.
  + Add path to the `include` directory to your project include paths.
  + Include required headers from the `include` directory into your source files.
  + Navigate to the `build` directory and generate library build script using `gyp --depth=.` command.
  + Compile the library using the build script generated on the previous step.
  + Compile you project linking to the static library compiled on the previous step.

## Testing

The project employs the [Google C++ Testing Framework](https://en.wikipedia.org/wiki/Google_C%2B%2B_Testing_Framework) for unit-testing. Each unit has a `tests` directory containing it's unit-tests. And every unit's build script contains a tests target. A tests target name has the following name convention: `%UNIT_NAME%_tests`.