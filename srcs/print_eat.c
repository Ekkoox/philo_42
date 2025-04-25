/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:31:55 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/25 18:18:03 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int print_eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->left_fork);
    printf("%u %d has taken a fork\n", get_time() - philo->routine.start_time, philo->data->id);
    pthread_mutex_lock(philo->data->right_fork);
    printf("%u %d has taken a fork\n", get_time() - philo->routine.start_time, philo->data->id);
    pthread_mutex_lock(&philo->data->mutex_time_to_eat);
    printf("%u %d is eating\n", get_time() - philo->routine.start_time, philo->data->id);
    return (EXIT_SUCCESS);
}
