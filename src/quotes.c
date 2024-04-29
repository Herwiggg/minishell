/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:48:20 by nadjemia          #+#    #+#             */
/*   Updated: 2024/04/29 15:33:25 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	ptr_on_quotes2(int *in_quotes, char *c)
{
	int	i;
	
	i = -1;
	if (!(*in_quotes))
		*in_quotes = 1;
	else
		*in_quotes = 0;
	while (c[++i])
		c[i] = c[i + 1];
}

static void	rm_quotes(char *str)
{
	int	i;
	int	in_double;
	int	in_single;

	in_double = 0;
	in_single = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 34 && !in_single)
			ptr_on_quotes2(&in_double, &str[i]);
		else if (str[i] == 39 && !in_double)
			ptr_on_quotes2(&in_single, &str[i]);
		else
			i++;
	}
}

int	quotes(char *str)
{
	if (!nbr_quotes(str))
		return (0);
	rm_quotes(str);
	return (1);
}