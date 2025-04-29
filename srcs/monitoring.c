/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:16:02 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/29 19:53:38 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int print_eat_well(t_philo *philo)
{

	pthread_mutex_lock(&philo->routine.routine_mutex);
	if (philo->routine.meals_count > 1)
	{
		pthread_mutex_unlock(&philo->routine.routine_mutex);
		ft_putstr_fd("All philosophers have eaten enough\n", 1);
		return (EXIT_FAILURE);
	}
	pthread_mutex_unlock(&philo->routine.routine_mutex);

	return (EXIT_SUCCESS);
}

int eat_well(t_data *data)
{
	int i;
	int philo_greedy;
	
	if (data->routine->meals_count == -1)
		return (EXIT_FAILURE);
	i = 0;
	philo_greedy = 0;
	while(i < data->routine->nbr_philos)
	{
		pthread_mutex_lock(&data->routine->meals_mutex);
		if (*(data[i])->routine->meals_count >= &data->routine->meals_count)
			philo_greedy++;
		pthread_mutex_unlock(&data->routine->meals_mutex);
		i++;	
	}
	if (philo_greedy == data->routine->nbr_philos)
		return (EXIT_FAILURE);
	return (EXIT_FAILURE);
}

int philo_died(t_data *data)	
{
	pthread_mutex_lock(&data->mutex_over);
	data->routine->stop = 1;
	pthread_mutex_unlock(&data->mutex_over);
	pthread_mutex_lock(&data->routine->meals_mutex);
	printf("%u %d died\n", get_time() - data->routine->start_time, data->id);
	pthread_mutex_unlock(&data->routine->meals_mutex);
	return (EXIT_FAILURE);
}

int can_i_print(t_data *data, char *str)
{
	pthread_mutex_lock(&data->routine->mutex_over);
	if (data->routine->stop == 1 || eat_well(data))
	{
		pthread_mutex_unlock(&data->routine->mutex_over);
		return (EXIT_FAILURE);
	}
	pthread_mutex_unlock(&data->routine->mutex_over);
	pthread_mutex_lock(&data->routine->routine_mutex);
	printf("%u %d %s", get_time()
		- data->routine->start_time, data->id, str);
	pthread_mutex_unlock(&data->routine->routine_mutex);
	return (EXIT_SUCCESS);
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
		if (eat_well(philo) == 1)
			return (print_eat_well(philo));
	}
	return (NULL);
}
