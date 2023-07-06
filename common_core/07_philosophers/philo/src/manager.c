/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 22:59:37 by Manny             #+#    #+#             */
/*   Updated: 2023/07/03 15:03:25 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/* Sets the sim_stop flag to true if the sim has stopped or false if not*/
static void	set_sim_stop_flag(t_table *table, bool state)
{
	pthread_mutex_lock(&table->sim_stop_lock);
	table->sim_stop = state;
	pthread_mutex_unlock(&table->sim_stop_lock);
}

/* Checks if the simulation has stopped, the stop flag is protected by a lock
 * to avoid multiple threads checking at the same time.
 * Returns true if the sim_stop flag is true and false if not. */
bool	sim_has_stopped(t_table *table)
{
	bool	ret;

	ret = false;
	pthread_mutex_lock(&table->sim_stop_lock);
	if (table->sim_stop == true)
		ret = true;
	pthread_mutex_unlock(&table->sim_stop_lock);
	return (ret);
}

/* Checks time_to_die with last_meal time. If the philosopher died,
 * sets the sim_stop flag and displays DIED status.
 * Returns true if the philosopher died or false if not. */
static bool	philo_died(t_philo *philo)
{
	time_t	time;

	time = get_time_in_ms();
	if ((time - philo->last_meal) >= philo->table->time_to_die)
	{
		set_sim_stop_flag(philo->table, true);
		write_status(philo, true, DIED);
		pthread_mutex_unlock(&philo->meal_time_lock);
		return (true);
	}
	return (false);
}

/* Checks if the conditions to end the simulation have been met.
 * Stops the sim if a philo died or if he ate enough.
 * Returns true if a condition has been met or false if not. */
static bool	stop_condition_met(t_table *table)
{
	unsigned int	i;
	bool			ate_enough;

	ate_enough = true;
	i = 0;
	while (i < table->nb_philos)
	{
		pthread_mutex_lock(&table->philos[i]->meal_time_lock);
		if (philo_died(table->philos[i]))
			return (true);
		if (table->must_eat_count != -1)
			if (table->philos[i]->meal_count
				< (unsigned int)table->must_eat_count)
				ate_enough = false;
		pthread_mutex_unlock(&table->philos[i]->meal_time_lock);
		i++;
	}
	if (table->must_eat_count != -1 && ate_enough == true)
	{
		set_sim_stop_flag(table, true);
		return (true);
	}
	return (false);
}

/* Checks if a philosopher died and if they all ate enough.
 * Stops the simulation and returns NULL if one the two conditions is met. */
void	*manager(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	if (table->must_eat_count == 0)
		return (NULL);
	set_sim_stop_flag(table, false);
	sim_start_delay(table->start_time);
	while (true)
	{
		if (stop_condition_met(table) == true)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
