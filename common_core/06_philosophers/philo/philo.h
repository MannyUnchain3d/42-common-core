/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:51:21 by Manny             #+#    #+#             */
/*   Updated: 2023/02/12 19:33:35 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define MAX_PHILOS 200
# define STR_MAX_PHILOS "200"
# define STR_PROG_NAME "philo:"
# define STR_USAGE "%s usage: ./philo <number_of_philosophers> <time_to_die> \
<time_to_eat> <time_to_sleep> [numbers_of_time_philosophers_must_eat]\n"
# define STR_ERR_INPUT_DIGIT "%s invalid input: %s: \
is not a valid unsigned integer between 0 and 2147483647.\n"
# define STR_ERR_INPUT_PHILO "%s invalid input: \
Philosophers have to be between 1 and %s.\n"
# define STR_ERR_THREAD "%s error: Could not create thread.\n"
# define STR_ERR_MALLOC "%s error: Could not allocate memory.\n"
# define STR_ERR_MUTEX "%s error: Could not create mutex.\n"

typedef struct s_philo	t_philo;

typedef struct s_table
{
	unsigned int	nb_philos;
	int				must_eat_count;
	bool			sim_stop;
	time_t			start_time;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	pthread_t		manager;
	pthread_mutex_t	sim_stop_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*fork_locks;
	t_philo			**philos;
}	t_table;

typedef struct s_philo
{
	pthread_t		thread;
	unsigned int	id;
	unsigned int	fork[2];
	unsigned int	meal_count;
	pthread_mutex_t	meal_time_lock;
	time_t			last_meal;
	t_table			*table;
}	t_philo;

typedef enum e_status
{
	DIED = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3,
	GOT_FORK_1 = 4,
	GOT_FORK_2 = 5
}	t_status;

/* -------- Input Check --------------- */
bool	is_valid_input(int ac, char **av);
int		digit_atoi(char *str);

/* -------- Initialize ---------------- */
t_table	*init_table(int ac, char **av, int i);

/* -------- Routines ------------------ */
void	*philosopher(void *data);

/* -------- Time ---------------------- */
time_t	get_time_in_ms(void);
void	philo_sleep(t_table *table, time_t sleep_time);
void	sim_start_delay(time_t start_time);

/* -------- Output -------------------- */
void	write_status(t_philo *philo, bool death, t_status status);
void	write_outcome(t_table *table);
void	*error_null(char *str, char *details, t_table *table);
int		msg(char *str, char *details, int exit_nb);

/* -------- Manager ------------------- */
void	*manager(void *data);
bool	sim_has_stopped(t_table *table);

/* -------- Exit ---------------------- */
int		error_failure(char *str, char *infos, t_table *table);
void	*free_table(t_table *table);
void	destroy_mutex(t_table *table);

#endif