#include "push_swap.h"

void	ft_free(void *ptr)
{
	if (ptr != 0)
	{
		free(ptr);
		ptr = 0;
	}
}
