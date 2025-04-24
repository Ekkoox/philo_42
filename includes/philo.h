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
	int				start_time;
	int				meals_count;
	int				time_to_eat;
	int				time_to_die;
	int				nbr_philos;
	int				time_to_sleep;
	int				meals_count;
	int				start_time;
	pthread_mutex_t	stop_mutex; //assigned in detroy 1
    pthread_mutex_t meals_mutex; //assigned in detroy 2

}					t_routine;

typedef struct s_data
{
	pthread_t		thread;
	pthread_mutex_t	left_forks; //assigned in detroy 3
	pthread_mutex_t	*right_forks; //assigned in detroy 4
}					t_data;

typedef struct s_philo
{
	t_routine		*routine;
	t_data			*data;
}					t_philo;

// STRUCT
int					init_struct(t_philo **philo);
void				free_struct(t_philo *philo);

// TIME
unsigned int		get_time(void);

// INIT
int					init_philo(t_philo *philo, int ac, char **av);

// UTILS
int					join_philo(t_philo *philo);
int					destroy_philo(t_philo *philo);
void				ft_putstr_fd(char *s, int fd);
void				*ft_calloc(size_t nmemb, size_t size);

#endif