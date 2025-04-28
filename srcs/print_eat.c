/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:31:55 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/28 19:42:51 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_eat_pair(t_data *data)
{
	pthread_mutex_lock(&data->left_fork);
	printf("%u %d has taken left fork\n", get_time()
		- data->routine->start_time, data->id);
	pthread_mutex_lock(data->right_fork);
	printf("%u %d has taken right fork\n", get_time()
		- data->routine->start_time, data->id);
	printf("%u %d is eating\n", get_time() - data->routine->start_time,
		data->id);
	pthread_mutex_lock(&data->mutex_time_to_eat);
	data->time_last_meal = get_time();
	pthread_mutex_unlock(&data->mutex_time_to_eat);
	pthread_mutex_lock(&data->routine->meals_mutex);
	data->eat++;
	pthread_mutex_unlock(&data->routine->meals_mutex);
	usleep(data->routine->time_to_eat * 1000);
	pthread_mutex_unlock(data->right_fork);
	pthread_mutex_unlock(&data->left_fork);
	return (EXIT_SUCCESS);
}

int	print_eat(t_data *data)
{
	if (data->id % 2 == 0)
		return (print_eat_pair(data));
	pthread_mutex_lock(data->right_fork);
	printf("%u %d has taken right fork\n", get_time()
		- data->routine->start_time, data->id);
	pthread_mutex_lock(&data->left_fork);
	printf("%u %d has taken left fork\n", get_time()
		- data->routine->start_time, data->id);
	printf("%u %d is eating\n", get_time() - data->routine->start_time,
		data->id);
	pthread_mutex_lock(&data->mutex_time_to_eat);
	data->time_last_meal = get_time();
	pthread_mutex_unlock(&data->mutex_time_to_eat);
	pthread_mutex_lock(&data->routine->meals_mutex);
	data->eat++;
	pthread_mutex_unlock(&data->routine->meals_mutex);
	usleep(data->routine->time_to_eat * 1000);
	pthread_mutex_unlock(&data->left_fork);
	pthread_mutex_unlock(data->right_fork);
	return (EXIT_SUCCESS);
}
