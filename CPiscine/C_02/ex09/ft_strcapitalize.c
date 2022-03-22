/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:48:50 by sehjang           #+#    #+#             */
/*   Updated: 2022/01/17 19:40:01 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lower(char	str)
{
	if (str >= 'a' && str <= 'z')
		return (1);
	else
		return (0);
}

int	is_first_letter(char	str)
{
	if (is_lower(str))
		return (1);
	else if (str >= 'A' && str <= 'Z')
		return (1);
	else if (str >= '0' && str <= '9')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char	*str)
{
	int	i;

	i = 1;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	while (str[i] != '\0')
	{
		if (is_lower(str[i]))
		{
			if (!is_first_letter(str[i - 1]))
				str[i] = str[i] - 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (is_first_letter(str[i - 1]))
				str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}
