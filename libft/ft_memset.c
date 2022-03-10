#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t	i;
	unsigned char	*arr;

	i = 0;
	arr = (unsigned char *)ptr;
	while (i < num)
	{
		arr[i] = value;
		i++;
	}
	return ((void *)arr);
}
