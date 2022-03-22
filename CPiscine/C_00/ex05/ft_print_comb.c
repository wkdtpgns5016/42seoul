/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:23:01 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/11 10:41:23 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_arr(char	*arr, int	size)
{
	int	i;

	i = 0;
	while (i < size)
		write(1, &arr[i++], 1);
}

void	recursive(char	start)
{
	char	num;
	char	arr[3];

	num = start;
	arr[0] = start;
	arr[1] = arr[0] + 1;
	arr[2] = arr[1] + 1;
	while (arr[2] <= '9')
	{
		print_arr(arr, 3);
		if (arr[0] < '7')
			write(1, ", ", 2);
		if (arr[2] == '9')
		{
			arr[1]++;
			arr[2] = arr[1] + 1;
		}
		else
			arr[2]++;
	}
	start++;
	if (start <= '7')
		recursive(start);
}

void	ft_print_comb(void)
{
	char	start;

	start = '0';
	recursive(start);
}
