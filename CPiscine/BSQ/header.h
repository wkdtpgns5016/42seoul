#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define MAX_READ 200000000

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

int		ft_map_vaild(char	**map, int len);
char	*ft_gets(char *str);

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_put_error(void);
int		ft_put_map_error(void);

int		ft_atoi(char *str);
char	*ft_strdup(char *src);
char	*ft_get_nbr(char *first_line);

char	**ft_fget_name(int ac, char **av);
char	**ft_fget_map(char *filename, int *h_len, int *v_len);
char	**ft_fget_map2(int *h_len, int *v_len);

void	sort_point(t_point *answer);

void	mapping(char **map, int v_len, int h_len);
void	make_square(int **dp, int v_len, int h_len);
void	print_map(char **map, int v_len);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
void	free_arr(char *filename, char **dict);

char	**asign_map(char *map_buf, int strs);
char	*ft_get_line(char *sub_map_buf);
int		ft_get_strs(char *strs);

void	get_max(int **dp, int v_len, int h_len, int *max);

void	change_map(int **dp, char **map, t_point answer);

t_point	select_square(int **dp, int v_len, int h_len);

#endif