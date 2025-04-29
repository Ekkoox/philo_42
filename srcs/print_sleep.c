/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:06:12 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/29 15:31:42 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_sleep(t_data *data)
{
	can_i_print(data, SLEEP);
	usleep(data->routine->time_to_sleep * 1000);
	return (EXIT_SUCCESS);
}
