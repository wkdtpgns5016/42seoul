#include "header.h"

char	*ft_get_nbr(char *first_line)
{
	int		i;
	int		fl_len;
	char	*nbr;

	fl_len = ft_strlen(first_line);
	fl_len -= 3;
	nbr = malloc(sizeof(char) * (fl_len + 1));
	i = 0;
	while (i < fl_len)
	{
		nbr[i] = first_line[i];
		i++;
	}
	nbr[i] = '\0';
	return (nbr);
}
