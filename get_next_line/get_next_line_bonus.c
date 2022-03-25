#include "get_next_line_bonus.h"
#include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*arr;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (arr == 0)
		return (0);
	ft_strlcpy(arr, s1, s1_len + 1);
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
			if(*(backup + newline) == '\n')
				break;
			newline++;
		}
		if((line = (char *)malloc(sizeof(char) * (newline + 1))) == 0)
			return (0);
		ft_strlcpy(line, backup, newline + 1);
	}
	else
	{
		if((line = (char *)malloc(sizeof(char) * (ft_strlen(backup) + 1))) == 0)
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

	if((buf = (char *)malloc(BUFFER_SIZE + 1)) == 0)
		return (0);
	while ((nbytes = read(fd, buf, BUFFER_SIZE)) != 0)
	{
		buf[nbytes] = '\0';
		if (*backup == 0)
			*backup = ft_strdup(buf);
		else
		{
			temp = *backup;
			*backup = ft_strjoin(temp, buf);
			free(temp);
		}
		if(*backup == 0)
			return (0);
		if (ft_strchr(buf, '\n') != 0)
			break;
	}
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
			if(*((*backup) + newline) == '\n')
				break;
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
	}
	else
	{
		free(*backup);
		*backup = 0;
	}
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	line = 0;
	if(init_backup(fd, &backup) == 0)
		return (0);
	if (backup != 0)
		line = make_line(backup);
	if (backup != 0)
		split_backup(&backup);
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
        printf("|%s\n", line);
        free(line);
        j++; 
    } 
    printf("|%s\n", line); 
    free(line); 
    close(fd); 
}