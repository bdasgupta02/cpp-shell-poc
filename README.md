# Simple C++ Shell without JIT compilation
- Just uses C++ STL (as opposed to cling)
- Simulates a REPL under the hood to behave like an interactive shell
- Uses the GNU C++ compiler (G++)

## Why?
- Tool to explore and prototype C++ code quickly
- Helpful in learning C++ through quick evaluation and feedback
- Not many options available that use pure C++
- Seemed like a really fun challenge to do it without JIT

## Improvements in progress
- Detecting function declarations
- Concurrency to compensate for compilation times (and other optimizations)
- Error detection and auto-undo
- Dedicated REPL printer for printing variable assignments, removing old print statements
- `/help` function

## Key improvements
- Threading compilation for better responsiveness
- Ability to retain the source output file

## Custom commands (prefixed with /)
- `/refresh`
- `/undo`
- `/exit`

## Sample usage
Just run the `shell.cpp` file
```cpp
cpp-shell$ g++ shell.cpp -o shell.out && ./shell.out

Welcome to the C++ Shell

>>> int a = 10

>>> int b = 20

>>> #include <iostream>

>>> std::cout << a + b << std::endl
30

>>> exit 
```
