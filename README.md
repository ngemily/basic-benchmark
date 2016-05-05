A Simple Testbench Suite
========================

About
-----

This testbench is designed to exercise various aspects of an ISA.

Commands
--------

Overview of LLVM commands for compiling executables, emitting intermediate
representations, and producing graphs.

Compile target:

    clang -o <main> <main.c>

Emit assembly:

    clang -S <main.c>

Emit llvm IR:

    clang -S -emit-llvm <main.c>

Produce graphs:

    opt -dot-regions <main.ll>
        # produces reg.<func>.dot for each function in main.ll
    dot -Tps -O <reg.main.dot>
    convert <reg.main.dot.ps> <main.png>

For a list of all the graphing options: `opt --help | grep dot`
