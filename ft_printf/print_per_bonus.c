#include "ft_printf_bonus.h"
#include "libft/libft.h"

int	print_per(t_format *format, int length)
{
	int		len;
	char	*str;

	str = (char *)malloc(sizeof(char) + 1);
	str[0] = '%';
	str[1] = '\0';
	str = add_width(format, &str);
	if (str == 0)
		return (-1);
	len = print_value(&str, length);
	return (len);
}
