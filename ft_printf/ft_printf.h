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
int         set_format(t_format **format, const char *str);
int         is_type_char(const char c);
int         is_vaild_format(t_format *format);
int         print_c(t_format *format, char c);
int         print_p(t_format *format, void *ptr);
void        print_hex(unsigned long long num, int *len);
int print_d(t_format *format, int value);
char    *flag_zero(int len, char **str);
char    *flag_dash(int len, char **str);
char *flag_shap(t_format *format, char **str);
char *flag_plus(t_format *format, char **str, int value);
char *flag_gap(t_format *format, char **str, int value);

#endif
