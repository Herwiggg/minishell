/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:17:07 by almichel          #+#    #+#             */
/*   Updated: 2024/04/20 00:38:23 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// Fonctions qui execute une commande simple du genre ls -l par exemple.
// elle est pas encore dans le main pour l'instant

void	setup_exe_simple_cmd(char *cmd, t_list **env, t_list **exp_var)
{
	pid_t pid = fork();
   			 if (pid == 0)
			 {
				check_and_exe_cmd(cmd, env, exp_var);
				 exit(EXIT_SUCCESS);
			}
			else if (pid > 0)
			{
				 wait(NULL);
				write(1, "\n", 1);
			}
    		else
       	 		perror("fork");
}

void	check_and_exe_cmd(char *cmd, t_list **envp, t_list **exp_var)
{
	char	**cmd1;
	char	**absolut_path;
	char	**total_env;
	int	i;

	i = 0;

	total_env = stock_total_env(envp, exp_var);
	cmd1 = ft_split(cmd, ' ');
	absolut_path = ft_split(cmd, ' ');
	execve(absolut_path[0], cmd1, total_env);
	while (absolut_path[i])
	{
		free(absolut_path[i]);
		i++;
	}
	free(absolut_path);
	ft_relative_path(cmd1, total_env, cmd);
	i = 0;
	free_double_tabs(total_env);
	return;
}

void	ft_relative_path(char **splitted_cmd1, char **envp, char *cmd1)
{
	char	*good_line_envp;
	char	**good_path;
	char	*good_cmd;
	int	i;

	i = 0;
	good_path = NULL;
	good_line_envp = NULL;
	good_cmd = NULL;
	if (envp != NULL)
	{
		while (envp[i])
		{
			if (ft_strncmp("PATH=", envp[i], 5) == 0)
				good_line_envp = envp[i];
			i++;
		}
		if (good_line_envp != NULL)
		{
			good_path = ft_split(good_line_envp, ':');
			i = -1;
			while (good_path[++i])
			{
				good_cmd = ft_strjoin_cmd(good_path[i], cmd1);
				execve(good_cmd, splitted_cmd1, envp);
				free(good_cmd);
			}
		}
	}
	if (good_line_envp != NULL)
		free_double_tabs(good_path);
	ft_putstr_msg(": command not found\n", 2, cmd1);
	free_double_tabs(splitted_cmd1);
}

//Rassemble l'env dans un double tab car execve prends comme argument un double tab
char	**stock_total_env(t_list **envp, t_list **exp_var)
{
	int	len;
	int	i;
	t_list	*head;
	t_list	*current;
	char	**total_env;

	i = 0;
	head = *envp;
	current = *exp_var;
	len = ft_lstlen(envp) + ft_lstlen(exp_var) + 1;
	total_env = malloc(len * sizeof(char *));
	if (!total_env)
		return (NULL);
	if (envp && *envp)
	{
		while (head)
		{
			total_env[i] = ft_strdup(head->content);
			i++;
			head = head->next;
		}
	}
	if (exp_var && *exp_var)
	{
		while (current)
		{
			total_env[i] = ft_strdup(current->content);
			i++;
			current = current->next;
		}
	}
	total_env[i] = NULL;
	return (total_env);
}
