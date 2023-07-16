/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 21:20:36 by Manny             #+#    #+#             */
/*   Updated: 2023/07/17 05:58:14 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Gives the Unix Epoch in milliseconds
(time elapsed since 00:00:00 UTC 01-Jan-1970) */
time_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

/* Puts the philo thread to sleep. Checks at regular intervals if
 * the sim has stopped. Wakes up if the sim has stopped during sleep time */
void	philo_sleep(t_table *table, time_t sleep_time)
{
	time_t	wake_up;

	wake_up = get_time_in_ms() + sleep_time;
	while (get_time_in_ms() < wake_up)
	{
		if (sim_has_stopped(table))
			break ;
		usleep(100);
	}
}

/* Delays the execution of each thread so they can start at the same time,
 * with the same start time reference. Used to synchronize the manager thread
 * with the philos threads */
void	sim_start_delay(time_t	start_time)
{
	while (get_time_in_ms() < start_time)
		continue ;
}
