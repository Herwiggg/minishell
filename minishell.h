#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft42/libft.h"
# include "./ft_printf/ft_printf.h"

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>

typedef struct s_data
{
	char	**envp;
	char	**export;
	char	*logname;
	char	*mini;
	char	*pwd;
	char	*path;
	char	*extract_pwd;
	char	*total_setup;
	char	*str;
	char 	buf[1024];
}	t_data;

/*-------Init Lobby-------*/
char	*init_lobby(t_data *data);
void	add_minishell(t_data *data);
char	*find_logname(t_data *data);
void	add_pwd(t_data *data);

/*-------Export-------*/
char	*ft_add_declare_x(char *str);
void	ft_export(t_data *data);

/*-------Env-------*/
void	stock_env(char **env, t_list **envp);
void	print_env(t_list **envp);

/*-------Cd-------*/
void	ft_cd(t_data *data);

/*-------Utils-------*/
char 	*ft_strcat(char *dest, char *src);
char 	*ft_str3cat(char *dest, char *src1, char *src2, char *get_total_setup);
char	*ft_return_strcat(char *dest, char *src, char *result);

/*-------Ctrls-------*/
void 	signalHandler(int signum);
char	*get_total_setup(t_data *data);

#endif