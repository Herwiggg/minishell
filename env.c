/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:29:57 by almichel          #+#    #+#             */
/*   Updated: 2024/04/13 23:23:12 by almichel         ###   ########.fr       */
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
		new_case = ft_lstnew(ft_strdup(env[i]));
		ft_lstadd_back(envp, new_case);
		i++;
	}
}

void	update_env(t_list **env)
{
	t_list *current;
	char	buf[1024];
	char 	*cwd;
	int		flag;
	t_list	*new_case;
	char	*new_content;
	
	flag = 0;
	current = *env;
	if (env != NULL)
	{
		update_oldpwd(env);
		while (current)
		{
			if (strncmp(current->content, "PWD=", 4) == 0)
			{
				flag = 1;
				cwd = getcwd(buf, sizeof(buf));
				free(current->content);
				current->content = malloc(((ft_strlen(cwd) + 5) * sizeof(char)));
				current->content = ft_return_strcat("PWD=", cwd, current->content);
			}
			current = current->next;
		}
		if (flag == 0)
		{
			cwd = getcwd(buf, sizeof(buf));
			new_content = malloc(((ft_strlen(cwd) + 5) * sizeof(char)));
			new_content = ft_strcat("PWD=", cwd);
			new_case = ft_lstnew(new_content);
			ft_lstadd_back(env, new_case);
		}
	}
}

void	update_oldpwd(t_list **env)
{
	t_list *current;
	t_list	*new_case;
	int		flag;
	char	*cwd;
	
	flag = 0;
	current = *env;
	cwd = get_actualpwd(env);
	if (cwd == NULL)
	{
		cwd = malloc((7) * sizeof(char));
		if (!cwd)
			return;
		ft_strcpy(cwd, "OLDPWD=", 7);
	}
	while (current)
		{
			if (strncmp(current->content, "OLDPWD=", 7) == 0)
			{
				flag = 1;
				free(current->content);
				current->content = cwd;
			}
			current = current->next;
		}
		if (flag == 0)
		{
			new_case = ft_lstnew(cwd);
			ft_lstadd_back(env, new_case);
		}

}

char	*get_actualpwd(t_list **env)
{
	t_list	*current;
	char	*cwd;

	current = *env;
	while (current)
	{
		if (strncmp(current->content, "PWD=", 4) == 0)
		{
			cwd = malloc(((ft_strlen(current->content) + 4) * sizeof(char)));
			if (!cwd)
				return (NULL);
			ft_strcpy(cwd, "OLD", 3);
			cwd = ft_strcat(cwd, current->content);
			return (cwd);
		}
		current = current->next;
	}
	return (NULL);
}

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
