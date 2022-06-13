#include "get_next_line.h"

int ft_strlen(char *s)
{
	int i;
	i=0;
	while (*s++)
		i++;
	return (i);
}

char *ft_strchr(const char *s, int c)
{
	char *str;
	int i;

	i = 0;
	str = (char *)s;
	if (str == 0)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (str + i);
		i++;
	}
	if (c == '\0')
		return (str);
	return (0);
}

char *ft_strjoin(char *s1, char *s2)
{
	int i;
	int j;
	char *new;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		*s1 = '\0';
	}
	if (!s1 || !s2)
		return (0);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	j = 0;
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

char *get_backup(char *backup)
{
	char *new;
	int i;
	int j;

	if (*backup == '\0')
	{
		free(backup);
		return (0);
	}
	i = 0;
	j = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	new = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (backup[i] == '\n')
		i++;
	while (backup[i] != '\0')
		new[j++] = backup[i++];
	new[j] = '\0';
	free(backup);
	return (new);
}

char *get_line(char *backup)
{
	char *line;
	int i;
	int j;

	if (*backup == '\0')
		return (0);
	i = 0;
	j = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	while (backup[j] && backup[j] != '\n')
	{
		line[j] = backup[j];
		j++;
	}
	if (backup[j] == '\n')
	{
		line[j] = '\n';
		j++;
	}
	line[j] = '\0';
	return (line);
}

char *get_next_line(int fd)
{
	int bytes;
	char *line;
	char buffer[BUFFER_SIZE + 1];
	static char *backup;

	bytes = 1;
	if (fd < 0)
		return (0);
	while (bytes > 0 && ft_strchr(backup, '\n') == 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(backup);
			return (0);
		}
		buffer[bytes] = '\0';
		backup = ft_strjoin(backup, buffer);
	}
	line = get_line(backup);
	backup = get_backup(backup);
	return (line);
}