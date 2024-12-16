# Mini-Project Script

## Introduction
I will be talking about a small C compiler, named Chibicc.
For those unfamiliar, the C programming language is a language that is
compiled into an executable that your computer can run. Thus, a
compiler infrastructure is needed. I will first quickly go over very
generally how a typical compiler works. Most commonly used C compilers
(at least for x86_64) include GCC and Clang/LLVM, which you may be
familiar with.

From a high-level view, the first step in this process is the
preprocessor. This expands the code in the form of expanding macros,
replacing `#include` directives with the content from the included
file(s), and resolve preprocessor conditional directives, like `#ifdef`
that the C language provides.

The next step is referred to as compilation. This converts the output
of the preprocessor to architecture specific assembly code. This
assembly code that is generated is closer to something readable by a
CPU, rather than a human. It includes mnemonic symbols like `MOV` &
`ADD` that directly represent CPU operations.

The third step is assembling. An assembly instruction generally
consists of a opcode, which correlates to a binary sequence known to
the CPU. For example, the `PUSH` instruction on x86 maps to `0b0110`.
Opcodes are determined the CPU's ISA, however I digress. Following this
opcode is generally an operand, like a memory address. Generally, this
stage will produce an object file (`*.o`) that contains machine-level
code representing the original code's functions. This is not quite an
executable file.

The final stage of compilation is linking. The linker merges all the
object code from the previous stage into a single one. This stage is
far too complex to discuss here in detail, however this step will
magically output a executable file you can run.

In most common compiler infrastructures, these stages are delegated to
individual programs that are actually separate from the "compiler".
I.e. your Linux system has a standalone `cpp` program (preprocessor),
`as` program (assembler), and `ld` program (linker) that can all be
manually invoked to perform the familiar step of `cc foo.c`, where
this is all done for you (and for good reason).

The project being discussed, Chibicc, provides a preprocessor and
compiler. Assembling and linking is handled by the aforementioned
programs. Now, a bit more about Chibicc; it supports almost all
mandatory features of C11, as well as support for many things often not
contained in small compilers like floating point numbers, variable
length arrays, functions that return `struct`'s as values, and more.
Chibicc does not support things like complex numbers, inline assembly,
or optimisation for the sake of simplicity.

## Internal Overview
Chibicc consists of the following stages:

1. **Tokeniser**: takes a string as an input, break it into a list of
tokens, and returns this.
2. **Preprocessor**: takes a list of tokens as an input, and outputs a
new list of macro-expanded tokens. It interprets preprocessor
directives while also expanding macros.
3. **Parser**: recursively descends and constructs abstract syntax
trees from the output of the preprocessor. It also adds a type to each
AST node.
4. **Code Generator**: emits an assembly text for given AST nodes.

An interesting design aspect of Chibicc is the fact that allocated
memory is not freed as needed. This was a fairly odd and new concept
to me. After looking into this, the D programming languages' compiler
also does this. Compilers are short lived programs and should generally
try to execute as quickly as possible. This means allocating memory
without freeing until the entire process is done. This is why there are
no calls to `free()` in Chibicc.

## Examples
I have written five example C programs that live in the `examples/`
directory. I feel these demonstrate Chibicc's capabilities quite well.
1. An obligatory hello world program
2. Demonstrates inline Assembly capabilities
3. Demonstrates `struct` capabilities
4. Demonstrates multithreading capabilities
5. Demonstrates aligned and packed `struct`'s
