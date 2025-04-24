#include "philo.h"


static int	init_routine(t_philo *philo, int ac, char **av)
{
	philo->routine->nbr_philos = atoi(av[1]);
	philo->routine->time_to_die = atoi(av[2]);
	philo->routine->time_to_eat = atoi(av[3]);
	philo->routine->time_to_sleep = atoi(av[4]);
	if (ac == 6)
		philo->routine->meals_count = atoi(av[5]);
	else
		philo->routine->meals_count = -1;
	philo->routine->stop = 0;
	return (EXIT_SUCCESS);
}

static int	init_mutex(t_routine *routine)
{
	if (pthread_mutex_init(&routine->mutex_over, NULL))
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&routine->meals_mutex, NULL))
		return (pthread_mutex_destroy(&routine->mutex_over), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	init_mutex_philo(t_data *data)
{
	if (pthread_mutex_init(&data->left_fork, NULL))
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&data->mutex_over, NULL))
		return (pthread_mutex_destroy(&data->left_fork), EXIT_FAILURE);
	if (pthread_mutex_init(&data->mutex_time_to_eat, NULL))
		return (pthread_mutex_destroy(&data->left_fork),
			pthread_mutex_destroy(&data->mutex_over), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	init_data(t_philo *philo)
{
	int i;

	i = 0;
	philo->routine->start_time = get_time();
	while (i < philo->routine->nbr_philos)
	{
		philo->data[i].eat = 0;
		philo->data[i].dead = 0;
		philo->data[i].right_fork = NULL;
		if (init_mutex_philo(philo->data) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init(t_philo *philo, int ac, char **av)
{
	if (init_routine(philo, ac, av) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	philo->data = malloc(sizeof(t_data) * philo->routine->nbr_philos);
	if (!philo->data)
	{
		ft_putstr_fd("Error: Data memory allocation failed\n", 2);
		return (EXIT_FAILURE);
	}
	if (init_mutex(philo->routine) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_data(philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
