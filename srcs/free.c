/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:32:08 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/29 18:30:02 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int destroy_philo(t_philo *philo, int nbr_philo)
{
	int i;

	i = 0;
	while (i < nbr_philo)
	{
		pthread_mutex_destroy(&philo->data[i].left_fork);
		pthread_mutex_destroy(&philo->data[i].mutex_time_to_eat);
		pthread_mutex_destroy(&philo->data[i].mutex_over);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int destroy_mutex(t_philo *philo)
{
	pthread_mutex_destroy(&philo->routine.mutex_over);
	pthread_mutex_destroy(&philo->routine.meals_mutex);
	pthread_mutex_destroy(&philo->routine.routine_mutex);
	return (EXIT_SUCCESS);
}

void	ft_exit(t_philo *philo, int mutex, int nbr_philo)
{
	(void)mutex;
	pthread_mutex_lock(&philo->routine.mutex_over);
	if (philo->routine.stop == 0)
		philo->routine.stop = 1;
	pthread_mutex_unlock(&philo->routine.mutex_over);
	destroy_mutex(philo);
	if (nbr_philo > 0)
		destroy_philo(philo, nbr_philo);
	if (philo->data)
		free(philo->data);
}
