#include "libft.h"

void	ft_bzero(void *ptr, size_t num)
{
	size_t	i;
	unsigned char	*arr;

	i = 0;
	arr = (unsigned char *)ptr;
	while (i < num)
	{
		arr[i] = 0;
		i++;
	}
}
