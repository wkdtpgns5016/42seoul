#include "push_swap.h"

void	rotate_stack(t_stack *a)
{
	void	*data;

	if (get_size_stack(a) < 2)
		return ;
	data = delete_front_deque(a->top);
	add_rear_deque(a->top, data);
}

void	ra_stack(t_stack *a)
{
	rotate_stack(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb_stack(t_stack *b)
{
	rotate_stack(b);
	ft_putstr_fd("rb\n", 1);
}
void	rr_stack(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	ft_putstr_fd("rr\n", 1);
}
