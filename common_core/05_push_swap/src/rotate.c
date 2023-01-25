/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:13:53 by Manny             #+#    #+#             */
/*   Updated: 2023/01/25 15:54:42 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Rotates the top element of a stack to the bottom */
static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tail = stack_find_bottom(*stack);
	tail->next = tmp;
	tmp->next = NULL;
}

/* Rotates the top element of stack A to the bottom
 * then prints "ra" to stdout */
void	ra(t_stack **stack_a, int print)
{
	rotate(stack_a);
	if (print == 0)
		ft_putstr("ra\n");
}

/* Rotates the top element of stack B to the bottom
 * then prints "rb" to stdout */
void	rb(t_stack **stack_b, int print)
{
	rotate(stack_b);
	if (print == 0)
		ft_putstr("rb\n");
}

/* Rotates the top element of stack A and stack B to the bottom
 * then prints "rr" to stdout */
void	rr(t_stack **stack_a, t_stack **stack_b, int print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (print == 0)
		ft_putstr("rr\n");
}
