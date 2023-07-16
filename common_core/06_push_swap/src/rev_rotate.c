/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:26:55 by Manny             #+#    #+#             */
/*   Updated: 2023/07/17 03:15:28 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Rotates the bottom element of a stack to the top */
static void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tail = stack_find_bottom(*stack);
	before_tail = stack_find_before_bottom(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

/* Rotates the bottom element of stack A to the top
 * then prints "rra" to stdout */
void	rra(t_stack **stack_a, int print)
{
	rev_rotate(stack_a);
	if (print == 0)
		ft_putstr("rra\n");
}

/* Rotates the bottom element of stack B to the top
 * then prints "rrb" to stdout */
void	rrb(t_stack **stack_b, int print)
{
	rev_rotate(stack_b);
	if (print == 0)
		ft_putstr("rrb\n");
}

/* Rotates the bottom element of stack A and stack B to the top
 * then prints "rrr" to stdout */

void	rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	if (print == 0)
		ft_putstr("rrr\n");
}
