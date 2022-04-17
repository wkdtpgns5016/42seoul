#include "ft_printf.h"
#include "libft/libft.h"

static char	*convert_hex(t_format *format, unsigned int value)
{
	char		*str;

	if (format->type == 'x')
		str = make_str_hex(value, 1);
	else
		str = make_str_hex(value, 0);
	if (str == 0)
		return (0);
	str = revrse_str(&str);
	if (str == 0)
		return (0);
	return (str);
}

int	print_x(t_format *format, unsigned int value, int length)
{
	int		len;
	char	*str;

	str = convert_hex(format, value);
	if (str == 0)
		return (-1);
	str = add_precision_num(format, str);
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
