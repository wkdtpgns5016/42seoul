#include "push_swap.h"

void	swap_stack(t_stack *a)
{
	void	*top;
	void	*prev;
	
	if (get_size_stack(a) < 2)
		return;
	top = delete_front_deque(a->top);
	prev = delete_front_deque(a->top);
	add_front_deque(a->top, top);
	add_front_deque(a->top, prev);
}

void	sa_stack(t_stack *a)
{
	swap_stack(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb_stack(t_stack *b)
{
	swap_stack(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss_stack(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
	ft_putstr_fd("ss\n", 1);
}
