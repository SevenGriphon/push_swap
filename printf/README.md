*This activity has been created as part of the 42 curriculum by alnoviko*

## Description
This library contains a recreation of the function *printf* (with more limited conversions).
It includes following conventions:
- %c Prints a single character.
- %s Prints a string (as defined by the common C convention).
- %p Prints a void * pointer argument in hexadecimal format.
- %d Prints a decimal (base 10) number.
- %i Prints an integer in base 10.
- %u Prints an unsigned decimal (base 10) number.
- %x Prints a number in hexadecimal (base 16) lowercase format.
- %X Prints a number in hexadecimal (base 16) uppercase format.
- %% Prints a percent sign.

## Instructions
To use this library first compile it using makefile and then incude the ft_printf.h header in your file.  
__Makefile__:  
`make`/`make all`/`make libftprintf.a`: compile the library into libftprintf.a file.  
`make main`: compile the library with a main file. The file main.c should exist for this to function.  
`make clean`: remove all .o files.  
`make fclean`: remove all .o files, as well as remove library file.  
`make aclean`: compile the library and remove al .o files (the same as `make && make clean`).  

## Resources
A Description of printf function as well as a description of it's conventions:
[w3schools](https://www.w3schools.com/c/ref_stdio_printf.php)  
[man7](https://man7.org/linux/man-pages/man3/printf.3.html)  

## Algorithm
Since the function requires use of undefined number of parameters variadic arguments are used.
Variadic arguments allow function to take and use variable amount of arguments using the va_arg funtion to access a next argument.