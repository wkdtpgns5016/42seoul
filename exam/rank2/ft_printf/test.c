#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(*str++)
		i++;
	return (i);
}

int print_d(int num)
{
	int temp;
	int level;
	int n;
	int len;
	char c;

	temp = num;
	level = 1;
	len = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	while (temp > 0)
	{
		temp /= 10;
		level *= 10;
	}
	level /= 10;
	while (level > 0)
	{
		n = num / level;
		c = n + '0';
		num = num % level;
		level /= 10;
		len++;
		write(1, &c, 1);
	}
	return (len);
}

int get_size_hex(unsigned int num)
{
	int i;

	i = 0;
	while (num > 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}

char *make_arr_hex(unsigned int num)
{
	char *arr;
	int size;
	int i;

	size = get_size_hex(num);
	arr = (char *)malloc(sizeof(char) * size + 1);
	i = 0;
	while (num > 0)
	{
		arr[i] = "0123456789abcdef"[num % 16];
		num /= 16;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

int print_x(unsigned int num)
{
	char *str;
	int n;
	int len;

	str = make_arr_hex(num);
	len = ft_strlen(str);
	n = 0;
	write(1, "0x", 2);
	while (len > 0)
	{
		len--;
		n++;
		write(1, &str[len], 1);
	}
	free(str);
	return (n);
}

int print_value(const char *format, va_list *ap)
{
	char *str;
	int len;

	len = 0;
	if (*format == 's')
	{
		str = va_arg(*ap, char *);
		if (str == 0)
			str = "(null)";
		len = ft_strlen(str);
		write(1, str, len);
	}
	else if (*format == 'd')
	{
		len = print_d(va_arg(*ap, int));
	}
	else if (*format == 'x')
	{
		len = print_x(va_arg(*ap, unsigned int));
	}
	return (len);
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	int len;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += print_value(format, &ap);
			format++;
		}
		else
		{
			write(1, format, 1);
			len++;
			format++;
		}
	}
	va_end(ap);
	return (len);
}


int main(void)
{
	ft_printf("%s\n", "toto");
	write(1, "\n", 1);
	ft_printf("Magic %s is %d", "number", 100);
	write(1, "\n", 1);
	ft_printf("Hexadecimal for %d is %x\n", 42, 2147483647);
	write(1, "\n", 1);
}
