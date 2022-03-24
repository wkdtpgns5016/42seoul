#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int	get_newline(char *buf, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_line(char *buf, char **backup, int size)
{
	int		newline;
	char	*line;
	char	*temp;

	newline = get_newline(buf, size);
	if ((line = (char *)malloc(sizeof(char) * (ft_strlen(*backup) + newline + 1))) == 0)
		return (0);
	ft_strlcat(line, *backup, ft_strlen(*backup) + 1);
	ft_strlcat(line, buf, ft_strlen(*backup) + newline + 1);
	temp = *backup;
	free(temp);
	return (line);
}

char	*set_backup(char *newline_str, char *str, int size)
{
	int		newline;
	char	*backup;

	newline = get_newline(newline_str, size);
	backup = ft_strjoin(str, newline_str + newline + 1);
	return (backup);
}

int	make_line(char **line, char *buf, char **backup, int fd)
{
	ssize_t		flag;
	char		*temp;

	if (get_newline(*backup, ft_strlen(*backup)) >= 0)
	{
		*line = (char *)malloc(sizeof(char) * get_newline(*backup, ft_strlen(*backup)) + 1);
		ft_strlcpy(*line, *backup, get_newline(*backup, ft_strlen(*backup)) + 1);
		temp = *backup;
		*backup = set_backup(*backup, "", ft_strlen(*backup));
		free(temp);
		return (1);
	}
	while ((flag = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[flag] = '\0';
		if (get_newline(buf, (int)flag) >= 0)
		{
			*line = get_line(buf, backup, (int)flag);
			*backup = set_backup(buf, *backup, (int)flag);
			return (1);
		}
		else
			*backup = set_backup(buf, *backup, (int)flag);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	ssize_t		flag;
	char		*buf;
	char		*line;
	static char	*backup;
	char		*temp;

	if ((buf = (char *)malloc(BUFFER_SIZE + 1)) == 0)
		return (0);
	if (backup == 0)
	{
		if ((backup = (char *)malloc(sizeof(char))) == 0)
		return (0);
	}
	if (make_line(&line, buf, &backup, fd) > 0)
		return (line);
	if (backup != 0)
	{
		line = (char *)malloc(sizeof(char) * (ft_strlen(backup) + 1));
		ft_strlcpy(line, backup, ft_strlen(backup) + 1);
		free(backup);
		backup = 0;
	}
	else
	{
		line = 0;
	}
	return (line);
}

int main() 
{ 
    int fd; 
    int i; 
    int j; 
    char *line = 0; 
    char *lineadress[66]; 
    
    j = 1; 
    printf("\n==========================================\n"); 
    printf("========= TEST 2 : Empty Lines ===========\n"); 
    printf("==========================================\n\n"); 
    if (!(fd = open("/home/bigdata/42seoul/gnlTester/files/41_no_nl", O_RDONLY))) 
    { 
        printf("\nError in open\n"); 
        return (0); 
    }
    while ((line = get_next_line(fd)) != 0) 
    { 
        printf("|%s", line);
		getchar();
        free(line);
        j++; 
    } 
    printf("|%s\n", line); 
    free(line); 
    close(fd); 
}
