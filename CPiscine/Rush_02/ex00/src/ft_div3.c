/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihopark <jihopark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:21:24 by jihopark          #+#    #+#             */
/*   Updated: 2022/01/23 16:28:38 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	*ft_div3(unsigned int n)
{
	unsigned int	nb;
	int				*arr;

	arr = malloc(5 * sizeof(int));
	arr[0] = n / 1000000000;
	nb = n % 1000000000;
	arr[1] = nb / 1000000;
	nb = nb % 1000000;
	arr[2] = nb / 1000;
	nb = nb % 1000;
	arr[3] = nb;
	return (arr);
}
