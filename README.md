# Clang-Tidy MISRA support

This repository is intended for developing a Clang-Tidy MISRA plugin which
uses the implementation in [Clang-Tidy Automotive](https://github.com/PeterHallonmark/clang-tidy-automotive)
and maps the implementation towards **MISRA C:2023** and **MISRA C:2012**
with a compliance matrix. 

The idea is to have the major implementation in the Clang-Tidy Automotive 
plugin and the mapping against the correct rule in the Clang-Tidy MISRA
repo. 

**Note**: Official MISRA documents must be purchased and are protected
by copyright. This project is independent and is not affiliated with or
endorsed by the MISRA Consortium.

## License

The repository follows LLVM's license structure for the source code and 
tries to follow MISRA copyright even through I have not contacted MISRA 
about this repo since it is still not functioning in its early stages. 

When there is something working I will contact them about this repo. :)

## Contributing

Feel free to open issues or pull requests if you'd like to contribute to
this project. Contributions are always welcome!

**Note:** This project is not officially associated with MISRA or LLVM. It is
an independent initiative to develop clang-tidy checks for MISRA C 2023 and
MISRA C 2012. Any contributions or code changes are not officially endorsed
by MISRA or LLVM.
