/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:31:55 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/29 15:32:46 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	print_eat_even(t_data *data)
{
	pthread_mutex_lock(&data->left_fork);
	can_i_print(data, FORK);
	pthread_mutex_lock(data->right_fork);
	can_i_print(data, FORK);
	can_i_print(data, EAT);
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

static int	print_eat_odd(t_data *data)
{
	pthread_mutex_lock(data->right_fork);
	can_i_print(data, FORK);
	pthread_mutex_lock(&data->left_fork);
	can_i_print(data, FORK);
	can_i_print(data, EAT);
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

int print_eat(t_data *data)
{
	if (check_death(data->routine) == 1)
		return (philo_died(data),EXIT_FAILURE);
	if (data->id % 2 == 0)
		print_eat_even(data);
	else
		print_eat_odd(data);
	return (EXIT_SUCCESS);
}
