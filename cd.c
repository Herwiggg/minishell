/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 00:05:45 by almichel          #+#    #+#             */
/*   Updated: 2024/04/14 02:14:33 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(t_data *data, t_list **env)
{

	data->path = data->str + 3;
	if (chdir(data->path) == 0)
			{
				data->pwd = getcwd(data->buf, sizeof(data->buf));
				free(data->total_setup);
				data->total_setup = init_lobby(data);
				update_env(env);
			}
			else
				ft_printf("cannot access\n");
}

void	ft_export(t_data *data, t_list	**env)
{
	int	i;
	int	j;
	char	*temp;
	int		max;
	t_list	*current;

	current = *env;
	j = 0;
	i = 0;
	if (!env)
	{
		ft_printf("env: «export»: Aucun fichier ou dossier de ce type\n");
		return;
	}
	i = ft_lstlen(env);
	data->export = malloc((i + 1) * sizeof(char *));
	if (!data->export)
		return;
	data->export[i] = NULL;
	i = 0;
	while (current)
	{
		data->export[i] = malloc(ft_strlen(current->content) + 12);
		ft_strcpy_wn(data->export[i], "declare -x ", 12);
		ft_strcat(data->export[i], current->content);
		current = current->next;
		i++;
	}
	max = i;
	i = 0;
	while (i < max - 1)
	{
		j = 0;
		while (j < max - 1)
		{
			if (strcmp(data->export[j], data->export[j + 1]) > 0)
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

