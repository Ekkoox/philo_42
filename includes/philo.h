#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_routine
{
	int				stop;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				meals_count;
	int				start_time;
	pthread_mutex_t	stop_mutex;
    pthread_mutex_t meals_mutex;

}					t_routine;

typedef struct s_data
{
	int				philosophers;
	pthread_t		thread;
	pthread_mutex_t	left_forks;
	pthread_mutex_t	*right_forks;
}					t_data;

typedef struct s_philo
{
	t_routine		*routine;
	t_data			*data;
}					t_philo;

// UTILS
void				ft_putstr_fd(char *s, int fd);
void				*ft_calloc(size_t nmemb, size_t size);
int					join_philo(t_philo *philo);
int 				destroy_philo(t_philo *philo);

// TIME
unsigned int 		get_time();

// INIT
int 				init_philo(t_philo *philo, int ac, char **av);

#endif