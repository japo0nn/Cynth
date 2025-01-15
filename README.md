# Cynth compiler

**Cynth Compiler** is a compiler for the new Cynth programming language, written in ***C***. Cynth is designed for high performance and simplicity, with a focus on low-level programming concepts. The compiler features a one-pass compilation process, a flexible type system, and supports arrays, hash tables, pointers, and user-defined structures. It generates optimized machine or assembly code and has minimal external dependencies, making it portable across platforms. Cynth's syntax is straightforward, making it suitable for both beginners and experienced developers. The compiler uses custom lexers, recursive parsing, and efficient code generation.

## Installation

1. First you need to install required packages:
    - CMake
    - Clang
    - Git

2. Clone this repo:
    ```
    git clone https://github.com/japo0nn/Cynth.git
    cd Cynth
    ```
    or 
    ```
    git clone git@github.com:japo0nn/Cynth.git
    cd Cynth
    ```


## Build and run

- Using build.sh script
    Run script build.sh.
    ```
    ./build.sh
    ```

- Manually
    ```
    cd ./build/
    cmake ..
    make
    ./CynthCompiler
    ```
