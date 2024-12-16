# Principles of Programming and Programming Languages
# Mini-Project: chibicc

## Description
This project will talk about [chibicc](https://github.com/rui314/chibicc),
a functional C compiler written in less than 10,000 lines of code. I
aim to roughly explain the program's structure, a overview of its
internals (at least from a high level), demonstrate some examples using
chibicc, and how it compares to other compilers like GCC or LLVM/Clang.

Simply reviewing this project and its functionality will sufficiently
relate it to the topics covered in CSCI3155, as a compiler is very
much so the next step to the content covered in this class.

## Repository Organization
```shell
.
├── chibicc        #  chibicc sources provided as a submodule
├── examples       #  example programs that chibicc can run
│   ├──  01.c
│   ├──  02.c
│   ├──  03.c
│   ├──  04.c
│   ├──  05.c
│   └── Makefile   #  a makefile to build afforementioned programs
├── readme.md
├── recording.mp4  #  screen recording of demonstration
├── script.md      #  rough verbal script used in recording
└── slides.pdf     #  slides used during recording
```

## Building and Testing Instructions

### Dependencies
- `cc` (GCC or other C compiler)
- `make` (GNU Make or other Make program)

### Building chibicc
Ensure this repository was cloned with submodules.

```shell
$ cd chibicc
$ make
```

If successful, there should be a `chibicc` executable in the working
directory:
```shell
$ file chibicc
chibicc: ELF 64-bit LSB pie executable, x86-64
```

This can now be used to compile the sample C programs in the `examples`
directory (add to `$PATH` or run with appropriate path):
```shell
$ chibicc 01.c -o 01.bin
# or the make equivalent
$ make 01
$ ./01.bin
Hello world!
# or compile and run all tests
$ make
$ make test
```

## Presentation
- YouTube: https://youtu.be/TODO
- Script: [script.md](script.md)
- Recording: [recording.mp4](recording.mp4)
- Slides: [slides.pdf](slides.pdf) & [slides.pptx](slides.pptx)

## References
[1] https://stackoverflow.com/questions/77108297/breaking-down-the-c-compilation-process-into-preprocessing-compilation-assembl
[2] https://www.drdobbs.com/cpp/increasing-compiler-speed-by-over-75/240158941
[3] https://www.phaedsys.com/standards/compilervalidation/cvrdata/CV005_ChoosingATtestSuite.pdf
