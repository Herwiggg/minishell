/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:46:16 by almichel          #+#    #+#             */
/*   Updated: 2024/04/09 00:03:26 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t sigint_received = 0;

void signalHandler(int sig)
{
	sig = sig;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
    rl_redisplay();
    sigint_received = 1;
}

int main(int ac, char **argv, char **envp)
{
	t_data data;
	char *str;
	int 	i;
	char buf[1024];

	signal(SIGINT, &signalHandler);
	signal(SIGQUIT, &signalHandler);
	ac = ac;
	argv = argv;
	data.envp = envp;
	data.pwd = getcwd(buf, sizeof(buf));
	init_lobby(&data);
	i = 0;
	while (1)
	{
		if (sigint_received)
		{
			sigint_received = 0;
		}
		str = readline(data.total_setup);
		if (sigint_received)
		{
			sigint_received = 0;
		}
		if (str == NULL)
		{
			ft_printf("exit\n");
			return (0);
		}
		if (strcmp("env", str) == 0)
			while (envp[i])
				printf("%s\n", envp[i++]);
		else if (strcmp("pwd", str) == 0)
			{
				str = getcwd(buf, sizeof(buf));
				printf("%s\n", str);
			}
		else if(strcmp("exit", str) == 0)
			exit (EXIT_FAILURE);
	
	}
	
}
