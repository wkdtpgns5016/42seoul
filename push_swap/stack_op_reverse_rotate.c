#include "push_swap.h"

void	reverse_rotate_stack(t_stack *a)
{
	void	*data;

	if (get_size_stack(a) < 2)
		return ;
	data = delete_rear_deque(a->top);
	add_front_deque(a->top, data);
}

void	rra_stack(t_stack *a)
{
	reverse_rotate_stack(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb_stack(t_stack *b)
{
	reverse_rotate_stack(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr_stack(t_stack *a, t_stack *b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	ft_putstr_fd("rrr\n", 1);
}