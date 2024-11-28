# FluxCode
[![Version](https://img.shields.io/badge/Version-v0.0.1-darkorange?style=flat)]()

FluxCode is a simple interpreted language designed to perform basic arithmetic operations, variable declarations, control structures, and functions. This language reads commands from a file with a .fx extension and executes them. FluxCode aims to be easy to learn and use, making it suitable for educational purposes and simple scripting tasks.

## Example

Create a file named example.fx with the following content:

```sh
start()
int x 10
int y 20
+ x y
printVar x
```

To run this program, compile and execute the interpreter:

```sh
g++ -o fluxcode main.cpp
./fluxcode example.lx
```

## Commands

Commands in FluxCode are case-sensitive and must be written as specified. Each command typically occupies a single line.

## Data Types
FluxCode supports the following data types:

_int_: Integer numbers (e.g., 10, -5)
_float_: Floating-point numbers (e.g., 3.14, -0.001)
_str_: Strings (e.g., "hello")
_chr_: Characters (e.g., 'a', 'Z')

Variables
Declaration
Variables are declared using the following syntax:

```sh
<data_type> <variable_name> <initial_value>
```
Examples
int count 10
float pi 3.14
str greeting "Hello, World!"
chr letter 'A'
Arithmetic Operations
FluxCode supports basic arithmetic operations. The result of the operation is printed to the console.

Addition
```sh
+ <operand1> <operand2>
```
Subtraction
```sh
- <operand1> <operand2>
```
Multiplication
```sh
* <operand1> <operand2>
```
Division
```sh
/ <operand1> <operand2>
```
Example
```sh
int a 5
int b 3
+ a b  // Output: 8
* a b  // Output: 15
```
Control Structures

## Conditionals
FluxCode supports basic conditional operations.

if <operand1> <operator> <operand2>
Operators include ==, !=, <, >, <=, and >=.

Example
int x 10
int y 20
if x < y
Loops
FluxCode supports simple loops.

loop <start> to <end>
Example
loop 1 to 5
Functions
FluxCode allows the definition and calling of user-defined functions.

Definition
define <function_name>
<commands>
end
Calling
call <function_name>
Example
define myFunc
int x 10
int y 5
+ x y
end

call myFunc
Input/Output
Printing
To print a string or variable, use the print command.

```sh
print <text>
printVar <variable_name>
```

## Example
```sh
pr Hello, World!
int x 42
printVar x
```

## Example Programs

Example 1: Basic Arithmetic
```sh
start()
int a 10
int b 20
+ a b
* a b
/ a b
- a b
```
Example 2: Conditional and Loop
```sh
start()
int x 10
int y 20
if x < y
pr x is less than y
```

## Importing Modules

FluxCode supports importing modules from external files. This allows you to reuse code across different scripts.

```sh
import <moduleName> from <moduleFile>
```

```sh
extern func <operator> <argument1> <argument2>
```

## FluxCode includes basic error handling for:

Invalid file extension
Missing initiator function (start())
Invalid commands
Division by zero
Error messages are printed to the console, and the program exits if a critical error is encountered.

This documentation provides a comprehensive guide to using FluxCode, covering its syntax, commands, and usage examples. By following this guide, users can start writing and executing their own FluxCode scripts.

## License

MIT

**Created by: Shujan Islam**