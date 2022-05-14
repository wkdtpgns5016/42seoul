#include "push_swap.h"

void	pa_stack(t_stack *a, t_stack *b)
{
	void	*data;

	if (is_empty_stack(b))
		return ;
	data = delete_front_deque(b->top);
	add_front_deque(a->top, data);
	ft_putstr_fd("pa\n", 1);
}

void	pb_stack(t_stack *a, t_stack *b)
{
	void	*data;

	if (is_empty_stack(a))
		return ;
	data = delete_front_deque(a->top);
	add_front_deque(b->top, data);
	ft_putstr_fd("pb\n", 1);
}
