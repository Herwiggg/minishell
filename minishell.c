/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:46:16 by almichel          #+#    #+#             */
/*   Updated: 2024/05/06 00:03:26 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	sigint_received = 0;

// Ca c'est ce qui permet de faire un retour a la ligne a chaque ctrl C et quitte le programme quand tu ctrl D
void	signalHandler(int sig)
{
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	else
	{
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	sigint_received = 1;
}

int	main(int ac, char **argv, char **envp)
{
	t_list	*env;
	t_data	data;
	t_list	*exp_var;
	t_code	code;
	int		len;
	char	**double_tab;
	int		i;

	code.code = 0;
	exp_var = NULL;
	env = NULL;
	data.path = NULL;
	signal(SIGINT, signalHandler);
	signal(SIGQUIT, signalHandler);
	ac = ac + 0;
	argv = argv + 0;
	stock_env(envp, &env);
	data.envp = envp;
	data.pwd = getcwd(data.buf, sizeof(data.buf));
	data.total_setup = init_lobby(&data);
	data.str = NULL;
	len = 0;
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
			exit (code.code);
		}
		if (strcmp("env", data.str) == 0)
		{
			print_env(&env, &exp_var);
		}
		else if (strncmp("pwd", data.str, 3) == 0)
		{
			print_pwd(data.str, &code);
		}
		else if (strncmp("exit", data.str, 4) == 0)
		{
			ft_exit(data.str, &env, &exp_var, &code);
			exit(code.code);
		}
		else if (strncmp("cd ~", data.str, 4) == 0)
		{
			ft_cd_home(&data, &env);
		}
		else if (strncmp("cd", data.str, 2) == 0)
		{
			ft_cd(&data, &env, &exp_var, &code);
		}
		else if (strncmp("export", data.str, 6) == 0 && len > 1)
		{
			i = 1;
			while (i < len)
			{
				export_variable(&env, &exp_var, double_tab[i], &code);
				i++;
			}
		}
		else if (strncmp("export", data.str, 6) == 0 && len < 2)
			ft_export(&data, &env, &exp_var);
		else if (strncmp("unset", data.str, 5) == 0 && len > 1)
		{
			i = 1;
			while (i < len)
			{
				ft_unset(&env, &exp_var, double_tab[i], &code);
				i++;
			}
		}
		else if (strncmp("echo test", data.str, 9) == 0)
			setup_exe_simple_cmd(data.str, &env, &exp_var, "outfile", "<", &code);
		else if (ft_strncmp(data.str, "ls", 2) == 0)
		{
			char 	**envv = stock_total_env(&env, &exp_var);
			main_pipes(ft_count_words(data.str, ' ') + 1, ft_split(data.str, ' '), envv, &code, data.str);
		}
	
	}
	exit(code.code);
}
