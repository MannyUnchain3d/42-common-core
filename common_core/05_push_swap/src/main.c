/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:42:41 by Manny             #+#    #+#             */
/*   Updated: 2023/01/12 20:31:55 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

/* Chooses a sorting method depending on amount of nb in stack */
static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		sa(stack_a);
	else if (stack_size == 3)
		sort_3nb(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

/* Checks if input is correct, initializes stack A and B, assign each
 * nb an index and sorts the stack, when sorting is done, frees the stack */
static int	run_push_swap(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (!is_valid_input(argv))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack_nb(argc, argv);
	stack_size = stack_find_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**strs;

	if (argc < 2 || (argc == 2 && (ft_strlen(argv[1]) == 0)))
		return (0);
	if (argc == 2)
	{
		strs = ft_split(argv[1], ' ');
		if (!is_valid_input(strs))
			exit_error_strs(strs);
		run_push_swap(ft_split_size(strs), strs);
		ft_split_free(strs);
		return (0);
	}
	return (run_push_swap(argc, argv));
}
