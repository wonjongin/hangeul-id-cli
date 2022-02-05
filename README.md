# Hangeul ID CLI

CLI app using [Hangeul ID library](https://github.com/wonjongin/hangeul-id-cpp)!

## Usage

```text
$ hangeul-id-cli --help

Hangeul id cli app
Usage: hangeul-id-cli [OPTIONS] SUBCOMMAND

Options:
  -h,--help                   Print this help message and exit
  -v,--version                Display program version information and exit

Subcommands:
  uuid                        Generate Hangeul id with UUID v4
  convert                     Convert Hangeul ID

```

## Install Binary

Download [Release](https://github.com/wonjongin/hangeul-id-cli/releases) file and copy in directory registered in PATH.

## Build

### Pre-requirement

- [cmake](https://cmake.org)
- c++ compiler (like clang, gcc)
- [make](https://www.gnu.org/software/make/) or [ninja](https://github.com/ninja-build/ninja)
- [hangeul-id-cpp](https://github.com/wonjongin/hangeul-id-cpp)
- [vcpkg](https://github.com/microsoft/vcpkg) (optional)

### Build and Install

1. We manage dependencies with [vcpkg](https://github.com/microsoft/vcpkg). Please set up vcpkg.
2. Hangeul ID library is required. Please set up [hangeul-id-cpp](https://github.com/wonjongin/hangeul-id-cpp).
3. Clone this project and go to project directory.
4. `vcpkg install` to install dependencies with vcpkg
5. `export VCPKG_ROOT=/path/to/vcpkg`
6. Ninja -> 5.i, Make -> 5.ii

    1. Ninja
        ```shell
       cmake \
       -G Ninja \
       -B build \
       -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake 
       
       ninja -C build
       
       ninja -C build install
       ```
    2. Make
       ```shell
       cmake \
       -G "Unix Makefiles" \
       -B build \
       -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake 
       
       make -C build
       
       make -C build install
       ```
