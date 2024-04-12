/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:46:16 by almichel          #+#    #+#             */
/*   Updated: 2024/04/12 02:04:02 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t sigint_received = 0;

void signalHandler(int sig)
{
	sig = sig + 0;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
    rl_redisplay();
    sigint_received = 1;
}

int main(int ac, char **argv, char **envp)
{
	t_data data;
	int 	i;
	
	data.path = NULL;
	signal(SIGINT, &signalHandler);
	signal(SIGQUIT, &signalHandler);
	ac = ac + 0;
	argv = argv + 0;
	data.envp = envp;
	data.pwd = getcwd(data.buf, sizeof(data.buf));
	data.total_setup = init_lobby(&data);
	i = 0;
	data.str = NULL;
	while (1)
	{
		if (sigint_received)
		{
			sigint_received = 0;
		}
		data.str = readline(data.total_setup);
		if (data.str != NULL)
			add_history(data.str);
		if (sigint_received)
		{
			sigint_received = 0;
		}
		if (data.str == NULL)
		{
			ft_printf("exit\n");
			return (0);
		}
		if (strcmp("env", data.str) == 0)
			while (envp[i])
				printf("%s\n", envp[i++]);
		else if (strcmp("pwd", data.str) == 0)
			{
				data.str = NULL;
				data.str = getcwd(data.str, 0);
				printf("%s\n", data.str);
				free(data.str);
			}
		else if(strcmp("exit", data.str) == 0)
			exit (EXIT_FAILURE);
		else if (strncmp("cd", data.str, 2) == 0)
			ft_cd(&data);

	
	}
	
}
