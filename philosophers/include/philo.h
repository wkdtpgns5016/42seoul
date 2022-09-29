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
	uint64_t		start_time;
}	t_info;

typedef struct s_table
{
	uint64_t		start_time;
	int				print_able;
	int				dead_flag;

	pthread_mutex_t	**fork;
	pthread_mutex_t	*flag_mutex;
	pthread_mutex_t	*print_mutex;

}	t_table;

typedef struct s_philo
{
	pthread_t		*philo;
	uint64_t		last_eat_time;
	int				philo_num;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	int				goal_flag;

	pthread_mutex_t	*last_eat_mutex;
	t_info			*info;
	t_table			*table;
}	t_philo;

typedef struct s_monitor
{
	pthread_t		*monitor;
	t_philo			**philos;
}	t_monitor;

t_info			set_info(int ac, char **av);
pthread_mutex_t	**set_fork(int num_of_philo);
t_table			*set_table(pthread_mutex_t **fork);

int				ft_atoi(const char *nptr);
void			print_message(char *str, int philo_num, uint64_t time);
void			ft_sleep(int us);
uint64_t		get_time(void);
pthread_mutex_t	*make_mutex(void);

t_philo			*set_philo(int num, t_info *info, t_table *table);
void			create_philo_thread(t_monitor monitor, t_info info);
void			*action(void *data);

int				pick_up_fork(t_philo *table);
int				put_down_fork(t_philo *table);
int				eating(t_philo *table);
int				sleeping(t_philo *table);
int				thinking(t_philo *table);
void			dead(t_philo *table, uint64_t time);
int				check_dead(t_philo *philo);

t_monitor		set_monitor(t_info *info, t_table *table);
void			*monitor_philo(void *data);

#endif