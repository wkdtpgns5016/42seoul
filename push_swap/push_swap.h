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

typedef struct s_stack
{
	t_list	*top;
}	t_stack;

typedef struct s_dlist
{
	void	*data;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}	t_dlist;

typedef	struct s_deque
{
	t_dlist	*front;
	t_dlist	*rear;
}	t_deque;

int			is_empty_stack(t_stack *stack);
void		push_stack(t_stack *stack, void *data);
void		*pop_stack(t_stack *stack);
void		init_deque(t_deque	*deque);
void		add_front_deque(t_deque *deque, void *data);
void		add_rear_deque(t_deque *deque, void *data);
void		*delete_front_deque(t_deque *deque);
void		*delete_rear_deque(t_deque *deque);
void		check_vaild_arg(int args, char **argc);
long long	ft_atol(const char *nptr);
t_deque	*	parsing_arg(int args, char **argc);
void		push_swap(t_deque *a, t_deque *b, int chunk);
#endif
