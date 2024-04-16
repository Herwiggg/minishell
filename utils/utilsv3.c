/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsv3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:12:33 by almichel          #+#    #+#             */
/*   Updated: 2024/04/15 23:30:01 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_lists(t_list **env, t_list **exp_var)
{
	t_list *current;
	t_list *head;

	current = *env;
	head = *exp_var;
	if (env && *env)
	{
		while (*env)
		{
			current = (*env)->next;
			free((*env)->content);
			free(*env);
			(*env) = current;
		}
	}
	if (exp_var && *exp_var)
	{
		while (*exp_var)
		{
			head = (*exp_var)->next;
			free((*exp_var)->content);
			free(*exp_var);
			(*exp_var) = head;
		}
	}
}
