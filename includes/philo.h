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
	int				nbr_philos;
	int				start_time;
	int				meals_count;
	int				time_to_eat;
	int				time_to_die;
	int				time_to_sleep;
	pthread_mutex_t	mutex_over; //assigned in detroy 1
    pthread_mutex_t meals_mutex; //assigned in detroy 2

}					t_routine;

typedef struct s_data
{
	int 			eat;
	int				dead;
	pthread_t		thread;
	pthread_mutex_t	left_fork; //assigned in detroy 3
	pthread_mutex_t	*right_fork; //assigned in detroy 4
	pthread_mutex_t	mutex_over; //assigned in detroy 5
	pthread_mutex_t	mutex_time_to_eat; //assigned in detroy 6
}					t_data;

typedef struct s_philo
{
	t_data			*data;
	t_routine		*routine;
}					t_philo;

// INIT
int					init(t_philo *philo, int ac, char **av);

// STRUCT
int					init_struct(t_philo **philo);
void				free_struct(t_philo *philo);

// TIME
unsigned int		get_time(void);

// UTILS
int					join_philo(t_philo *philo);
int					destroy_philo(t_philo *philo);
void				ft_putstr_fd(char *s, int fd);
void				*ft_calloc(size_t nmemb, size_t size);

#endif