# 42HN_ft_printf
Summary:

This project is pretty straightforward, I have to recode printf function and discover variadic arguments.

Foreword:

The versatility of the printf function in C represents a great exercise in programming for us.
This project is of moderate difficulty. The key to a successful ft_printf is a well-structured and good extensible code.

Links:

Wikipedia about printf function: https://en.wikipedia.org/wiki/Printf_format_string

Subject PDF: https://github.com/akliek/42HN_ft_printf/blob/master/en.subject.pdf

# Clone
Open a terminal and run following command:
```
git clone <repository url>
```
# Instalation
Then go to created repository and run following command:
```
make
```
# How to use?
For using "ft_printf" function in your projects include ft_printf header and compile it with following command:
```
gcc your_files.c <path_to_libftprintf.a>
```
# Usage
```
      Implemented following conversions:
        • %c print a single character.
        • %s print a string of characters.
        • %p The void * pointer argument is printed in hexadecimal. • %d print a decimal (base 10) number.
        • %i print an integer in base 10.
        • %u print an unsigned decimal (base 10) number.
        • %x print a number in hexadecimal (base 16), with lowercase. • %X print a number in hexadecimal (base 16), with uppercase.
        • %% print a percent sign.
      And following flags:
        • '-'
        • '0'
        • '.'
        • minimum width
        • '#'
        • '+'
        • ' ' <- space
      Note:
        Invalid input cases don't implemented.
```
