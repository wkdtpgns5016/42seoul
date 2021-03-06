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
int			*check_vaild_arg(int size, char **arr, int flag);
void		ft_free(void *ptr);
long long	ft_atol(const char *nptr);
t_deque		*make_deque(int args, int *argc);
t_stack		*parsing_arg(int args, char **argc, int flag);
void		init_stack(t_stack *stack);
int			is_empty_stack(t_stack *stack);
int			get_size_stack(t_stack *stack);
void		print_stack(t_stack *b);
int			get_top_stack(t_stack *stack);
void		push_swap(t_stack *a, t_stack *b, int args, char **argc);
void		swap_stack(t_stack *a);
int			sa_stack(t_stack *a, int flag);
int			sb_stack(t_stack *a, int flag);
int			ss_stack(t_stack *a, t_stack *b, int flag);
int			pa_stack(t_stack *a, t_stack *b, int flag);
int			pb_stack(t_stack *a, t_stack *b, int flag);
void		rotate_stack(t_stack *a);
int			ra_stack(t_stack *a, int flag);
int			rb_stack(t_stack *b, int flag);
int			rr_stack(t_stack *a, t_stack *b, int flag);
void		reverse_rotate_stack(t_stack *a);
int			rra_stack(t_stack *a, int flag);
int			rrb_stack(t_stack *b, int flag);
int			rrr_stack(t_stack *a, t_stack *b, int flag);
int			get_chunk(double x);
void		pass_b(t_stack *a, t_stack *b, int num, int chunk);
int			find_max(t_stack *stack, int max);
void		rotate_max(t_stack *b, int flag);
void		pass_a(t_stack *a, t_stack *b, int flag);
int			is_ascending_order_stack(t_stack *stack);
int			is_descending_order_stack(t_stack *stack);
void		push_swap_small(t_stack *a, t_stack *b, int size);
int			find_max(t_stack *stack, int max);
int			get_index_stack(t_stack *stack, int value);
void		clear_stack(t_stack *stack);
int			*convert_int_arg(int args, char **argc);
void		free_strs(char **argc);
int			find_num(t_stack *a, int chunk, int size);
int			check_num(t_stack *a, int chunk);
int			pass_b_test(t_stack *a, t_stack *b, int chunk, int flag);
int			pass_a_test(t_stack *a, t_stack *b, int flag);
t_stack		*make_a_stack(int args, char **argc);
void		free_ab_stack(t_stack *a, t_stack *b);

#endif
