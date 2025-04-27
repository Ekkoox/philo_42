/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:32:24 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/27 20:14:33 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	destroy_mutex(t_philo *philo)
// {
// 	if (&philo->routine->stop_mutex == 1)
// 		pthread_mutex_destroy(&philo->routine->stop_mutex);
// 	if (&philo->routine->meals_mutex == 2)
// 		pthread_mutex_destroy(&philo->routine->meals_mutex);
// 	if (&philo->data->left_forks == 3)
// 		pthread_mutex_destroy(&philo->data->left_forks);
// 	if (&philo->data->right_forks == 4)
// 		pthread_mutex_destroy(&philo->data->right_forks);
// }

// int	check_philo(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo);
// }
//check si manager a um philo mort, si oui exit les autres
