/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:49:38 by Manny             #+#    #+#             */
/*   Updated: 2022/12/26 19:59:13 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Swaps the top 2 elements of a stack, does nothing if there is 1
 * or no element */
static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->nb;
	stack->nb = stack->next->nb;
	stack->next->nb = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

/* Swaps the top 2 elements of stack A then prints "sa" to stdout */
void	sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

/* Swaps the top 2 elements of stack B then prints "sb" to stdout */
void	sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

/* Swaps the top 2 elements of stack A and stack B
 * then prints "ss" to stdout */
void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}
