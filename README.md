# Clang-Tidy MISRA support

This repository is intended for developing a clang-tidy MISRA plugin which
uses the implementation in [Clang-Tidy Automotive](https://github.com/PeterHallonmark/clang-tidy-automotive)
 will try to cover as much as possible of MISRA C 2023** and 
**MISRA C 2012**. 

## License

The repository follows LLVM's license structure to make it easier to upstream
changes to the LLVM project if and when that happens. :)

## Future Improvements

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
