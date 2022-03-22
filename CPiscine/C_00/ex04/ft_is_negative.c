/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:40:34 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/11 10:40:45 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int	n)
{
	char	result;

	if (n < 0)
	{
		result = 78;
	}
	else
	{
		result = 80;
	}
	write(1, &result, 1);
}
