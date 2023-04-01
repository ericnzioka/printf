#include <stdarg.h>
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1. Correct
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _printf - is a function that prints
 * @format: gives the format to the function
 * cases - d, i, s, c, %
 * Return: a string.
 */

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    for (const char *p = format; *p != '\0'; p++) {
        if (*p == '%') {
            p++;
            if (*p == 'c') {
                char c = va_arg(args, int);
                _putchar(c);
                count++;
            }
            else if (*p == 's') {
                char *str = va_arg(args, char *);
                for (; *str != '\0'; str++) {
                    _putchar(*str);
                    count++;
                }
            }
            else if (*p == '%') {
                _putchar('%');
                count++;
            }
            else {
                _putchar('%');
                _putchar(*p);
                count += 2;
            }
        }
        else {
            _putchar(*p);
            count++;
        }
    }

    va_end(args);

    return count;
}
