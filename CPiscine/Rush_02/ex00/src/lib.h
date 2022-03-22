/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihopark <jihopark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:32:49 by jihopark          #+#    #+#             */
/*   Updated: 2022/01/23 21:26:38 by jihopark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "s_dict.h"

int				print_dict_error(void);
int				is_dict_valid(char **arr);
int				is_space(char c);
int				is_operator(char c);
int				is_num(char c);
unsigned int	ft_atoi(char *str);
char			*ft_convert(int i, t_dict *dict);
int				*ft_div3(unsigned int n);
int				is_include(char	c,	char *charset);
int				word_count(char *str, char *charset);
void			insert_word(char *arr, char *str, int size);
void			start_split(char **arr, char *str, char *charset, int arr_idx);
char			**ft_split(char *str, char *charset);
t_dict			*create_dicts(unsigned int size);
char			*delete_space_eng(char *str);
t_dict			add_dict(char *str, unsigned int size);
t_dict			*ft_make_dicts(char **arr);
int				ft_pow(int num, int i);
void			ft_putchar(char *str);
void			print_value(int mod, t_dict *dict, int *num);
void			ft_write3(int i, t_dict *dict);
void			ft_print(int *arr, t_dict *dict);
char			*ft_read(char *dict);
int				check_max(char *str);
int				ft_valid(char *str);
char			**ft_new_split(char *str);
void			free_split_arr(char **arr);	

#endif
