/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:28:09 by sehjang           #+#    #+#             */
/*   Updated: 2022/03/29 17:28:11 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

static char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*arr;
	char	*temp;

	if (s1 == 0 && s2 == 0)
		return (0);
	temp = (char *)s1;
	if (temp == 0)
		temp = "";
	s1_len = ft_strlen(temp);
	s2_len = ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (arr == 0)
		return (0);
	ft_strlcpy(arr, temp, s1_len + 1);
	ft_strlcpy(arr + s1_len, s2, s2_len + 1);
	arr[s1_len + s2_len] = '\0';
	return (arr);
}

static char	*make_line(char *backup)
{
	int		newline;
	char	*line;

	newline = 0;
	if (ft_strchr(backup, '\n') != 0)
	{
		while (*(backup + newline) != '\0')
		{
			if (*(backup + newline) == '\n')
				break ;
			newline++;
		}
		line = (char *)malloc(sizeof(char) * (newline + 2));
		if (line == 0)
			return (0);
		ft_strlcpy(line, backup, newline + 2);
	}
	else
	{
		line = (char *)malloc(sizeof(char) * (ft_strlen(backup) + 1));
		if (line == 0)
			return (0);
		ft_strlcpy(line, backup, ft_strlen(backup) + 1);
	}
	return (line);
}

static int	init_backup(int fd, char	**backup)
{
	char	*buf;
	ssize_t	nbytes;
	char	*temp;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == 0)
		return (0);
	nbytes = read(fd, buf, BUFFER_SIZE);
	while (nbytes > 0)
	{
		buf[nbytes] = '\0';
		temp = *backup;
		*backup = ft_strjoin(temp, buf);
		free(temp);
		if (*backup == 0)
		{
			free(buf);
			return (0);
		}
		if (ft_strchr(buf, '\n') != 0)
			break ;
		nbytes = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (1);
}

static void	split_backup(char **backup)
{
	int		newline;
	char	*temp;

	newline = 0;
	if (ft_strchr(*backup, '\n') != 0)
	{
		while (*((*backup) + newline) != '\0')
		{
			if (*((*backup) + newline) == '\n')
				break ;
			newline++;
		}
		temp = *backup;
		*backup = ft_substr(temp, newline + 1, ft_strlen(temp + newline + 1));
		free(temp);
		if (ft_strlen(*backup) == 0)
		{
			free(*backup);
			*backup = 0;
		}
		return ;
	}
	free(*backup);
	*backup = 0;
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*line;

	if (fd > OPEN_MAX && fd < 0)
		return (0);
	line = 0;
	if (init_backup(fd, &backup[fd]) == 0)
		return (0);
	if (backup[fd] != 0)
		line = make_line(backup[fd]);
	if (backup[fd] != 0)
		split_backup(&backup[fd]);
	return (line);
}
