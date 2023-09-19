#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: a character string which is composed of zero or more directives
 * @...: the list of other arguments to be printed
 * Return: the number of characters printed excluding the null byte
 */

int _printf(const char *format, ...)
{
	unsigned int w, str_read, read = 0;
	va_list args;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);

	for (w = 0; format[w] != '\0'; w++) /* Iterate through the format string */
	{
		if (format[w] != '%')
			put_chr(format[w]); /* Write the char to standard output */

		else if (format[w + 1] == 'c') /* Handle the 'c specifier */
		{
			put_chr(va_arg(args, int));
			w++;
		}
		else if (format[w + 1] == 's') /* Hnadle the 's' specifier */
		{
			str_read = put_str(va_arg(args, char *));
			w++;
			read += (str_read - 1);
		}
		else if (format[w + 1] == '%')
		{
			put_chr('%');
		}
		read += 1;
	}
	va_end(args);
	return (read);
}
