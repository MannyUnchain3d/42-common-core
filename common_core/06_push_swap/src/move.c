/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:40:55 by Manny             #+#    #+#             */
/*   Updated: 2023/07/17 03:15:28 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Rotates stack A and B until one of the stack is in position,
 * the cost is positive because numbers are in the top half of the stack,
 * the cost is decremented until one reaches 0 */
static void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b, 0);
	}
}

/* Reverse rotates stack A and B until one of the stack is in position,
 * the cost is negative because numbers are in the bottom half of the stack,
 * the cost is incremented until one reaches 0 */
static void	rev_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a, b, 0);
	}
}

/* Rotates stack A until it is in position, if the cost is positive,
 * the stack will be rotated, if it is negative, it will be reverse rotated */
static void	rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(a, 0);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(a, 0);
			(*cost)++;
		}
	}
}

/* Rotates stack B until it is in position, if the cost is positive,
 * the stack will be rotated, if it is negative, it will be reverse rotated */
static void	rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(b, 0);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(b, 0);
			(*cost)++;
		}
	}
}

/* Rotates or reverse rotates stack A and B until they are in position,
 * if the cost is the same, both stacks will be rotated or reverse rotated
 * at the same time, if the cost is different, it will be done separately
 * for each stack */
void	move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both(a, b, &cost_a, &cost_b);
	rotate_a(a, &cost_a);
	rotate_b(b, &cost_b);
	pa(a, b, 0);
}
