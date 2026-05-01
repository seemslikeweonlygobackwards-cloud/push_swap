*This project has been created as part of the 42 curriculum by mavanesy.*

# ft_pintf

A lightweight reimplementation of the C standard library printf function. The function is compared with the original one.

## Description

Function handles the following conversions: cspdiuxX%

• % c Prints a single character.
• % s Prints a string (as defined by the common C convention).
• % p The void * pointer argument has to be printed in hexadecimal format.
• % d Prints a decimal (base 10) number.
• % i Prints an integer in base 10.
• % u Prints an unsigned decimal (base 10) number.
• % x Prints a number in hexadecimal (base 16) lowercase format.
• % X Prints a number in hexadecimal (base 16) uppercase format.
• % % Prints a percent sign

**ft_printf** 

**The goal** of this project is to create your very own printf function and understand how variadic functions work in C using va_list, va_start, va_arg, and va_end. You also develop a solid grasp of format string parsing, type promotion rules, and recursive digit extraction for integer and hexadecimal conversion. Rather than relying on high-level library functions, all output is handled through the low-level write syscall, giving you direct experience with system-level I/O. The project also challenges you to think carefully about edge cases such as INT_MIN, null strings, and pointer representation, while keeping your code clean and well-structured across multiple files.

## Instructions

To compile the library use the make command

This will create:
 
libftprintf.a

Available Makefile Rules
make        -> Compile the library
make clean  -> Remove object files
make fclean -> Remove object files and library
make re     -> Recompile everything

Files are compiled with flags -Wall -Wextra -Werror

## Resources

-caffeinated and tired brain
-peer help and motivation, and special thanks the Arpen for helping me with handling some of the edge cases.
-artificial intelligence nerves trying to explain variadic functions with cats in the boxes
-the endless ability of human mind of making errors
-general explanations of printf functions 
-42 Intranet subject for Printf
-Painkillers
-Prayers

MAY THE FORCE LEAD US
