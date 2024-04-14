/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:10:18 by almichel          #+#    #+#             */
/*   Updated: 2024/04/15 00:06:59 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(t_data *data, t_list **env, t_list **exp_var)
{
	int		i;
	int		j;
	char	*temp;
	int		max;
	t_list	*current;
	t_list	*head;

	head = *exp_var;
	current = *env;
	j = 0;
	i = 0;
	if (!env)
	{
		ft_printf("env: «export»: Aucun fichier ou dossier de ce type\n");
		return ;
	}
	i = ft_lstlen(env);
	if (exp_var != NULL)
		i = i + ft_lstlen(exp_var);
	data->export = malloc((i + 1) * sizeof(char *));
	if (!data->export)
		return ;
	data->export[i] = NULL;
	i = 0;
	while (current)
	{
		data->export[i] = malloc(ft_strlen(current->content) + 12);
		ft_strcpy_wn(data->export[i], "declare -x ", 12);
		ft_strcat(data->export[i], current -> content);
		current = current->next;
		i++;
	}
	while (head)
	{
		data->export[i] = malloc(ft_strlen(head->content) + 12);
		ft_strcpy_wn(data->export[i], "declare -x ", 12);
		ft_strcat(data->export[i], head -> content);
		head = head->next;
		i++;
	}
	max = i;
	i = 0;
	while (i < max - 1)
	{
		j = 0;
		while (j < max - 1)
		{
			if (strcmp(data->export[j], data -> export[j + 1]) > 0)
			{
				temp = data->export[j];
				data->export[j] = data->export[j + 1];
				data->export[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (data->export[i])
		ft_printf("%s\n", data->export[i++]);
	i = 0;
	while (data->export[i])
	{
		free(data->export[i]);
		i++;
	}
	free(data->export);
}

void	export_variable(t_list **env, t_list **exp_var, char *var)
{
	t_list	*current;
	int		flag;
	t_list	*new_case;
	t_list	*head;

	if (exp_var)
		head = *exp_var;
	flag = 0;
	if (ft_check_equal(var) == -1)
		return ;
	current = *env;
	while (current)
	{
		if (ft_strncmp(current->content, var, ft_len_equal(var)) == 0)
		{
			flag = 1;
			free(current->content);
			current->content = var;
		}
		current = current->next;
	}
	if (exp_var != NULL && flag == 0)
	{
		while (head)
		{
			if (ft_strncmp(head->content, var, ft_len_equal(var)) == 0)
			{
				flag = 1;
				free(head->content);
				head->content = var;
			}
			head = head->next;
		}
	}
	if (flag == 0)
	{
		new_case = ft_lstnew(var);
		ft_lstadd_back(exp_var, new_case);
	}
}
