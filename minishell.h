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
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <termios.h>

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
void	ft_export(t_data *data, t_list	**env, t_list **exp_var);
void	update_env(t_list **env);
void	export_variable(t_list	**env, t_list **exp_var, char *var);

/*-------Env-------*/
void	stock_env(char **env, t_list **envp);
void	print_env(t_list **envp, t_list	**exp_var);
void	update_oldpwd(t_list **env);
char	*get_actualpwd(t_list **env);

/*-------Cd-------*/
void	ft_cd(t_data *data, t_list **env);
void	ft_cd_home(t_data *data, t_list **env);
void	get_home_path(t_data *data, t_list	**env);

/*-------Unset-------*/
void	ft_unset(t_list **env, t_list **exp_var, char *var);

/*-------Ctrls-------*/
void 	signalHandler(int signum);
char	*get_total_setup(t_data *data);
int		ft_count_words(const char *s, char c);


/*-------echo------*/
void	ft_echo(char *str, int n_option, t_list **env, t_list **exp_var, int *fd);
char	*find_echo_var(char *str, t_list **env, t_list **exp_var, int *flag);

/*-------Cmds-------*/
void	setup_exe_simple_cmd(char *cmd, t_list **env, t_list **exp_var,
		char *file, char *redir);
void	check_and_exe_cmd(char *cmd, t_list **envp, t_list **exp_var, int fd, char *redir);
void	ft_relative_path(char **splitted_cmd1, char **envp, char *cmd1);
char	**stock_total_env(t_list **envp, t_list **exp_var);
char	*ft_strjoin_cmd(char const *s1, char const *s2);
void	check_redirection(char *str, char *file, int *fd);

/*-------Utils-------*/
char 	*ft_strcat(char *dest, char *src);
char 	*ft_str3cat(char *dest, char *src1, char *src2, char *get_total_setup);
char	*ft_return_strcat(char *dest, char *src, char *result);
int		ft_lstlen(t_list **lst);
void	ft_strcpy_wn(char *dest, char *src, int size);
int 	ft_len_equal(char *str);
int 	ft_check_equal(char *str);
void	ft_free_lists(t_list **env, t_list **exp_var);
void	ft_putstr_msg(char *s, int fd, char *str);
void	free_double_tabs(char **str);
char	*ft_strjoin_error(char const *s1, char const *s2);
int		ft_strlen_space(const char *str);
int		ft_strcmp(char *s1, char *s2);

#endif