#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct s_format
{
	char    *flags;
	int     width;
    char    precision;
    char    type;
}	t_format;

int	ft_printf(const char *format, ...);

#endif
