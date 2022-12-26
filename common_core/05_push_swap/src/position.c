/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:32:56 by Manny             #+#    #+#             */
/*   Updated: 2022/12/26 16:23:40 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Assigns a position to each number in the stack from top to bottom,
 * starting from 0. Used to find the cost of each move.
 * ex. 	nb:		 4	 2	-6 	 9
 * 		index:	[3]	[2]	[1]	[4]
 * 		pos:	[0]	[1]	[2]	[3]
 * the cost of pushing nb 4 to the other stack is 0, for nb 2 it's 1, etc.
 * the cost of rotating nb 9 to the top is 3, for nb 2 it's 1, etc. */
static void	assign_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

/* Returns the position of the number with the lowest index */
int	find_lowest_index_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	assign_position(stack);
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

/* Finds the best target position in stack a for a number in stack b.
 * Checks if there is a number in stack a with the closest biggest index,
 * if so, assigns as target position, if not, assigns to the lowest index
 * ex:	target_pos = INT_MAX
 *		B index: 8
 *		A indexes: 15 10 9 0
 *		15 > 8 && 15 < INT_MAX	target_pos = 0
 *		10 > 8 && 10 < 15		target_pos = 1
 *		9 > 8 && 9 < 10			target_pos = 2
 *		0 < 8 && 0 < 9			target_pos not changed
 *		target_pos = pos of index 9 because it's the closest bigger index
 *
 *  ex:	target_pos = INT_MAX
 *		B index: 8
 *		A indexes: 6 4 3
 *		6 < 8					target_pos not changed
 *		4 < 8					target_pos not changed
 *		3 < 8					target_pos not changed
 *		target_pos is still INT_MAX because there is no bigger index,
 *		so assigns the lowest index instead:
 *		target_pos = pos of index 3 because it's the lowest index (bottom) */
static int	find_target_pos(t_stack **a, int b_idx,
								int target_idx, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

/* Assigns a target position in stack a for each number of stack b.
 * Used to calculate the cost of each move. */
void	assign_target_pos(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	assign_position(a);
	assign_position(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = find_target_pos(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
