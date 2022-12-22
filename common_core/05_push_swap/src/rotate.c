/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:13:53 by Manny             #+#    #+#             */
/*   Updated: 2022/12/22 19:26:45 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Rotates the top element of a stack to the bottom */
static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = stack_find_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

/* Rotates the top element of stack a to the bottom
 * then prints "ra" to stdout */
void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

/* Rotates the top element of stack b to the bottom
 * then prints "rb" to stdout */
void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

/* Rotates the top element of stack a and stack b to the bottom
 * then prints "rr" to stdout */
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
