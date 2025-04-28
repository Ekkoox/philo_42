/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:06:12 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/28 19:31:03 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_sleep(t_data *data)
{
	printf("%u %d is sleeping\n", get_time() - data->routine->start_time,
		data->id);
	usleep(data->routine->time_to_sleep * 1000);
	return (EXIT_SUCCESS);
}
