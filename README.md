
# My Printf

A recode of the printf function from the C library according to the C99 standard.


## Usage/Examples
Copile the lib using the Makefile.
```c
#include "include/my.h"

int main() {
  my_printf(const char *format, ...);
}
```


## Field Width and Precision

`Field Width` specifies the minimum number of characters to be printed for a given output. If the output is shorter than the specified width, it will be padded with spaces (or zeros if the `0` flag is used) to ensure it occupies the specified width.

`Precision` controls the number of digits displayed after the decimal point for floating-point numbers, or the maximum number of characters to be printed from a string. It is introduced by a period (`.`) followed by a number (`n`), indicating how much precision should be applied to the output.

## Flag Characters

| Flag | Description                                      |
|------|--------------------------------------------------|
| `-`  | Left-justifies the output within the specified width. |
| `+`  | Forces the output to include a sign (+ or -) for numeric values. |
| `0`  | Pads the output with leading zeros instead of spaces. |
| `" "`  | Adds a space before positive numbers to indicate sign. |

## Length Modifiers

| Flag | Description                                    |
|------|------------------------------------------------|
| `l`  | Specifies that the argument is a `long int`.  |
| `ll` | Specifies that the argument is a `long long int`. |
| `h`  | Specifies that the argument is a `short int`. |
| `hh` | Specifies that the argument is a `char`.      |

## Flags


| Flag | Description                                    |
|------|------------------------------------------------|
| `%d` | Prints an integer in decimal format.          |
| `%i` | Prints an integer in decimal format (similar to `%d`). |
| `%f` | Prints a floating-point number.                |
| `%s` | Prints a string of characters.                 |
| `%c` | Prints a single character.                     |
| `%x` | Prints a number in lowercase hexadecimal format. |
| `%X` | Prints a number in uppercase hexadecimal format. |
| `%o` | Prints a number in octal format.               |
| `%u` | Prints an unsigned integer.                     |
| `%p` | Prints a pointer in hexadecimal format.        |
| `%%` | Prints a literal percentage symbol.            |
| `%m` | Prints the last error message (errno).        |
| `%b` | Prints a number in binary format.              |



## Running Tests

To run tests, run the following command

```bash
  make unit_tests
  make tests_run
```


## Bonuses

The project includes several bonuses that enhance its functionality:

- **`%m` Flag**: This flag allows the `my_printf` function to print the last error message based on the value of `errno`. It provides users with immediate feedback on errors that may occur during program execution.

- **`%b` Flag**: This flag enables the printing of numbers in binary format, offering a unique way to represent data that is often useful in debugging and low-level programming.

- **`my_sprintf` Function**: This function mimics the behavior of `sprintf`, supporting all the flags and features of `my_printf`. This allows for formatted string generation directly into a buffer, making it versatile for various applications.

## Authors

- [@Geoffrey](https://github.com/Jean-FrancoisVilacorta)
- [@The Abrisbus](https://github.com/theabrisbus)

## Used By

This project is used by the following companies:

- by me
- and my friend Paco
