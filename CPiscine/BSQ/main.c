#include "header.h"

int	main(int ac, char **av)
{
	int		i;
	t_point	len;
	char	**map;
	char	**filename;

	if (ac != 1)
	{
		filename = ft_fget_name(ac, av);
		i = -1;
		while (++i < ac - 1)
		{
			map = ft_fget_map(filename[i], &len.x, &len.y);
			if (ft_map_vaild(map, v_len))
				mapping(map, v_len, h_len);
			else
				ft_put_map_error();
		}
	}
	else if (ac == 1)
	{
		map = ft_fget_map2(&len.x, &len.y);
		if (ft_map_vaild(map, len.y))
			mapping(map, len.y, len.x);
		else
			ft_put_map_error();
	}
	return (0);
}
