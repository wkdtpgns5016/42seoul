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

typedef	struct s_time
{
	struct timeval	*timestamp;
	pthread_mutex_t	*time_mutex;
}	t_time;

typedef struct s_philo
{
	int				read;
	int				*dead_flag;
	int				left_fork;
	int				right_fork;
	int				philo_num;
	uint64_t		last_eat_time;
	pthread_mutex_t	**fork;
	pthread_t		*philo;
	struct timeval	timestamp;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*last_eat_mutex;
	pthread_mutex_t	*flag_mutex;
	t_info			info;
}	t_philo;

typedef struct s_monitor
{
	pthread_t		*monitor;
	t_philo			**philos;
}	t_monitor;

typedef struct s_table
{
	t_info			info;
	int				philo_num;
	struct timeval	time;
	struct timeval	starve_time;
	pthread_mutex_t	*time_mutex;
	t_monitor		*monitor;
}	t_table;

t_info			set_info(int ac, char **av);
pthread_mutex_t	**set_fork(int num_of_philo);
t_table			set_table(int ac, char **av);
t_time			*set_time(void);
uint64_t		calc_ms(struct timeval time);

int				ft_atoi(const char *nptr);
void			print_message(char *str, int philo_num, uint64_t time);
void			ft_sleep(int us);

int				get_right_fork(int philo_num);
int				get_left_fork(int philo_num, int total_philo);

t_philo			*set_philo(pthread_mutex_t **fork, int num, t_info info, t_time *time);
void			create_philo_thread(t_monitor monitor, t_info info);
void			*action(void *data);

int				pick_up_fork(t_philo *table);
int				put_down_fork(t_philo *table);
int				eating(t_philo *table);
int				sleeping(t_philo *table);
int				thinking(t_philo *table);
void			dead(t_philo *table, uint64_t time);
int				check_dead(t_philo *philo);

t_monitor		set_monitor(pthread_mutex_t **fork, t_info info);
void			*monitor_philo(void *data);
uint64_t		get_time(void);

#endif