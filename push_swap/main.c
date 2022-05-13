#include <stdio.h>
#include "push_swap.h"

static int	get_chunk(double x)
{
	double	y;

	y = 0.000000053 * x * x + 0.03 * x + 14.5;
	return ((int)y);
}

int	main(int args, char **argc)
{
	t_deque *deque;
	int		chunk;

	chunk = get_chunk(1000);
	check_vaild_arg(args, argc);
	deque = parsing_arg(args, argc);
	t_dlist *list = deque->front;
	while (list != 0)
	{
		printf("%d ", *((int *)(list->data)));
		list = list->next;
	}
	printf("\n%d\n", chunk);
}
