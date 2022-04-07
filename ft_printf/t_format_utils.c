#include "ft_printf.h"
#include "libft/libft.h"
#include <stdarg.h>

t_format	*fmt_new()
{
	t_format *format = (t_format *)malloc(sizeof(t_format));
	if (format == 0)
		return (0);
	format->flags = 0;
	format->width = 0;
	format->precision = 0;
	format->type = 0;
	format->len = 0;
	return (format);
}
