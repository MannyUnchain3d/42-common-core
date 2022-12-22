/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:42:49 by Manny             #+#    #+#             */
/*   Updated: 2022/12/22 20:30:41 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Returns the highest index of the stack */
static int	find_highest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

/* Sorts a stack of 3 numbers in 2 moves or less, by using their indexes
 * ex. 	nb:		 4	 2	-6
 *		index:	[3]	[2]	[1]
 * solution: 2 moves (ra, sa)
 * ra:
 * 		nb:		-6	 4	 2
 * 		index:	[1]	[3]	[2]
 * sa:
 * 		nb:		-6	 2	 4
 * 		index:	[1]	[2]	[3] */
void	sort_3nb(t_stack **stack)
{
	int	highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		ra(stack);
	else if ((*stack)->next->index == highest)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}