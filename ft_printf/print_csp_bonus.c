#include "libft/libft.h"
#include "ft_printf_bonus.h"

static int	print_c_null(t_format *format, char c, int length)
{
	int	len;

	len = 0;
	if ((unsigned int)(format->width + length) >= 2147483647)
		return (-1);
	if (format->width > 1)
	{
		if (ft_strchr(format->flags, '-') == 0)
		{
			while (++len < format->width)
				ft_putchar_fd(' ', 1);
			ft_putchar_fd(c, 1);
		}
		else
		{
			ft_putchar_fd(c, 1);
			while (++len < format->width)
				ft_putchar_fd(' ', 1);
		}
		return (len);
	}
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_c(t_format *format, char c, int length)
{
	int		len;
	char	*str;

	if (c == '\0')
		return (print_c_null(format, c, length));
	str = (char *)malloc(sizeof(char) + 1);
	if (str == 0)
		return (-1);
	ft_memset(str, c, sizeof(char));
	str[1] = '\0';
	if (add_flag_zd(format, &str) < 0)
		return (-1);
	str = add_width(format, &str);
	if (str == 0)
		return (-1);
	len = print_value(&str, length);
	return (len);
}

int	print_s(t_format *format, char *value, int length)
{
	int		len;
	char	*str;
	char	*temp;

	temp = value;
	if (temp == 0)
		temp = "(null)";
	if (temp == 0)
		return (-1);
	str = add_precision_s(format, temp);
	if (str == 0)
		return (-1);
	if (add_flag_zd(format, &str) < 0)
		return (-1);
	str = add_width(format, &str);
	if (str == 0)
		return (-1);
	len = print_value(&str, length);
	return (len);
}

static char	*convert_addr(uintptr_t addr)
{
	char	*str;
	char	*temp;

	str = make_str_addr(addr);
	if (str == 0)
		return (0);
	str = revrse_str(&str);
	if (str == 0)
		return (0);
	temp = str;
	str = ft_strjoin("0x", temp);
	free(temp);
	if (str == 0)
		return (0);
	return (str);
}

int	print_p(t_format *format, void *ptr, int length)
{
	int			len;
	char		*str;

	str = convert_addr((uintptr_t)ptr);
	if (str == 0)
		return (-1);
	if (add_flag_zd(format, &str) < 0)
		return (-1);
	str = add_width(format, &str);
	if (str == 0)
		return (-1);
	len = print_value(&str, length);
	return (len);
}
