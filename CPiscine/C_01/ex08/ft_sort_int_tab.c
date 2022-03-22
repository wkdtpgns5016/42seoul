/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:27:12 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/12 10:20:49 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int	*a, int	*b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int	*tab, int	size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		temp = i;
		j = i + 1;
		while (j < size)
		{
			if (tab[temp] > tab[j])
				temp = j;
			j++;
		}
		ft_swap(&tab[i], &tab[temp]);
		i++;
	}
}
