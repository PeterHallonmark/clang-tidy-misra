# Clang-Tidy MISRA support

This repository is intended for developing clang-tidy checks for **MISRA
C 2023** and **MISRA C 2012**. The goal is to provide as many clang-tidy
checks as possible to help developers adhere to MISRA coding standards.

## Getting Started

To build clang-tidy with MISRA support, follow these steps:

### Prerequisites 

Clang 19 (or compatible version)

### Setup Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/PeterHallonmark/clang-tidy-misra.git
   cd clang-tidy-misra
   ```

2. Run the following setup scripts to build clang-tidy with MISRA support:
   ```bash
   ./setup.sh
   ./configure.sh
   ./build.sh
   ```

**Note:** The scripts will need to be adjusted to use a Docker container in
the future. This is part of the TODO list.

## Usage

To use the MISRA support in clang-tidy, enable the rules misra-c2023-* or misra-c2012-* when using clang-tidy.
The example below assumes the avoid-goto.c test file and the root directory of clang-tidy-misra.
   ```bash
   ./build/bin/clang-tidy --checks="misra-c2023-*" test/checkers/misra/c2023/avoid-goto.c -- 
   ```

See [clang-tidy](https://clang.llvm.org/extra/clang-tidy/) for more information.

## License

The repository follows LLVM's license structure to make it easier to upstream
changes to the LLVM project if and when that happens. :)

## Future Improvements

Move setup scripts to a Docker container for easier setup and environment
management.

## Contributing

Feel free to open issues or pull requests if you'd like to contribute to
this project. Contributions are always welcome!

**Note:** This project is not officially associated with MISRA or LLVM. It is
an independent initiative to develop clang-tidy checks for MISRA C 2023 and
MISRA C 2012. Any contributions or code changes are not officially endorsed
by MISRA or LLVM.

## Copyright Notice and MISRA Compliance

This project uses MISRA C 2023 and MISRA C 2012 metadata such as rule
IDs, rule categories and the programming language versions the rule applies 
to (required for verification purpose). However, the actual MISRA headings 
and text are not included in this repository as they are copyrighted by the 
MISRA organization.

The goal of this project is to provide MISRA-compliant checks without directly
reproducing copyrighted headings or texts. By using only metadata this
project aims to make it possible to contribute to the LLVM project in the 
future.
