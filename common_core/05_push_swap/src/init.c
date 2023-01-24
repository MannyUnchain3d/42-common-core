/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:09:14 by Manny             #+#    #+#             */
/*   Updated: 2023/01/25 02:29:37 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Fills stack A with numbers from input when there are only 2 arguments,
 * splits argv[1] by space and converts each number to int, if the integers are
 * out of range, frees the stack, prints error and exits */
t_stack	*fill_stack_nb2(char **argv)
{
	t_stack		*stack_a;
	char		**split;
	int			i;
	int			nb;

	stack_a = NULL;
	i = 0;
	split = ft_split(argv[1], ' ');
	while (split[i] != NULL)
	{
		nb = ft_atol(split[i]);
		if (!arg_is_nb(split[i]))
			exit_error_strs(split);
		else if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		else if (i == 0)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	free_split(split);
	return (stack_a);
}

/* Fills stack A with numbers from input, if the integers are out of range,
 * frees the stack, prints error and exits */
t_stack	*fill_stack_nb(int argc, char **argv)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	i = 1;
	if (argc == 2)
		stack_a = fill_stack_nb2(argv);
	else
	{
		while (i < argc)
		{
			nb = ft_atol(argv[i]);
			if (!arg_is_nb(argv[i]))
				exit_error(&stack_a, NULL);
			else if (nb > INT_MAX || nb < INT_MIN)
				exit_error(&stack_a, NULL);
			else if (i == 1)
				stack_a = stack_new((int)nb);
			else
				stack_add_bottom(&stack_a, stack_new((int)nb));
			i++;
		}
	}
	return (stack_a);
}

/* Assigns an index to each nb in stack A, from highest to lowest
 * (from stack_size to 1), easier to compare indexes instead of actual values
 * ex. 	nb:		 4	 2	-6	 9
 *		index:	[3]	[2]	[1]	[4] */
void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		nb;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		nb = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->nb == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->nb > nb && ptr->index == 0)
			{
				nb = ptr->nb;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
