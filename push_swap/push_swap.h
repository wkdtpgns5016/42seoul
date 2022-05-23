/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:52:23 by sehjang           #+#    #+#             */
/*   Updated: 2022/05/10 17:52:24 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_dlist
{
	void			*data;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}	t_dlist;

typedef struct s_deque
{
	t_dlist	*front;
	t_dlist	*rear;
}	t_deque;

typedef struct s_stack
{
	t_deque	*top;
}	t_stack;

int			get_size_dlist(t_dlist *list);
void		init_deque(t_deque	*deque);
int			get_size_deque(t_deque *deque);
void		clear_deque(t_deque *deque);
void		add_front_deque(t_deque *deque, t_dlist *newnode);
void		add_rear_deque(t_deque *deque, t_dlist *newnode);
t_dlist		*delete_front_deque(t_deque *deque);
t_dlist		*delete_rear_deque(t_deque *deque);
void		error_message(void);
void		check_vaild_arg(int args, char **argc);
void		ft_free(void *ptr);
long long	ft_atol(const char *nptr);
t_deque		*make_deque(int args, char **argc);
t_stack		*parsing_arg(int args, char **argc);
void		init_stack(t_stack *stack);
int			is_empty_stack(t_stack *stack);
int			get_size_stack(t_stack *stack);
void		print_stack(t_stack *b);
int			get_top_stack(t_stack *stack);
void		push_swap(t_stack *a, t_stack *b);
void		swap_stack(t_stack *a);
void		sa_stack(t_stack *a);
void		sb_stack(t_stack *a);
void		ss_stack(t_stack *a, t_stack *b);
void		pa_stack(t_stack *a, t_stack *b);
void		pb_stack(t_stack *a, t_stack *b);
void		rotate_stack(t_stack *a);
void		ra_stack(t_stack *a);
void		rb_stack(t_stack *b);
void		rr_stack(t_stack *a, t_stack *b);
void		reverse_rotate_stack(t_stack *a);
void		rra_stack(t_stack *a);
void		rrb_stack(t_stack *b);
void		rrr_stack(t_stack *a, t_stack *b);
int			get_chunk(double x);
void		pass_b(t_stack *a, t_stack *b, int num, int chunk);
int			find_max(t_stack *stack, int max);
void		rotate_max(t_stack *b);
void		pass_a(t_stack *a, t_stack *b);
int			is_ascending_order_stack(t_stack *stack);
int			is_descending_order_stack(t_stack *stack);
void		push_swap_small(t_stack *a, t_stack *b, int size);
int			find_max(t_stack *stack, int max);
int			get_index_stack(t_stack *stack, int value);
void		clear_stack(t_stack *stack);

#endif
