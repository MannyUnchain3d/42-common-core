/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 03:49:54 by Manny             #+#    #+#             */
/*   Updated: 2023/01/26 07:14:20 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

/* Checks if a stack is sorted, returns 0 if sorted or 1 if it's not */
int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	ftstrncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] != '\0' && s2[i] != '\0')
		&& (i < n - 1) && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*check_op(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (!ft_strncmp(line, "sa", 2) && (line[2] == '\n' || line[2] == '\0'))
		sa(stack_a, 1);
	else if (!ft_strncmp(line, "sb", 2) && (line[2] == '\n' || line[2] == '\0'))
		sb(stack_b, 1);
	else if (!ft_strncmp(line, "ss", 2) && (line[2] == '\n' || line[2] == '\0'))
		ss(stack_a, stack_b, 1);
	else if (!ft_strncmp(line, "pa", 2) && (line[2] == '\n' || line[2] == '\0'))
		pa(stack_a, stack_b, 1);
	else if (!ft_strncmp(line, "pb", 2) && (line[2] == '\n' || line[2] == '\0'))
		pb(stack_a, stack_b, 1);
	else if (!ft_strncmp(line, "ra", 2) && (line[2] == '\n' || line[2] == '\0'))
		ra(stack_a, 1);
	else if (!ft_strncmp(line, "rb", 2) && (line[2] == '\n' || line[2] == '\0'))
		rb(stack_b, 1);
	else if (!ft_strncmp(line, "rr", 2) && (line[2] == '\n' || line[2] == '\0'))
		rr(stack_a, stack_b, 1);
	else if (!ftstrncmp(line, "rra", 3) && (line[3] == '\n' || line[3] == '\0'))
		rra(stack_a, 1);
	else if (!ftstrncmp(line, "rrb", 3) && (line[3] == '\n' || line[3] == '\0'))
		rrb(stack_b, 1);
	else if (!ftstrncmp(line, "rrr", 3) && (line[3] == '\n' || line[3] == '\0'))
		rrr(stack_a, stack_b, 1);
	else
		exit_error(stack_a, stack_b);
	return (get_next_line(0));
}

void	checker(t_stack **stack_a, t_stack **stack_b, char *line)
{
	char	*tmp;

	while (line)
	{
		tmp = line;
		line = check_op(stack_a, stack_b, line);
		free(tmp);
	}
	if (*stack_b)
		write(1, "KO\n", 3);
	else if (is_sorted(*stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(line);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = fill_stack_nb(argc, argv);
	if (!stack_a || arg_is_dup(stack_a))
		exit_error(&stack_a, NULL);
	line = get_next_line(0);
	if (!line && is_sorted(stack_a))
		write(1, "OK\n", 3);
	else if (!line && !is_sorted(stack_a))
		write(1, "KO\n", 3);
	else
		checker(&stack_a, &stack_b, line);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
