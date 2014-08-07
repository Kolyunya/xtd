#XTD – extension of the C++ standard library

##Description

This library is an extension of the C++ standard library which contains general purpose, commonly used tools.


##Structure

Library root directory contains `include`, `src` and `sytem` sub-directories. The `include` directory contains library header files which are supposed to be included in projects. "Src" directory contains project sources with tests and building scripts. The `system` directory contains system files used mostly for
library building.

Each library unit is contained in a separate directory. Each unit directory contains `build`, `src` and `tests` sub-directories. The `build` directory contains GYP script which is used for building the unit. The `src` directory contains unit source files. The `tests` directory contains unit tests.

##Usage

* Prerequisites.
  + C++11 compatible compiler.
* Using the library.
  + Add path to library `include` directory to your project.
  + Include required unit headers from library `include` directory into your project.
  + Compile your project.

##Documentation
The project employs the [Doxygen](http://www.doxygen.org/) documentation generator. The documentation is available in the `documentation` directory. The HTML version of the library documentation is hosted on GitHub Pages of the project [here](http://kolyunya.github.io/xtd/).

##Testing

* Prerequisites.
  + C++11 compatible compiler supported by GYP.
  + GYP build system.
* Testing library.
  + Set `XTD_HOME` environment variable to the location of this library. Home directory is one with `src`, `include`, `system` and others sub-directories
  + Set `GYP_GENERATORS` environment variable to value(s) corresponding you compiler(s). Options should be separated by a comma. Available options are `make`, `msvs`, `ninja`, `scons`, `eclipse` and others.
  + Execute library GYP script by calling `gyp --depth=. %LIBRARY_ROOT%/build/generator.gyp` command. Selected build scripts would be produced in the "build" directory.
  + Run build script(s) from `%LIBRARY_ROOT%/build/` directory.
  + Compile test program using selected environment.
  + Run test program.