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

int		is_empty_stack(t_stack *stack);
void	push_stack(t_stack *stack, void *data);
void	*pop_stack(t_stack *stack);

#endif
