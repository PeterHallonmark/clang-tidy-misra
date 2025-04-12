# clang-tidy MISRA Checks

This repository is intended for developing clang-tidy checks for **MISRA C 2023** and **MISRA C 2012**. The goal is to provide as many clang-tidy checks as possible to help developers adhere to MISRA coding standards.

## Getting Started

To build clang-tidy with MISRA support, follow these steps:

### Prerequisites
- Clang 19 (or compatible version)

### Setup Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/PeterHallonmark/clang-tidy-misra.git
   cd clang-tidy-misra

2. Run the following setup scripts to build clang-tidy with MISRA support:
   ./setup.sh
   ./configure.sh
   ./build.sh

   Note: The scripts will need to be adjusted to use a Docker container in the future. This is part of the TODO list.

## License

The repository follows LLVM's license structure to make it easier to upstream changes to the LLVM project if and when that happens. :)

## Future Improvements

Move setup scripts to a Docker container for easier setup and environment management.

## Contributing

Feel free to open issues or pull requests if you'd like to contribute to this project. Contributions are always welcome!

**Note:** This project is not officially associated with MISRA or LLVM. It is an independent initiative to develop clang-tidy checks for MISRA C 2023 and MISRA C 2012. Any contributions or code changes are not officially endorsed by MISRA or LLVM.
