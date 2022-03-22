/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihopark <jihopark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:25:03 by jihopark          #+#    #+#             */
/*   Updated: 2022/01/22 16:35:43 by jihopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	if (c == '\r' || c == '\f' || c == '\v')
		return (1);
	else
		return (0);
}

int	is_operator(char c)
{
	if (c == '+')
		return (1);
	else
		return (0);
}

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

unsigned int	ft_atoi(char *str)
{
	int				i;
	unsigned int	result;

	i = 0;
	result = 0;
	while (is_space(str[i]))
		i++;
	if (is_operator(str[i]))
	{		
		i++;
	}
	while (is_num(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}
