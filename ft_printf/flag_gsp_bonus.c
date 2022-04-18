#include "libft/libft.h"
#include "ft_printf_bonus.h"

char	*flag_shap(t_format *format, char **str)
{
	char	*new;

	if (format->type == 'x')
		new = ft_strjoin("0x", *str);
	else if (format->type == 'X')
		new = ft_strjoin("0X", *str);
	else
		return (*str);
	free(*str);
	if (new == 0)
		return (0);
	return (new);
}

char	*flag_plus(char **str, int value)
{
	char	*new;

	if (value >= 0)
	{
		new = ft_strjoin("+", *str);
		free(*str);
		if (new == 0)
			return (0);
		return (new);
	}
	return (*str);
}

char	*flag_gap(char **str, int value)
{
	char	*new;

	if (value >= 0)
	{
		new = ft_strjoin(" ", *str);
		free(*str);
		if (new == 0)
			return (0);
		return (new);
	}
	return (*str);
}
