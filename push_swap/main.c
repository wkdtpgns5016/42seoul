#include <stdio.h>
#include "push_swap.h"

int	is_sort_stack(t_stack *stack)
{
	int		max;
	t_dlist	*list;

	max	= -1;
	list = stack->top->front;
	if (list != 0)
	{
		if (max < *(int *)(list->data))
			max = *(int *)(list->data);
		else
			return (0);
		list = list->next;
	}
	return (1);
}

int	main(int args, char **argc)
{
	t_stack *a;
	t_stack *b;

	check_vaild_arg(args, argc);
	a = parsing_arg(args, argc);
	b = (t_stack *)malloc(sizeof(t_stack));
	init_stack(b);
	if (!is_sort_stack(a))
		push_swap(a, b);
}
