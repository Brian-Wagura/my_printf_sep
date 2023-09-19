#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        int x = BUFFER_SIZE - 2;
        unsigned long int num = va_arg(types, unsigned long int);

        num = convert_size_unsigned(num, size);

        if (num == 0)
                buffer[x--] = '0';

        buffer[BUFFER_SIZE - 1] = '\0';

        while (num > 0)
        {
                buffer[x--] = (num % 10) + '0';
                num /= 10;
        }

        x++;

        return (write_unsigned(0, x, buffer, flags, width, precision, size));
}

/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
	int x = BUFFER_SIZE - 2;
        unsigned long int num = va_arg(types, unsigned long int);
        unsigned long int init_num = num;

        UNSPECIFIED(width);

        num = convert_size_unsigned(num, size);

        if (num == 0)
                buffer[x--] = '0';

        buffer[BUFFER_SIZE - 1] = '\0';

        while (num > 0)
        {
                buffer[x--] = (num % 8) + '0';
                num /= 8;
        }

        if (flags & F_HASH && init_num != 0)
                buffer[x--] = '0';

        x++;

        return (write_unsigned(0, x, buffer, flags, width, precision, size));

}

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        return (print_hex(types, "0123456789abcdef", buffer,
                flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_caps(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        return (print_hexa(types, "0123456789ABCDEF", buffer,
                flags, 'X', width, precision, size));
}

/**
 * print_hex - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */

int print_hex(va_list types, char map_to[], char buffer[],
        int flags, char flag_ch, int width, int precision, int size)
{
        int x = BUFFER_SIZE - 2;
        unsigned long int num = va_arg(types, unsigned long int);
        unsigned long int init_num = num;

        UNSPECIFIED(width);

        num = convert_size_unsigned(num, size);

        if (num == 0)
                buffer[x--] = '0';

        buffer[BUFFER_SIZE - 1] = '\0';

        while (num > 0)
        {
                buffer[x--] = map_to[num % 16];
                num /= 16;
        }

        if (flags & F_HASH && init_num != 0)
        {
                buffer[x--] = flag_ch;
                buffer[x--] = '0';
        }

        x++;

        return (write_unsigned(0, x, buffer, flags, width, precision, size));
}