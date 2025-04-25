/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:06:12 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/25 16:23:47 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int print_sleep(t_philo *philo)
{
    printf("philo %u %d has sleep", get_time() - philo->routine.start_time, philo->data->id);
    return (EXIT_SUCCESS);
}
