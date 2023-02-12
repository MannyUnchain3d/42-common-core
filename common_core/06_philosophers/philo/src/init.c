/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:47:11 by Manny             #+#    #+#             */
/*   Updated: 2023/02/12 20:02:23 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/* Allocates memory and initializes fork mutex.
 * Returns a pointer to the fork mutex array, or NULL if errors */
static pthread_mutex_t	*init_forks(t_table *table)
{
	pthread_mutex_t	*forks;
	unsigned int	i;

	forks = malloc(sizeof(pthread_mutex_t) * table->nb_philos);
	if (!forks)
		return (error_null(STR_ERR_MALLOC, NULL, 0));
	i = 0;
	while (i < table->nb_philos)
	{
		if (pthread_mutex_init(&forks[i], 0) != 0)
			return (error_null(STR_ERR_MUTEX, NULL, 0));
		i++;
	}
	return (forks);
}

/* Assigns 2 forks ids to each philosopher. Even-numbered philosophers
get their fork order switched to avoid deadlocks. Example with 3 philosophers:
 * Philo #1 (id0) takes fork 1 and then fork 0.
 * Philo #2 (id1) takes fork 1 and then fork 2.
 * Philo #3 (id2) takes fork 0 and then fork 2.
 * Philo #1 takes fork 1, philo #3 takes fork 0 and philo #2 waits.
 * Fork 2 is free for philo #3, so he eats.
 * When he is done philo #1 can take fork 0 and eat.
 * When he is done, philo #2 can finally get fork 1 and eat. */
static void	assign_forks(t_philo *philo)
{
	philo->fork[0] = philo->id;
	philo->fork[1] = (philo->id + 1) % philo->table->nb_philos;
	if (philo->id % 2)
	{
		philo->fork[0] = (philo->id + 1) % philo->table->nb_philos;
		philo->fork[1] = philo->id;
	}
}

/* Allocates memory for each philosopher and initializes their values.
 * Returns a pointer to the array of philosophers or NULL if errors. */
static t_philo	**init_philosophers(t_table *table)
{
	t_philo			**philos;
	unsigned int	i;

	philos = malloc(sizeof(t_philo) * table->nb_philos);
	if (!philos)
		return (error_null(STR_ERR_MALLOC, NULL, 0));
	i = 0;
	while (i < table->nb_philos)
	{
		philos[i] = malloc(sizeof(t_philo) * 1);
		if (!philos[i])
			return (error_null(STR_ERR_MALLOC, NULL, 0));
		if (pthread_mutex_init(&philos[i]->meal_time_lock, 0) != 0)
			return (error_null(STR_ERR_MUTEX, NULL, 0));
		philos[i]->table = table;
		philos[i]->id = i;
		philos[i]->meal_count = 0;
		assign_forks(philos[i]);
		i++;
	}
	return (philos);
}

/* Initializes mutex locks for forks, writing and the stop-sim flag.
 * Returns true if successful or false if not. */
static bool	init_global_mutex(t_table *table)
{
	table->fork_locks = init_forks(table);
	if (!table->fork_locks)
		return (false);
	if (pthread_mutex_init(&table->sim_stop_lock, 0) != 0)
		return (error_failure(STR_ERR_MUTEX, NULL, table));
	if (pthread_mutex_init(&table->write_lock, 0) != 0)
		return (error_failure(STR_ERR_MUTEX, NULL, table));
	return (true);
}

/* Initializes the "dining table" a data structure with all the parameters
 * needed for the simulation. Returns a pointer to the allocated table structure
 * or NULL if errors. */
t_table	*init_table(int ac, char **av, int i)
{
	t_table	*table;

	table = malloc(sizeof(t_table) * 1);
	if (!table)
		return (error_null(STR_ERR_MALLOC, NULL, 0));
	table->nb_philos = digit_atoi(av[i++]);
	table->time_to_die = digit_atoi(av[i++]);
	table->time_to_eat = digit_atoi(av[i++]);
	table->time_to_sleep = digit_atoi(av[i++]);
	table->must_eat_count = -1;
		table->must_eat_count = digit_atoi(av[i++]);
	table->philos = init_philosophers(table);
	if (!table->philos)
		return (NULL);
	if (!init_global_mutex(table))
		return (NULL);
	table->sim_stop = false;
	return (table);
}
