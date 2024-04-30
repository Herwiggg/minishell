#ifndef MINISHELL_H
# define MINISHELL_H

# include "../LIBFT/libft.h"
//# include "../ft_printf/ft_printf.h"      //&noah

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>

//&Structures noah
typedef struct s_input
{
	char	*intput_brut;
	char	*cmd;
	char	*cmd_opt;
	char	**args;
}	t_input;

//?Structures Alexy
typedef struct s_data
{
	char	**envp;
	char	*logname;
	char	*mini_logname;
	char	*mini;
	char	*pwd;
	char	*extract_pwd;
	char	*total_setup;
}	t_data;


/*//?Foncions d'alexy*/

char 	*ft_strcat(char *dest, char *src);
char 	*ft_str3cat(char *dest, char *src1, char *src2);
void	init_lobby(t_data *data);
void	add_minishell(t_data *data);
char	*find_logname(t_data *data);
void	add_pwd(t_data *data);
void 	signalHandler(int signum);

/*//&Fonctions de noah*/
int		parsing(t_input *input);
int		quotes(char *str);
int		nbr_quotes(char *str);
void		interpretation(char *str, int index);

#endif