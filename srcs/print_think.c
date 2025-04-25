/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:07:20 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/25 16:23:52 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int print_think(t_philo *philo)
{
    printf("philo %u %d has think", get_time() - philo->routine.start_time, philo->data->id);
    return (EXIT_SUCCESS);
}
