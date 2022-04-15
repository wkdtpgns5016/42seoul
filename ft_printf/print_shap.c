#include "ft_printf.h"
#include "libft/libft.h"

int	print_shap(t_format *format)
{
	int		len;

	len = 1;
	len += print_width(format->width, len);
	ft_putchar_fd('%', 1);
	return (len);
}
