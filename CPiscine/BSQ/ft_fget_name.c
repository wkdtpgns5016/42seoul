#include "header.h"

char	**ft_fget_name(int ac, char **av)
{
	int		i;
	char	**filename;

	filename = (char **)malloc(sizeof(char *) * ac);
	if (!filename)
		ft_put_error();
	i = -1;
	while (++i < ac - 1)
		filename[i] = ft_strdup(av[i + 1]);
	filename[i] = 0;
	return (filename);
}
