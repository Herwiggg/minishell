/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:48:20 by nadjemia          #+#    #+#             */
/*   Updated: 2024/04/13 12:52:42 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	nbr_quotes(char *str)
{
	int	i;
	int	dbl;
	int	sngl;

	i = 0;
	dbl = 0;
	sngl = 0;
	while (str[i])
	{
		if (str[i] == 39)
			dbl++;
		if (str[i] == 34)
			sngl++;
		i++;
	}
	if (dbl % 2 || sngl % 2)
		return (0);
	return (1);
}

int	quotes(char *str)
{
	if (!nbr_quotes(str))
		return (0);
	return (1);
}