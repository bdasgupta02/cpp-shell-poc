# Simple C++ Shell without JIT
- Just uses C++ STL
- Simulates a REPL under the hood to behave like a shell
- Uses the GNU C++ compiler (G++)

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
