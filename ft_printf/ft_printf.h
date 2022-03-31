#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct s_format
{
	char    *flags;
	int     width;
    int     precision;
    char    type;
    int     len;
}	t_format;

int         ft_printf(const char *format, ...);
t_format	*fmt_new();

#endif
