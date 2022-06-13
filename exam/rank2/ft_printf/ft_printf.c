#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>


int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

int print_d(int num)
{
	int temp;
	int level;
	int n;
	int count;
	char c;

	if (num < 0)
	{
		num = num * -1;
		write(1, "-", 1);
	}
	temp = num;
	level = 1;
	count = 0;
	while (temp > 0)
	{
		temp /= 10;
		level *= 10;
	}
	level /= 10;
	while (level > 0)
	{
		n = num / level;
		num = num % level;
		c = n + '0';
		write(1, &c, 1);
		level /= 10;
		count++;
	}
	return (count);
}

int	get_size_hex(unsigned int num)
{
	int	size;

	size = 0;
	while (num > 0)
	{
		num /= 16;
		size++;
	}
	return (size);
}

char	*make_str_hex(unsigned int num)
{
	char	*str;
	int		size;
	int		i;

	size = get_size_hex(num);
	if (size == 0)
	{
		str = (char *)malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = '\0';
	}
	else
	{
		str = (char *)malloc(sizeof(char) * (size + 1));
		if (str == 0)
			return (0);
		i = 0;
		while (num > 0)
		{
			str[i] = "0123456789abcdef"[num % 16];
			num /= 16;
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

int print_hex(unsigned int hex)
{
	char *str;
	int i;
	int len;

	str = make_str_hex(hex);
	i = ft_strlen(str) - 1;
	len = 0;
	write(1,"0x",2);
	while (i >= 0)
	{
		write(1, str + i, 1);
		i--;
		len++;
	}
	free(str);
	return (len);
}

int	print_value(const char *format, va_list *ap)
{
	int		len;
	char	*str;

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
		len = print_d(va_arg(*ap, int));
	else if (*format == 'x')
		len = print_hex(va_arg(*ap, unsigned int));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;

	len = 0;
	va_start(ap, format);
	while (*format != 0)
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
			format++;
			len++;
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
