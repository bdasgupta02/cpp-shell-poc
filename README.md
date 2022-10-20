# Simple C++ Shell without LLVM/JIT
- Simulates a REPL under the hood to behave like a shell.
- Based on G++.

## Improvements in progress
- Detecting function declarations.
- Concurrency to compensate for compilation times.
- Smart output addition and removal for REPL loops.

## Custom commands
- `refresh`
- `undo`
- `exit`

## Sample usage
```cpp
/cpp-shell$ g++ shell.cpp -o shell.exe
/cpp-shell$ ./shell.exe
Welcome to the C++ Shell

>>> int a = 10;

>>> int b = 20;

>>> #include <iostream>

>>> std::cout << a + b << std::endl;
30

>>> exit 
```
