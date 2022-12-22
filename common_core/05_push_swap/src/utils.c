/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Manny <etetopat@student.42bangkok.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 22:15:26 by Manny             #+#    #+#             */
/*   Updated: 2022/12/22 12:29:00 by Manny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Returns the absolute value of a number to chose the shortest rotation */
int	abs_nb(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

/* Frees all the elements of the stack and sets its pointer to NULL */
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

/* Converts a string to a long integer */
long int	ft_atoi(const char *str)
{
	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * isneg);
}

/* Prints a string to the standard output */
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{	
		write(1, &str, 1);
		i++;
	}
}
