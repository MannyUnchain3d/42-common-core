/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:18:10 by Manny             #+#    #+#             */
/*   Updated: 2022/12/26 16:40:56 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> // write
# include <stdlib.h> // malloc, free
# include <stddef.h> // NULL
# include <limits.h> // INT_MAX

typedef struct s_stack
{
	int				nb;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* -------- Input Check --------------- */
int			is_valid_input(char **argv);
int			is_digit(char c);
int			is_sign(char c);
int			strnb_cmp(const char *s1, const char *s2);

/* -------- Initialize ---------------- */
t_stack		*fill_stack_nb(int argc, char **argv);
void		assign_index(t_stack *stack_a, int stack_size);

/* -------- Position ------------------ */
int			find_lowest_index_pos(t_stack **stack);
void		assign_target_pos(t_stack **stack_a, t_stack **stack_b);

/* -------- Cost ---------------------- */
void		find_cost(t_stack **stack_a, t_stack **stack_b);
void		cheapest_move(t_stack **stack_a, t_stack **stack_b);

/* -------- Move ---------------------- */
void		move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);

/* -------- Operations ---------------- */
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);

/* -------- Sorting Algorithms -------- */
int			is_sorted(t_stack *stack);
void		sort_3nb(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);

/* -------- Stack --------------------- */
int			stack_find_size(t_stack *stack);
void		stack_add_bottom(t_stack **stack, t_stack *new);
t_stack		*stack_new(int nb);
t_stack		*stack_find_bottom(t_stack *stack);
t_stack		*stack_find_before_bottom(t_stack *stack);

/* -------- Utils --------------------- */
int			abs_nb(int nb);
void		free_stack(t_stack **stack);
void		ft_putstr(char *str);
long int	ft_atoi(const char *str);

/* -------- Error --------------------- */
void		exit_error(t_stack **stack_a, t_stack **stack_b);

#endif
