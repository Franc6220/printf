#include "main.h"

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
 * print_char - Writes a character to stdout.
 * @c: The character to print
 *
 * Return: On success 1.
 */
int print_char(char c)
{
    return (write(1, &c, 1));
}

/**
 * print_string - Writes a string to stdout.
 * @str: The string to print
 *
 * Return: The number of characters printed
 */
int print_string(char *str)
{
    int i = 0;

    if (str == NULL)
        str = "(null)";

    while (str[i])
    {
        print_char(str[i]);
        i++;
    }

    return (i);
}

