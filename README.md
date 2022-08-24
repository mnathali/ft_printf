# ft_printf

ft_printf is a function that behaves like original printf of C-library.
Makefile creates static library and add this function to libft.

ft_printf can take not defined amount of parameters as original printf do. The stdarg.h is used to this purpose.
ft_printf uses write function to print in stdout and like original printf return number of printed symbols.
You can use ft_printf the same way like printf or use them together.
ft_printf do following conversions:

• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.

Bonus part can handle any combination of the following flags: ’-0.’ and the field minimum width.
Moreover managed all the following flags: ’#’, ’ ’, ’+’.
