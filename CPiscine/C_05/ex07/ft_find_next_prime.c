/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:54:44 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/24 14:45:16 by sehjang          ###   ########.fr       */
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
		return ((int)next + 1);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	sqrt;

	if (nb <= 1)
		return (0);
	i = 2;
	sqrt = ft_sqrt(nb);
	while (i <= sqrt)
	{
		if (nb != 2 && nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
