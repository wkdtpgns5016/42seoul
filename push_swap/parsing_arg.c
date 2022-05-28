/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:54:33 by sehjang           #+#    #+#             */
/*   Updated: 2022/05/17 20:40:42 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*parsing_arg(int args, char **argc, int flag)
{
	t_stack	*stack;
	int		*arr;

	arr = check_vaild_arg(args, argc, flag);
	if (arr == 0)
		return (0);
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == 0)
		return (0);
	stack->top = make_deque(args, arr);
	if (stack->top == 0)
	{
		ft_free(stack);
		return (0);
	}
	return (stack);
}
