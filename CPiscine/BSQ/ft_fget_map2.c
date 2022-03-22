#include "header.h"

char	**ft_fget_map2(int *h_len, int *v_len)
{
	int		i;
	int		flen;
	int		strs;
	char	*map_buf;
	char	**map;

	map_buf = (char *)malloc(sizeof(char) * MAX_READ);
	if (map_buf == NULL)
		ft_put_error();
	i = 0;
	flen = read(0, map_buf, sizeof(map_buf));
	while (flen != 0 && flen != -1 && flen < MAX_READ)
	{
		i += flen;
		flen = read(0, &map_buf[i], sizeof(map_buf));
	}
	strs = ft_get_strs(map_buf);
	map = asign_map(map_buf, --strs);
	*h_len = ft_strlen(map[1]);
	*v_len = ft_atoi(ft_get_nbr(map[0]));
	free(map_buf);
	return (map);
}
