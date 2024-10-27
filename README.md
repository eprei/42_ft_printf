# ft_printf

This project is a custom implementation of the printf function in C, developed as part of the 42 School curriculum. The ft_printf function mimics the behavior of the original printf function from the C standard library, handling various format specifiers without implementing buffer management.

## About

The ft_printf project aims to recreate the functionality of the standard printf function, focusing on handling the following format specifiers:

- `%c` - Print a single character
- `%s` - Print a string
- `%p` - Print a pointer in hexadecimal format
- `%d` - Print a decimal (base 10) number
- `%i` - Print an integer in base 10
- `%u` - Print an unsigned decimal number
- `%x` - Print a number in hexadecimal with lowercase letters
- `%X` - Print a number in hexadecimal with uppercase letters
- `%%` - Print a percent sign

## Code Style - The Norm

This project follows the strict coding standards of 42 School, known as "The Norm". These standards enforce a specific code style that might seem restrictive compared to modern practices but serves educational purposes. Some key aspects include:

- Variables must be declared and initialized separately
- Each function must contain a maximum of 25 lines
- Each line must be at most 80 characters long
- A maximum of 4 parameters for each function
- Variable declarations must be at the start of a function
- Only while loops are allowed (no for, do while, etc.)
- No assignments inside conditionals
- No multiple assignments on a single line
- No comments inside functions

These restrictions mean that some IDE suggestions for "improvements" must be ignored to maintain compliance with the school's standards. While modern IDEs like CLion might suggest more efficient or cleaner ways to write certain parts of the code, adherence to The Norm takes precedence in this academic context.

## Technical Details

The project is structured into several files:
- `ft_printf.c` - Main function implementation
- `ft_printf.h` - Header file with function prototypes and includes
- `ft_printf_outils.c` - Helper functions
- `ft_printf_outils1.c` - Additional helper functions
- `ft_printf_outils2.c` - More helper functions

### Key Features

- Uses variadic functions to handle variable numbers of arguments
- Implements custom number conversion functions for different bases
- Handles null pointer cases appropriately
- Returns the number of characters printed

### Function Prototype

```c
int ft_printf(const char *str, ...);
```

## Building the Project

The project uses a Makefile with the following rules:

```bash
make        # Compile the project and create libftprintf.a
make clean  # Remove object files
make fclean # Remove object files and libftprintf.a
make re     # Rebuild the project
```

### Compilation Flags

The project is compiled with the following flags:
```bash
-Wall -Wextra -Werror
```

## Usage

After compilation, you'll have a static library `libftprintf.a`. To use it in your project:

1. Include the header in your code:
```c
#include "ft_printf.h"
```

2. Compile your program with the library:
```bash
gcc your_program.c libftprintf.a
```

3. Use ft_printf like you would use the standard printf:
```c
ft_printf("Hello %s! Number: %d\n", "world", 42);
```

## Example

```c
#include "ft_printf.h"

int main(void)
{
    char *str = "world";
    int num = 42;
    
    ft_printf("Hello %s!\n", str);
    ft_printf("Number: %d\n", num);
    ft_printf("Hexadecimal: %x\n", num);
    ft_printf("Pointer: %p\n", str);
    
    return (0);
}
```
