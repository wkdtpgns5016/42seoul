#include "push_swap.h"

void	rotate_stack(t_deque *a)
{
	void	*data;

	if (a->front == 0)
		return ;
	data = delete_rear_deque(a);
	add_front_deque(a, data);
}

void	rr_stack(t_deque *a, t_deque *b)
{
	rotate_stack(a);
	rotate_stack(b);
}

void	reverse_rotate_stack(t_deque *a)
{
	void	*data;

	if (a->front == 0)
		return ;
	data = delete_front_deque(a);
	add_rear_deque(a, data);
}

void	rrr_stack(t_deque *a, t_deque *b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
}