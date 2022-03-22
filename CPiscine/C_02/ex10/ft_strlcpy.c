/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:11:20 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/17 20:24:32 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned	int	ft_strlen(char *arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i] != '\0')
		i++;
	return (i);
}

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_size;

	i = 0;
	src_size = ft_strlen(src);
	if (size != 0)
	{
		while (i < src_size && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		if (size > 0)
			dest[i] = '\0';
	}
	return (src_size);
}
