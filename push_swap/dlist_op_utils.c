#include "push_swap.h"
#include "libft/libft.h"

int	get_size_dlist(t_dlist *list)
{
	t_dlist *temp;
	int		size;

	temp = list;
	size = 0;
	while (temp != 0)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}
