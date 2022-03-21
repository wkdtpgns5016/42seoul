#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int	check_newline(char *buf, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

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

char	*get_line(char *buf, char *backup, int size)
{
	int		newline;
	char	*line;

	newline = get_newline(buf, size);
	line = (char *)malloc(sizeof(char) * (ft_strlen(backup) + newline + 1));
	if (line == 0)
		return (0);
	ft_strlcat(line, backup, ft_strlen(backup) + 1);
	ft_strlcat(line, buf, ft_strlen(backup) + newline + 1);
	return (line);
}

char	*get_backup(char *buf, char *backup, int size)
{
	int		newline;
	char	*str;

	newline = get_newline(buf, size);
	str = ft_strjoin(backup, buf + newline + 1);
	return (str);
}

char	*get_next_line(int fd)
{
	ssize_t		flag;
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	static char	*backup = "";

	flag = 1;
	while (flag != 0)
	{
		flag = read(fd, buf, BUFFER_SIZE);
		buf[flag] = '\0';
		if (check_newline(buf, (int)flag))
		{
			line = get_line(buf, backup, (int)flag);
			backup = "";
			backup = get_backup(buf, backup, (int)flag);
			return (line);
		}
		else
			backup = get_backup(buf, backup, (int)flag);
	}
	return (backup);
}

// int main() 
// { 
//     int fd; 
//     int i; 
//     int j; 
//     char *line = 0; 
//     char *lineadress[66]; 
    
//     j = 1; 
//     printf("\n==========================================\n"); 
//     printf("========= TEST 2 : Empty Lines ===========\n"); 
//     printf("==========================================\n\n"); 
//     if (!(fd = open("/home/bigdata/42seoul/gnlTester/files/41_no_nl", O_RDONLY))) 
//     { 
//         printf("\nError in open\n"); 
//         return (0); 
//     }
//     printf("%s", get_next_line(fd));
//     getchar();
//     printf("%s", get_next_line(fd));
//     getchar();
//     printf("%s", get_next_line(fd));
//     // while ((line = get_next_line(fd)) != 0) 
//     // { 
//     //     printf("|%s\n", line); 
//     //     free(line); 
//     //     j++; 
//     // } 
//     // printf("|%s\n", line); 
//     // free(line); 
//     close(fd); 
// }
