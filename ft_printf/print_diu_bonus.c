#include "libft/libft.h"
#include "ft_printf_bonus.h"

int	print_value(char **str, int length)
{
	int	len;

	len = ft_strlen(*str);
	if ((unsigned int)(len + length) < 2147483647)
	{
		ft_putstr_fd(*str, 1);
		free(*str);
		return (len);
	}
	free(*str);
	return (-1);
}

static char	*add_precision_du(t_format *format, char **num, int value)
{
	char	*str;

	if (format->precision == 0 && value == 0)
	{
		str = (char *)malloc(1);
		*str = '\0';
		free(*num);
	}
	else
		str = add_precision_num(format, num);
	return (str);
}

int	print_d(t_format *format, int value, int length)
{
	int		len;
	char	*str;
	char	*num;

	num = ft_itoa(value);
	if (num == 0)
		return (-1);
	str = add_precision_du(format, &num, value);
	if (str == 0)
		return (-1);
	if (add_flag_gsp_d(format, value, &str) < 0)
		return (-1);
	if (add_flag_zd(format, &str) < 0)
		return (-1);
	str = add_width(format, &str);
	if (str == 0)
		return (-1);
	len = print_value(&str, length);
	return (len);
}

int	print_i(t_format *format, int value, int length)
{
	int		len;

	len = print_d(format, value, length);
	return (len);
}

int	print_u(t_format *format, unsigned int value, int length)
{
	int		len;
	char	*str;
	char	*num;

	num = ft_uitoa(value);
	if (num == 0)
		return (-1);
	str = add_precision_du(format, &num, value);
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
