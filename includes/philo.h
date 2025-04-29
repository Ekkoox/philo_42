/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:32:26 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/29 17:03:29 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define ERR_PAR_NODIGIT "Error: only number accepted in parameters\n"
# define ERR_PAR_OUTRANGE "Error: number out of range\n"
# define FORK "has taken a fork\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"


# include <limits.h>
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
	pthread_mutex_t routine_mutex;
	pthread_mutex_t	mutex_over;
	pthread_mutex_t	meals_mutex;
	struct t_philo	*philo;
}					t_routine;

typedef struct s_data
{
	int				id;
	int				eat;
	int				dead;
	int 			stop;
	int				time_last_meal;
	pthread_t		thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	mutex_over;
	pthread_mutex_t	mutex_time_to_eat;
	t_routine		*routine;
}					t_data;

typedef struct s_philo
{
	t_data			*data;
	t_routine		routine;
}					t_philo;

//FREE
void				ft_exit(t_philo *philo, int mutex, int nbr_philo);

// INIT
int					init(t_philo *philo, int ac, char **av);

// MONITORING
void				*monitoring(void *arg);
int 				philo_died(t_data *data);
int 				can_i_print(t_data *data, char *str);

// PARSING
int					convert_nbr(char *str);
int					check_parsing(t_philo *philo, int ac);

// PRINT
int					print_eat(t_data *data);
int					print_sleep(t_data *datat_data);
int					print_think(t_data *data);

// ROUTINE
int					routine(t_philo *philo);
int					check_death(t_routine *routine);

// STRUCT
void				free_struct(t_philo *philo);

// TIME
int		get_time(void);

// UTILS
int					join_philo(t_philo *philo);
void				ft_putstr_fd(char *s, int fd);

#endif