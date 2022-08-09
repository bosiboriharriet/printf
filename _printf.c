#include "main.h"
/**
 * _printf - function to be used to produce output according to format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int cnt = 0;
	const char *string;
	va_list arg;

	if (!format)
		return (-1);

	va_start(arg, format);
	string = format;

	cnt = loop_format(arg, string);

	va_end(arg);
	return (cnt);
}
/**
 * loop_format - second function to be used to make loop tp string pointer
 * @string: pointer obtained from format
 * @arg: va_list arg
 */
int loop_format(va_list arg, const char *string)
{
	flag = 0;
	int i = 0;
	cnt = 0;
	cnt_fm = 0;
	chk_per = 0;

	while (i < _strlen((char *)string) && *string != '\0')
	{
		char aux = string[i];

		if (aux == '%')
		{
			flag++;
			i++
			aux = string[i];
			if (aux == '\0' && _strlen((char *)string) == 1)
				return (-1);
			if (aux == '\0')
				return (cnt);
			if (aux == '%')
			{
				flag++;
			} else
			{
				cnt_fm = function_manager(aux, arg);
				if (cnt_fm >= 0 && cnt_fm != -1)
				{
					i++;
					aux = string[i];
					if (aux == '%')
						flag--;
					cnt = cnt + cnt_fm;
				} else if (cnt_fm == -1 && aux != '\n')
				{
					cnt += _putchar('%');
				}
			}
		}
		chk_per = chk_prcnt(&flag, aux);
		cnt += chk_per;
		if (chk_per == 0 && aux != '\0' && aux != '%')
			cnt += _putchar(aux), i++;
		chk_per = 0;
	}
	return (cnt);
}
/**
 * chk_percent - function that will print the % pear
 *@flag: value by reference
 *@aux: character
 *Return: 1 if % is printed
 */
int chk_percent(int *flag, char aux)
{
	int cnt = 0;
	int tmp_flag;

	tmp_flag = *flag;
	if (tmp_flag == 2 && aux == '%')
	{
		_putchar('%');
		tmp_flag = 0;
		cnt = 1;
	}
	return (cnt);
}

/**
 * call_funct_mgr - call function manager
 *@aux: character parameter
 *@arg: va_list arg
 *Return: number of characteres printed
 */

int call_funct_mgr(char aux, va_list arg)
{
	int cnt = 0;

	cnt = function_manager(aux, arg);
	return (cnt);
}

