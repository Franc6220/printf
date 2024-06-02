#include "main.h"

int print_integer(int n);

/**
 * _printf - produces output according to a format.
 * @format: The format string containing the characters and the specifiers
 *
 * Return: The number of characters printed (excluding the null byte)
 */
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

/**
 * print_integer - Writes an integer to stdout.
 * @n: The integer to print
 *
 * Return: The number of characters printed
 */
int print_integer(int n)
{
    unsigned int num;
    int printed_chars = 0;

    if (n < 0)
    {
        printed_chars += print_char('-');
        num = -n;
    }
    else
    {
        num = n;
    }

    if (num / 10 != 0)
    {
        printed_chars += print_integer(num / 10);
    }

    printed_chars += print_char((num % 10) + '0');

    return (printed_chars);
}

