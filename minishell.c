/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:46:16 by almichel          #+#    #+#             */
/*   Updated: 2024/04/08 02:02:04 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_logname(t_data *data)
{
	int	i;
	int	j;
	int	temp;
	int	len;

	len = 0;
	j = 0;
	i = 0;
	if (!data->envp)
		return (NULL);
	while (data->envp[i])
	{
		if (ft_strncmp(data->envp[i], "USERNAME", 8) == 0)
			break;
		i++;
	}
	if (data->envp[i] == NULL)
		return (NULL);
	while (data->envp[i][j] && data->envp[i][j] != '=')
		j++;
	j++;
	temp = j;
	while (data->envp[i][j] && data->envp[i][j] != '\n')
	{
		len++;
		j++;
	}
	j = temp;
	data->logname = malloc(((len + 1) * sizeof(char)));
	if (!data->logname)
		return (NULL);
	temp = 0;
	while (data->envp[i][j])
	{
		data->logname[temp] = data->envp[i][j];
		j++;
		temp++;
	}	
	data->logname[temp] = '\0';
	return (data->logname);
}

void	init_lobby(t_data *data)
{
	data->logname = find_logname(data);
	if (!data->logname)
	{
		data->logname = malloc((5 * sizeof(char)));
		if (!data->logname)
			return;
		ft_strcpy(data->logname, "user", 5);
	}
	printf("%s\n", data->logname);
}

int main(int ac, char **argv, char **envp)
{
	t_data data;
	//char *str;
	//int 	i;
	//char buf[1024];
	
	ac = ac;
	argv = argv;
	data.envp = envp;
	init_lobby(&data);
	//i = 0;
	/*while (1)
	{
		str = readline("");
		if (strcmp("env", str) == 0)
			while (envp[i])
				printf("%s\n", envp[i++]);
		else if (strcmp("pwd", str) == 0)
			{
				str = getcwd(buf, sizeof(buf));
				printf("%s\n", str);
			}
	}*/
	
}
