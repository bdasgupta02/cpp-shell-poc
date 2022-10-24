# Simple C++ Shell without JIT compilation
- Just uses C++ STL (as opposed to cling)
- Simulates a REPL under the hood to behave like an interactive shell
- Uses the GNU C++ compiler (G++)

## Why?
- Tool to explore and prototype C++ code quickly
- Helpful in learning C++ through quick evaluation and feedback
- Not many options available that use pure C++
- Aims to be geared specifically towards quick testing (more accurate print interpretation) than other options
- This seemed fun

## Improvements in progress
- Detecting function declarations
- Concurrency to compensate for compilation times (and other optimizations)
- Error detection and auto-undo
- Dedicated REPL printer for printing variable assignments, removing old print statements
- `help` function

## Custom commands
- `refresh`
- `undo`
- `exit`

## Sample usage
```cpp
/cpp-shell$ g++ shell.cpp -o shell.out && ./shell.out

Welcome to the C++ Shell

>>> int a = 10

>>> int b = 20

>>> #include <iostream>

>>> std::cout << a + b << std::endl
30

>>> exit 
```
