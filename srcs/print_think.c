/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:07:20 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/26 20:02:05 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int print_think(t_data *data)
{
    printf("%u %d is thinking\n", get_time() - data->routine->start_time, data->id);
    return (EXIT_SUCCESS);
}
