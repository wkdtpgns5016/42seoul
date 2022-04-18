#include "libft/libft.h"
#include "ft_printf_bonus.h"

static int	get_unit(unsigned int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static int	get_level(unsigned int unit)
{
	int	level;

	level = 1;
	while (unit-- > 1)
		level *= 10;
	return (level);
}

static void	insert_value(char *arr, unsigned int num, int size)
{
	int	unit;
	int	level;
	int	i;

	unit = get_unit(num);
	level = get_level(unit);
	i = 0;
	if (size > unit)
		arr[i++] = '-';
	while (i < size)
	{
		arr[i++] = (num / level) + '0';
		num = num - ((num / level) * level);
		level /= 10;
	}
	arr[i] = '\0';
}

char	*ft_uitoa(unsigned int n)
{
	char			*arr;
	int				size;
	unsigned int	num;

	size = 0;
	num = n;
	if (n == 0)
		return (ft_strdup("0"));
	size += get_unit(num);
	arr = (char *)ft_calloc(sizeof(char), size + 1);
	if (arr == 0)
		return (0);
	insert_value(arr, num, size);
	return (arr);
}
