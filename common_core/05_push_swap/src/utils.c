/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:15:26 by Manny             #+#    #+#             */
/*   Updated: 2023/01/25 02:56:52 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Returns the absolute value of a number to choose the shortest rotation */
int	abs_nb(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

/* Frees all the elements of the stack and sets its pointer to NULL */
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

/* Frees all the elements of the array and sets its pointer to NULL */
void	free_split(char **strs)
{
	int	i;

	if (strs != NULL)
	{
		i = 0;
		while (strs[i] != NULL)
		{
			free(strs[i]);
			i++;
		}
		free(strs);
	}
}

/* Writes an error message to the standard error, frees the stacks and exits */
void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

/* Writes an error message to the standard error, frees the array and exits
 * Used only if argv[1] is an array of strings */
void	exit_error_strs(char **strs)
{
	if (strs)
		free_split(strs);
	write(2, "Error\n", 6);
	exit(1);
}
