/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:39:22 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/16 13:48:07 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	init_arr(char	*arr, int	size, int	start,	int	idx)
{
	int	i;

	i = idx + 1;
	arr[idx] = start;
	while (i < size)
	{
		arr[i] = arr[i - 1] + 1;
		i++;
	}
}

void	print_arr(char	*arr, int	size)
{
	int	i;

	i = 0;
	while (i < size)
		write(1, &arr[i++], 1);
}

int	check_up(char	*arr, int	size)
{
	char	n;
	int		check;

	n = '9';
	check = 0;
	while (size > 1)
	{
		if (arr[size - 1] == n)
			check++;
		size--;
		n--;
	}
	return (check);
}

void	recursive(char	start, int size)
{
	char	arr[10];
	int		check;

	init_arr(arr, size, start, 0);
	while (arr[size - 1] <= '9')
	{
		print_arr(arr, size);
		if (arr[0] < (10 - size) + '0')
			write(1, ", ", 2);
		if (arr[size - 1] == '9')
		{
			check = check_up(arr, size);
			init_arr(arr, size, arr[size - 1 - check] + 1, size - 1 - check);
		}
		else
			arr[size - 1]++;
	}
	start++;
	if (arr[0] < (10 - size) + '0')
		recursive(start, size);
}

void	ft_print_combn(int	n)
{
	recursive('0', n);
}
