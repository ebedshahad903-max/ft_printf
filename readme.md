*This project has been created as part of the 42 curriculum by ebedshahad903.*

<div align="center">

# ft_printf
A custom re‑implementation of the standard C `printf` function.

</div>

---

## Description
`ft_printf` is a custom implementation of the standard C library function `printf()`.  
The goal of this project is to understand how formatted output works internally, including:

- Parsing format strings  
- Handling variadic arguments  
- Implementing conversions such as characters, strings, integers, pointers, hexadecimal, and unsigned integers  
- Managing output through low‑level system calls (`write()`)

This project provides a foundational understanding of how complex standard library functions are built, while reinforcing skills in C programming, memory handling, and modular design.

---

## Features

| Conversion | Description |
|-----------|-------------|
| `%c` | Print a single character |
| `%s` | Print a string |
| `%d` / `%i` | Print a signed integer |
| `%u` | Print an unsigned integer |
| `%x` / `%X` | Print a hexadecimal number (lowercase/uppercase) |
| `%p` | Print a pointer address |
| `%%` | Print a literal `%` |

---

## Instructions

### Compilation
A Makefile is provided with the following rules:

