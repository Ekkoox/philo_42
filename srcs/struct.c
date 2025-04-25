/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:32:08 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/25 16:55:39 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_struct(t_philo *philo)
{
	// int i;

	// i = 0;
	// while (i < philo->routine.nbr_philos)
	// {
	// 	pthread_mutex_destroy(&philo->data[i].left_fork);
	// 	pthread_mutex_destroy(&philo->data[i].mutex_over);
	// 	pthread_mutex_destroy(&philo->data[i].mutex_time_to_eat);
	// 	i++;
	// }
	if (philo->data)
		free(philo->data);
}
