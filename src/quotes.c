/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:48:20 by nadjemia          #+#    #+#             */
/*   Updated: 2024/05/01 16:40:58 by nadjemia         ###   ########.fr       */
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

static void	is_interpreted(char *str, int *i, int *index, int *count)
{
	char	*value;
	int		x;
	
	value = get_env_value(str);
	if (value)
		index[(*count)++] = (*i)++;
	else
	{
		(*i)++;
		while (str[0] != ' ' && str[0] != 39 && str[0] != 34
			&& str[0] != '\t' && str[0])
		{
			x = -1;
			while (str[++x])
				str[x] = str[x + 1];
		}
		if (str[0] == 39 || str[0] == 34)
		{
			x = -1;
			while (str[++x])
				str[x] = str[x + 1];
		}
	}
}

static void	trim_quotes(char *str, int *in_single, int *in_double,
			int *index_of_var)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 34 && !(*in_single))
			ptr_on_quotes2(in_double, &str[i]);
		else if (str[i] == 39 && !(*in_double))
			ptr_on_quotes2(in_single, &str[i]);
		else if (str[i] == '$' && !(*in_single) && str[i + 1] != 39
			&& str[i + 1] != 34 && str[i + 1] != ' '
			&& str[i + 1] != '$')
			is_interpreted(str + i, &i, index_of_var, &count);
		else
			i++;
	}
}

static char	*rm_quotes(char *str)
{
	int	*index_of_var;
	int	nbr_ptr;
	int	in_double;
	int	in_single;
	char	*result;
	
	in_double = 0;
	in_single = 0;
	nbr_ptr = 0;
	index_of_var = init_index_of_var(str);
	if (!index_of_var)
		return (NULL);
	trim_quotes(str, &in_single, &in_double, index_of_var);
	int i = 0;
	while (index_of_var[i] != -1)
		printf("index = %d\n", index_of_var[i++]);
	result = interpretation(str, index_of_var);
	if (!result)
		return (NULL);
	return (result);
}

char	*quotes(char *str)
{
	char	*result;
	
	if (!nbr_quotes(str))
		return (NULL);
	result = rm_quotes(str);
	if (!result)
		return (NULL);
	return (result);
}