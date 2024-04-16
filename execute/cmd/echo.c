/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:08:30 by almichel          #+#    #+#             */
/*   Updated: 2024/04/16 13:48:53 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// Fonction echo, c'est juste un printf et je check si y'a l'option -n
void	ft_echo(char *str, int n_option)
{
	int	i;

	i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	if (n_option != -1)
		write(1, "\n", 1);
	
}
