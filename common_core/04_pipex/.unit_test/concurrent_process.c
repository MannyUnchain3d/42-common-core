/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concurrent_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:53:24 by Manny             #+#    #+#             */
/*   Updated: 2023/07/18 16:53:33 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>

void	child_process(int process_num)
{
	struct timeval	start_time;
	struct timeval	end_time;

	gettimeofday(&start_time, NULL);

	printf("Child process %d started at %ld seconds %ld microseconds.\n",
		process_num, start_time.tv_sec, start_time.tv_usec);

	usleep((process_num + 1) * 500000);

	gettimeofday(&end_time, NULL);

	printf("Child process %d finished at %ld seconds %ld microseconds.\n",
		process_num, end_time.tv_sec, end_time.tv_usec);
}

int	main(void)
{
	const int	num_processes = 3;

	for (int i = 0; i < num_processes; i++)
	{
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
			child_process(i + 1);
			exit(EXIT_SUCCESS);
		}
	}

	for (int i = 0; i < num_processes; i++) {
		wait(NULL);
	}

	return (0);
}
