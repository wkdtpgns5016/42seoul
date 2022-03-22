/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:24:43 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/20 11:00:32 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int		i;
	double	next;
	double	temp;

	next = 0.5 * (1 + (nb / 1));
	while (1)
	{
		temp = next;
		next = 0.5 * (next + (nb / next));
		if (temp - next < 0.005 || temp - next < -0.005)
			break ;
	}
	i = (int)next;
	if (i * i == nb)
		return ((int)next);
	else
		return (0);
}
