/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjang <sehjang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:26:53 by sehjang           #+#    #+#             */
/*   Updated: 2022/04/14 18:26:56 by sehjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

typedef struct s_format
{
	char	*flags;
	int		width;
	int		precision;
	char	type;
	int		len;
}	t_format;

int			ft_printf(const char *format, ...);
t_format	*fmt_new(void);
int			set_format(t_format **format, const char *str, va_list *ap);
int			is_vaild_format(t_format *format);
int			print_c(t_format *format, char c);
int			print_s(t_format *format, char *value);
int			print_p(t_format *format, void *ptr);
void		print_hex(unsigned long long num, int *len);
int			print_d(t_format *format, int value);
int			print_i(t_format *format, int value);
int			print_u(t_format *format, unsigned int value);
char		*flag_zero(int len, char **str);
char		*flag_dash(int len, char **str);
char		*flag_shap(t_format *format, char **str);
char		*flag_plus(t_format *format, char **str, int value);
char		*flag_gap(t_format *format, char **str, int value);
int			add_flag_gsp_d(t_format *format, int value, char **str);
int			add_flag_zd(t_format *format, char **str);
char		*add_precision_d(t_format *format, int value);
char		*add_precision_u(t_format *format, unsigned int value);
char		*add_precision_s(t_format *format, char *value);
int			print_width(int width, int len);
int			is_flag_char(const char c);
int			is_type_char(const char c);
char		*get_flag(const char *str, size_t len);
int			get_num(const char *str, size_t len);
char		*make_str_hex(uintptr_t num);
int			get_size_hex(uintptr_t num);
char		*revrse_str(char **str);
char		*ft_uitoa(unsigned int n);

#endif
