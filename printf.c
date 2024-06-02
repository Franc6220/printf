#include "main.h"
#include <stdio.h>

int print_char(char c)
{
    putchar(c);  /* Print the character to stdout */
    return 1;    /* Return the number of characters printed, which is 1 in this case */
}

int print_string(char *str)
{
    int printed_chars = 0;
    while (*str != '\0')
    {
        putchar(*str);
        str++;
        printed_chars++;
    }
    return printed_chars;
}

int print_integer_recursive(int n)
{
    int printed_chars = 0;
    if (n / 10)
    {
        printed_chars += print_integer_recursive(n / 10);
    }
    putchar(n % 10 + '0');
    return printed_chars + 1;
}

int print_integer(int n)
{
    int printed_chars = 0;
    if (n < 0)
    {
        putchar('-');
        n = -n;
        printed_chars++;
    }
    printed_chars += print_integer_recursive(n);
    return printed_chars;
}

int print_binary(unsigned int n)
{
    int printed_chars = 0;
    unsigned int mask = 1u << (sizeof(unsigned int) * 8 - 1); /* Set the most significant bit */

    while (mask > 0)
    {
        if (n & mask)
            printed_chars += print_char('1');
        else
            printed_chars += print_char('0');

        mask >>= 1; /* Shift the mask to the right */
    }

    return printed_chars;
}

int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, printed_chars = 0;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%' && format[i + 1] != '\0')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    printed_chars += print_char(va_arg(args, int));
                    break;
                case 's':
                    printed_chars += print_string(va_arg(args, char *));
                    break;
                case '%':
                    printed_chars += print_char('%');
                    break;
                case 'd':
                case 'i':
                    printed_chars += print_integer(va_arg(args, int));
                    break;
                case 'b':
                    printed_chars += print_binary(va_arg(args, unsigned int));
                    break;
                default:
                    printed_chars += print_char('%');
                    printed_chars += print_char(format[i]);
                    break;
            }
        }
        else
        {
            printed_chars += print_char(format[i]);
        }
        i++;
    }

    va_end(args);
    return (printed_chars);
}

