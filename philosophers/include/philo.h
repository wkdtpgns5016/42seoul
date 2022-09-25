#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_info
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				goal;
}	t_info;

typedef struct s_monitor
{
	pthread_t		*monitor;
	pthread_t		**philos;
	pthread_mutex_t	*flag_mutex;
	int				dead_flag;
	int				*time;
	int				status;
}	t_monitor;

typedef struct s_table
{
	t_info			info;
	int				philo_num;
	int				left_fork;
	int				right_fork;
	struct timeval	time;
	struct timeval	starve_time;
	pthread_mutex_t	*time_mutex;
	pthread_mutex_t	**fork;
	t_monitor		*monitor;
}	t_table;

t_info			set_info(int ac, char **av);
pthread_mutex_t	**set_fork(int num_of_philo);
t_table			set_table(int ac, char **av);

int				ft_atoi(const char *nptr);
void			print_message(char *str, int philo_num, int time);

int				get_right_fork(int philo_num);
int				get_left_fork(int philo_num, int total_philo);
int				calc_time(t_table *table, struct timeval start);
int				check_dead(t_table *table, int start, int end);

pthread_t		**set_philo(t_table table);
void			create_philos(pthread_t **philos, t_table table);
void			*action(void *data);

int				pick_up_fork(t_table *table);
int				put_down_fork(t_table *table);
int				eating(t_table *table);
int				sleeping(t_table *table);
int				thinking(t_table *table);
void			dead(t_table *table);

t_monitor		set_monitor(pthread_t **philos);
void			*monitor_philo(void *data);

#endif