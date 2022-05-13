#include "push_swap.h"

void	swap_stack(t_deque *a)
{
	void	*top;
	void	*prev;
	
	if (a->front == 0)
		return;
	top = delete_rear_deque(a);
	prev = delete_rear_deque(a);
	add_rear_deque(a, top);
	add_rear_deque(a, prev);
}

void	ss_stack(t_deque *a, t_deque *b)
{
	swap_stack(a);
	swap_stack(b);
}

void	pa_stack(t_deque *a, t_deque *b)
{
	void	*data;

	if (b->front == 0)
		return ;
	data = delete_rear_deque(b);
	add_rear_deque(a, data);
}

void	pb_stack(t_deque *a, t_deque *b)
{
	void	*data;

	if (a->front == 0)
		return ;
	data = delete_rear_deque(a);
	add_rear_deque(b, data);
}
