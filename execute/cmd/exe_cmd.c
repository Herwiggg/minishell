/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:17:07 by almichel          #+#    #+#             */
/*   Updated: 2024/04/22 01:22:38 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// Fonctions qui executent une commande simple du genre ls -l par exemple.

void	check_redirection(char *str, char *file, int *fd)
{
	if (ft_strcmp(">", str) == 0)
	{
		*fd = open(file, O_WRONLY | O_TRUNC, 0644);
		if (access(file, W_OK) == -1 && access(file, F_OK) == 0)
		{
			ft_putstr_msg(": No such file or directory\n", 2, file);
		}
		else
		{
			*fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
			if (access(file, R_OK) != 0)
				ft_putstr_msg(": Permission denied\n", 2, file);
		}
	}
	else if (ft_strcmp(">>", str) == 0)
	{
		*fd = open(file, O_WRONLY | O_APPEND, 0644);
		if (access(file, W_OK) == -1 && access(file, F_OK) == 0)
		{
			ft_putstr_msg(": No such file or directory\n", 2, file);
		}
		else
		{
			*fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
			if (access(file, R_OK) != 0)
				ft_putstr_msg(": Permission denied\n", 2, file);
		}
	}
	else if (ft_strcmp("<", str) == 0)
	{
		if (access(file, F_OK) != 0)
		{
			ft_putstr_msg(": No such file or directory\n", 2, file);
		}
		else
		{
			*fd = open(file, O_RDONLY);
			if (access(file, R_OK) != 0)
				ft_putstr_msg(": Permission denied\n", 2, file);
		}
	}
}

void	setup_exe_simple_cmd(char *cmd, t_list **env, t_list **exp_var,
		char *file, char *redir)
{
	pid_t	pid;
	int		fd;

	pid = fork();
	if (pid == 0)
	{
		if (file[0] == '.' && file[1] == '/')
			if (chdir(file) != 0)
				{
					ft_putstr_msg(": Aucun fichier ou dossier de ce type", 2, file);
					exit(EXIT_FAILURE);
				}
		check_redirection(redir, file, &fd);
		check_and_exe_cmd(cmd, env, exp_var, fd, redir);
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

void	check_and_exe_cmd(char *cmd, t_list **envp, t_list **exp_var, int fd, char *redir)
{
	char	**cmd1;
	char	**absolut_path;
	char	**total_env;
	int		i;

	i = 0;
	if (redir)
	{
		if (ft_strcmp(redir, ">") == 0 || ft_strcmp(redir, ">>") == 0)
			dup2(fd, STDOUT_FILENO);
		else if (ft_strcmp(redir, "<") == 0)
			dup2(fd, STDIN_FILENO);
	}
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
	return ;
}

void	ft_relative_path(char **splitted_cmd1, char **envp, char *cmd1)
{
	char	*good_line_envp;
	char	**good_path;
	char	*good_cmd;
	int		i;

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

// Rassemble l'env dans un double tab car execve prends comme argument un double tab
char	**stock_total_env(t_list **envp, t_list **exp_var)
{
	int		len;
	int		i;
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
