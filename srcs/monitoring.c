/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:16:02 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/27 20:19:15 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_died(t_data *philo)
{
	pthread_mutex_lock(&philo->routine->mutex_over);
	philo->routine->stop = 1;
	pthread_mutex_unlock(&philo->routine->mutex_over);
	pthread_mutex_lock(&philo->routine->meals_mutex);
	printf("%u %d died\n", (get_time() - philo->routine->start_time),
		philo->id);
	pthread_mutex_unlock(&philo->routine->meals_mutex);
}

void	*monitoring(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	while (philo->routine.stop != 1)
	{
		i = 0;
		while (i < philo->routine.nbr_philos)
		{
			pthread_mutex_lock(&philo->data[i].mutex_time_to_eat);
			if ((get_time() - philo->data[i].time_last_meal)
				>= philo->routine.time_to_die)
			{
				philo_died(&philo->data[i]);
				pthread_mutex_unlock(&philo->data[i].mutex_time_to_eat);
				return (NULL);
			}
			pthread_mutex_unlock(&philo->data[i].mutex_time_to_eat);
			i++;
		}
		pthread_mutex_unlock(&philo->routine.mutex_over);
		usleep(1000);
	}
	return (NULL);
}
