/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsv2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:58:58 by nadjemia          #+#    #+#             */
/*   Updated: 2024/04/29 09:28:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	init_ptr_on_quotes(size_t len, char ***ptr_double, char ***ptr_single)
{
	size_t	i;
	
	*ptr_double = (char **)malloc(sizeof(char *) * (len + 1));
	*ptr_single = (char **)malloc(sizeof(char *) * (len + 1));
	if (!(*ptr_double) || !(*ptr_single))
		return (0);
	i = 0;
	while (i < len)
	{
		(*ptr_double)[i] = NULL;
		(*ptr_single)[i] = NULL;
		i++;
	}
	return (1);
}

void	free_quotes(char **ptr_double, char **ptr_single)
{
	free(ptr_double);
	free(ptr_single);
}

/* JE PENSE QUE CA NOUS SERVIRA A RIEN FINALEMENT

static int	white_space(char c)
{
	if (c == ' ' || c == '\r' || c == '\v' || c == '\n'
		|| c == '\t' || c == '\b')
		return (1);
	return (0);
}

static void	in_quotes(char *str, int index, int *dbl, int *sngl)
{
	if (index == 0 && str[index] == 34)
		*dbl = 1;
	else if (index == 0 && str[index] == 39)
		*sngl = 1;
	else if (str[index - 1] == 34 && *dbl == 0)
		*dbl = 1;
	else if (str[index - 1] == 39)
	{
		if (*sngl)
			*sngl = 0;
		else
			*sngl = 1;
	}
}

static size_t	nbr_words(char *str)
{
	size_t	nbr;
	int		i;
	int		in_dbl;
	int		in_sngl;
	
	in_dbl = 0;
	in_sngl = 0; 
	nbr = 0;
	i = -1;
	while (str[++i])
	{
		printf("dbl = %d, sngl = %d\n", in_dbl ? 1 : 0, in_sngl ? 1 : 0);
		in_quotes(str, i, &in_dbl, &in_sngl);
		if (i == 0 && !white_space(str[i]))
			nbr++;
		else if (white_space(str[i - 1]) && !white_space(str[i])
			&& !in_dbl && !in_sngl)
			nbr++;
		else if (!white_space(str[i]) && (white_space(str[i + 1])
			|| str[i + 1] == '\0') && !in_dbl && !in_sngl)
			nbr++;
	}
	return (nbr / 2);
}

size_t	mini_split(char *str)
{
	return (nbr_words(str));
}
*/