
```markdown
# TOY Language

Welcome to the TOY Language repository. This repository contains the implementation of the TOY language, a simple educational programming language designed to demonstrate compiler development using LLVM.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
- [Building the TOY Compiler](#building-the-toy-compiler)
- [Running TOY Programs](#running-toy-programs)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## Introduction

TOY is a simplified programming language created for educational purposes. It is designed to help learners understand the fundamental concepts of compiler construction and how to utilize the LLVM framework for generating intermediate representation (IR) and performing optimizations.

## Features

- **Variables**: Declaration and assignment of variables.
- **Arithmetic Operations**: Basic arithmetic operations (addition, subtraction, multiplication, division).
- **Functions**: Definition and invocation of functions.
- **Control Flow**: Simple control flow constructs like conditional statements and loops.

## Getting Started

To get started with TOY, you need to clone this repository to your local machine:

```sh
git clone https://github.com/yourusername/TOY.git
cd TOY
```

## Building the TOY Compiler

To build the TOY compiler, you need to have LLVM and CMake installed. Follow these steps:

1. Install LLVM (version 3.8 or later) and CMake (version 3.1 or later).

2. Build the TOY compiler:

    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

## Running TOY Programs

After building the TOY compiler, you can compile and run TOY programs. Here is an example:

1. Write a TOY program (e.g., `example.toy`):

    ```toy
    def foo(a, b)
      var c = a + b;
      return c;

    var result = foo(5.0, 3.0);
    ```

2. Compile the TOY program:

    ```sh
    ./toy example.toy
    ```

## Examples

You can find example TOY programs in the `examples` directory. These examples cover various language features and can be used to test the compiler.



## License

This repository is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.
```

