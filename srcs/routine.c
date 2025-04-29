/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:32:10 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/29 12:19:07 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_routine *routine)
{
	int	state;

	state = 0;
	pthread_mutex_lock(&routine->mutex_over);
	if (routine->stop == 1)
		state = routine->stop;
	pthread_mutex_unlock(&routine->mutex_over);
	return (state);
}

static void	*routine_philo(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	
	if (data->id % 2 == 0)
		usleep (100);
	while (check_death(data->routine) != 1)
	{
		if (print_eat(data) == EXIT_FAILURE)
			return (NULL);
		if (print_sleep(data) == EXIT_FAILURE)
			return (NULL);
		if (print_think(data) == EXIT_FAILURE)
			return (NULL);
	}
	return (NULL);
}

int	routine(t_philo *philo)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	philo->routine.start_time = get_time();
	if (philo->routine.nbr_philos == 1)
		return (EXIT_FAILURE);
	while (i < philo->routine.nbr_philos)
	{
		if (pthread_create(&(philo->data[i].thread), NULL, routine_philo,
				&philo->data[i]) != 0)
		{
			ft_putstr_fd("Error: Thread creation failed\n", 2);
			return (EXIT_FAILURE);
		}
		i++;
	}
	pthread_create(&monitor, NULL, monitoring, philo);
	pthread_join(monitor, NULL);
	return (EXIT_SUCCESS);
}
