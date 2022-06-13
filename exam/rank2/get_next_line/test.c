/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shahn <shahn@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 02:01:26 by shahn             #+#    #+#             */
/*   Updated: 2022/06/11 20:51:20 by shahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char* s2)
{
	char *new;
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		*s1 = '\0';
	}
	if (!s1 || !s2)
		return (0);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s1)
		while (s1[j] != '\0')
			new[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	if (!s)
		return (0);
	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	return (0);
}

char	*get_backup(char *backup)
{
	char	*new;
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (!*backup)
	{
		free(backup);
		return (NULL);
	}
	while (backup[count] && backup[count] != '\n')
		count++;
	new = (char *)malloc((sizeof(char) * (ft_strlen(backup) - count) + 1));
	if (backup[count] == '\n')
		count++;
	while (backup[count])
		new[i++] = backup[count++];
	new[i] = '\0';
	free(backup);
	return (new);
}

char	*get_line(char *backup)
{
	int		linesize;
	char	*line;
	int		i;

	i = 0;
	linesize = 0;
	if (!*backup)
		return (NULL);
	while (backup[linesize] && backup[linesize] != '\n')
		linesize++;
	line = (char *)malloc(sizeof(char) * (linesize + 2));
	while (backup[i] && backup[i] != '\n')
	{
		line[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*backup;
	char			*line;
	char			buffer[BUFFER_SIZE + 1];
	int				bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && ft_strchr(backup, '\n') == NULL)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(backup);
			return (NULL);
		}
		buffer[bytes] = '\0';
		backup = ft_strjoin(backup, buffer);
	}
	line = get_line(backup);
	backup = get_backup(backup);
	return (line);
}
