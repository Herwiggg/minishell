/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:29:57 by almichel          #+#    #+#             */
/*   Updated: 2024/04/13 00:42:43 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	stock_env(char **env, t_list **envp)
{
	int	i;
	
	t_list	*new_case;

	if (!env)
		return;
	i = 0;
	new_case = NULL;
	while (env[i])
	{
		new_case = ft_lstnew(env[i]);
		ft_lstadd_back(envp, new_case);
		i++;
	}
}
/*
void	update_env(t_data *data)
{
	if (data->stock_envp != NULL)
	{
		
	}
}*/

void	print_env(t_list **envp)
{
	t_list	*top;

	top = *envp;

	while (top)
	{
		ft_printf("%s\n", top->content);
		top = top->next;
	}
}
