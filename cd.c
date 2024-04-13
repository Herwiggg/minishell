/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 00:05:45 by almichel          #+#    #+#             */
/*   Updated: 2024/04/13 17:35:30 by almichel         ###   ########.fr       */
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

void	ft_export(t_data *data, t_list **env)
{
	int	i;
	int	j;
	char	*temp;
	int	max;

	j = 0;
	i = 0;
	if (!env)
	{
		ft_printf("env: «export»: Aucun fichier ou dossier de ce type\n");
		return;
	}
	data->export = malloc((ft_lstlen(env)) * sizeof(char *));
	if (!data->export)
		return;
	data->export[i] = NULL;
	max = i;
	i = 0;
	while (i < max - 1)
	{
		j = 0;
		while (j < max - 1)
		{
			if (strcmp(data->envp[j], data->envp[j + 1]) > 0)
			{
				temp = data->envp[j];
                data->envp[j] = data->envp[j + 1];
                data->envp[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (data->envp[i])
	{
		data->export[i] = ft_strdup(data->envp[i]);
		i++;
	}
		
	data->export[i] = '\0';
	i = 0;
	while (data->export[i])
	{
		data->export[i] = ft_add_declare_x(data->export[i]);
		i++;
	}
	i = 0;
	while (data->export[i])
		ft_printf("%s\n", data->export[i++]);
	

}

char	*ft_add_declare_x(char *str)
{
	char	*export;
	int		len;

	len = ft_strlen(str) + 12;
	export = malloc((len) * sizeof(char));
	if (!export)
		return (NULL);
	ft_return_strcat("declare -x ", str, export);
	return (export);
	free(str);
}
