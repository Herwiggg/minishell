/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:46:16 by almichel          #+#    #+#             */
/*   Updated: 2024/04/07 23:58:53 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **argv, char **envp)
{
	char *str;
	int 	i;
	char buf[1024];
	
	ac = ac;
	argv = argv;
	i = 0;
	while (1)
	{
		str = readline("");
		if (strcmp("env", str) == 0)
			while (envp[i])
				printf("%s\n", envp[i++]);
		else if (strcmp("pwd", str) == 0)
			{
				str = getcwd(buf, sizeof(buf));
				printf("%s\n", str);
			}
	}
	
}
