#include "header.h"

int	ft_get_strs(char *strs)
{
	int	count;

	count = 0;
	while (*strs)
	{
		if (*strs == '\n')
			count++;
		strs++;
	}
	return (count + 1);
}

char	*ft_get_line(char *sub_map_buf)
{
	int		i;
	char	*result;

	i = 0;
	while (sub_map_buf[i] != '\n' && sub_map_buf[i])
		i++;
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (result == NULL)
		ft_put_error();
	i = 0;
	while (sub_map_buf[i] != '\n' && sub_map_buf[i])
	{
		result[i] = sub_map_buf[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	check_map_row(char **map)
{
	int	count;

	count = 0;
	while (map[count] != 0)
		count++;
	if (count <= 2)
		return (0);
	return (1);
}

char	**asign_map(char *map_buf, int strs)
{
	char	**map;

	map = (char **)malloc(sizeof(char *) * (strs + 1));
	if (map == NULL)
		ft_put_error();
	while (*map_buf)
	{
		while (*map_buf && (*map_buf == '\n'))
			map_buf++;
		if (*map_buf != '\0')
		{
			*map = ft_get_line(map_buf);
			map++;
		}
		while (*map_buf && *map_buf != '\n')
			map_buf++;
	}
	*map = 0;
	map -= strs;
	return (map);
}

char	**ft_fget_map(char *filename, int *h_len, int *v_len)
{
	int		fd;
	int		flen;
	int		strs;
	char	*map_buf;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_buf = (char *)malloc(sizeof(char) * 99999);
	if (map_buf == NULL)
		ft_put_error();
	flen = read(fd, map_buf, 99999);
	strs = ft_get_strs(map_buf);
	map = asign_map(map_buf, strs);
	if (!check_map_row(map))
		ft_put_map_error();
	else
	{
		*h_len = ft_strlen(map[1]);
		*v_len = ft_atoi(ft_get_nbr(map[0]));
	}
	close(fd);
	free(map_buf);
	return (map);
}
