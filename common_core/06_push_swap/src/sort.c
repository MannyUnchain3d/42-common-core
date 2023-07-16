/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:42:55 by Manny             #+#    #+#             */
/*   Updated: 2023/07/17 03:15:28 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Pushes all the numbers of stack A into stack B, until there is only 3 numbers
 * left in stack A. Pushes the smaller numbers first to improve efficiency */
void	push_all_but_3(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = stack_find_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			pb(stack_a, stack_b, 0);
			pushed++;
		}
		else
			ra(stack_a, 0);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pb(stack_a, stack_b, 0);
		pushed++;
	}
}

/* Shifts stack A until the smallest number is at the top */
static void	shift_stack(t_stack **stack_a)
{
	int	lowest_index_pos;
	int	stack_size;

	lowest_index_pos = find_lowest_index_pos(stack_a);
	stack_size = stack_find_size(*stack_a);
	if (lowest_index_pos > stack_size / 2)
	{
		while (lowest_index_pos < stack_size)
		{
			rra(stack_a, 0);
			lowest_index_pos++;
		}
	}
	else
	{
		while (lowest_index_pos > 0)
		{
			ra(stack_a, 0);
			lowest_index_pos--;
		}
	}
}

/* Sorting algorithm for more than 3 numbers in a stack.
 * Pushes all numbers from stack A to stack B except for the last 3 numbers.
 * Sorts the last 3 numbers in stack A using sort_3nb.
 * Pushes the numbers back to stack A by calculating the best cost-efficient way.
 * Shifts stack A until the smallest number is at the top */
void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_but_3(stack_a, stack_b);
	sort_3nb(stack_a);
	while (*stack_b)
	{
		assign_target_pos(stack_a, stack_b);
		find_cost(stack_a, stack_b);
		cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}
