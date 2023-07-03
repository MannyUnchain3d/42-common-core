/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etetopat <etetopat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:44:00 by niclaw            #+#    #+#             */
/*   Updated: 2023/06/25 18:58:00 by etetopat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BONUS_H
# define MINISHELL_BONUS_H
# include "minishell.h"

/* ---- PARSER ------------------------ */
t_list	*wild_find(t_list *tokens);
int		is_wild_card(char *str);
char	*ft_strrstr(const char *str, const char *str2);

#endif