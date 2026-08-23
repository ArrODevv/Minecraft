# Minecraft C++ Clone

A Minecraft clone written from scratch in C++.

## Disclaimer

This project is neither associated with nor approved by Mojang/Microsoft and is solely for entertainment
and learning purposes. All rights regarding Minecraft go to Mojang/Microsoft.
For legal discourse contact me at [Coming soon@email.com](mailto:todo@mail.com)!

## Contributing

Contributing is greatly appreciated, just open a pull request!

## Building

If you do not already have it install [CMake](https://cmake.org).
Then run this command to setup the build directory:

```bash
cmake -S . -B build # -S specifies the source directory ('.'' for the current dir)
                    # -B specifies the build directory (e.g. build, builddir, bin, ...)
```

If it succeedes you can then run this command to compile the binary:

```bash
#               \/ has to be the name you chose for '-B [dir]' in the command above
cmake --build build 
```
