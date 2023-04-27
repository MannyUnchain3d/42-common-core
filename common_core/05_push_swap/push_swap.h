/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:18:10 by Manny             #+#    #+#             */
/*   Updated: 2023/04/27 11:33:45 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> // write
# include <stdlib.h> // malloc, free
# include <stddef.h> // NULL
# include <limits.h> // INT_MAX
# include "libft/libft.h"

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

/* -------- INPUT CHECK --------------- */
int			arg_is_nb(char *argv);
int			arg_is_dup(t_stack *stack_a);

/* -------- INITIALIZE ---------------- */
t_stack		*fill_stack_nb(int argc, char **argv);
t_stack		*fill_stack_nb2(char **argv);
void		assign_index(t_stack *stack_a, int stack_size);

/* -------- POSITION ------------------ */
int			find_lowest_index_pos(t_stack **stack);
void		assign_target_pos(t_stack **stack_a, t_stack **stack_b);

/* -------- COST ---------------------- */
void		find_cost(t_stack **stack_a, t_stack **stack_b);
void		cheapest_move(t_stack **stack_a, t_stack **stack_b);

/* -------- MOVE ---------------------- */
void		move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);

/* -------- OPERATIONS ---------------- */
void		sa(t_stack **stack_a, int print);
void		sb(t_stack **stack_b, int print);
void		ss(t_stack **stack_a, t_stack **stack_b, int print);
void		pa(t_stack **stack_a, t_stack **stack_b, int print);
void		pb(t_stack **stack_a, t_stack **stack_b, int print);
void		ra(t_stack **stack_a, int print);
void		rb(t_stack **stack_b, int print);
void		rr(t_stack **stack_a, t_stack **stack_b, int print);
void		rra(t_stack **stack_a, int print);
void		rrb(t_stack **stack_b, int print);
void		rrr(t_stack **stack_a, t_stack **stack_b, int print);

/* -------- SORTING ALGORITHMS -------- */
int			is_sorted(t_stack *stack);
void		sort_3nb(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);

/* -------- STACK --------------------- */
int			stack_find_size(t_stack *stack);
void		stack_add_bottom(t_stack **stack, t_stack *new);
t_stack		*stack_new(int nb);
t_stack		*stack_find_bottom(t_stack *stack);
t_stack		*stack_find_before_bottom(t_stack *stack);

/* -------- UTILS --------------------- */
int			abs_nb(int nb);
void		free_stack(t_stack **stack);
void		free_split(char **strs);
long		ft_atol(const char *str);

/* -------- ERROR --------------------- */
void		exit_error(t_stack **stack_a, t_stack **stack_b);
void		exit_error_strs(char **strs);

#endif
