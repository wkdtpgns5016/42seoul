/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:02:48 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/17 20:27:18 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char	*str)
{
	int				i;
	int				result;
	unsigned char	*arr;

	i = 0;
	result = 1;
	arr = (unsigned char *)str;
	while (arr[i] != '\0')
	{
		if (arr[i] >= 32 && arr[i] <= 126)
			result = 1;
		else
			return (0);
		i++;
	}
	return (result);
}
