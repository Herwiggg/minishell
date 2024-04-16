/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:46:16 by almichel          #+#    #+#             */
/*   Updated: 2024/04/16 13:28:42 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t sigint_received = 0;

// Ca c'est ce qui permet de faire un retour a la ligne a chaque ctrl C et quitte le programme quand tu ctrl D
void signalHandler(int sig)
{
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_replace_line("", 1);
		rl_redisplay();
	}
	rl_replace_line("", 1);
	rl_on_new_line();
    rl_redisplay();
    sigint_received = 1;
}

int main(int ac, char **argv, char **envp)
{
	t_list *env;
	t_data data;
	t_list	*exp_var;

	exp_var = NULL;
	env = NULL;
	data.path = NULL;
	signal(SIGINT, &signalHandler);
	signal(SIGQUIT, &signalHandler);
	ac = ac + 0;
	argv = argv + 0;
	stock_env(envp, &env);
	data.envp = envp;
	data.pwd = getcwd(data.buf, sizeof(data.buf));
	data.total_setup = init_lobby(&data);
	data.str = NULL;
	int	len;
	len = 0;
	char	**double_tab;
	while (1)
	{
		if (sigint_received)
		{
			sigint_received = 0;
		}
		data.str = readline(data.total_setup);
		if (data.str != NULL)
		{
			len = ft_count_words(data.str, ' ');
			if (len > 1)
				double_tab = ft_split(data.str, ' ');
			add_history(data.str);
		}
		
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
		{
				print_env(&env, &exp_var);
		}
		else if (strcmp("pwd", data.str) == 0)
			{
				data.str = NULL;
				data.str = getcwd(data.str, 0);
				printf("%s\n", data.str);
				free(data.str);
			}
		else if(strcmp("exit", data.str) == 0)
		{
			ft_free_lists(&env, &exp_var);
			exit (EXIT_FAILURE);
		}
		else if (strncmp("cd ~", data.str, 4) == 0)
			ft_cd_home(&data, &env);
		else if (strncmp("cd", data.str, 2) == 0)
			ft_cd(&data, &env);
		else if (strncmp("export", data.str, 6) == 0 && len > 1)
		{
			int	i = 1;
			while (i < len)
			{
				export_variable(&env, &exp_var, double_tab[i]);
				i++;
			}
		}
		else if (strncmp("export", data.str, 6) == 0 && len < 2)
			ft_export(&data, &env, &exp_var);
		else if (strncmp("unset", data.str, 5) == 0 && len > 1)
		{
			int	i = 1;
			while (i < len)
			{
				ft_unset(&env, &exp_var, double_tab[i]);
				i++;
			}
		}

		else if (strncmp("echo", data.str, 4) == 0)
			ft_echo(data.str, 1);
	}
}

