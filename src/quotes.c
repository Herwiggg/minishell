/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:48:20 by nadjemia          #+#    #+#             */
/*   Updated: 2024/04/29 15:18:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*static void	step_aside(char *str, char **ptr_double, char **ptr_single)
{
	int	i;
	int	count;
	int	y;
	
	(void)ptr_single;
	count = 0;
	i = 0;
	while (str[i])
	{
		//printf("%p\n%p\n\n", &str[i], ptr_double[count]);
		if (&str[i] == ptr_double[count])
		{
			y = i - 1;
			while (str[++y])
				str[y] = str[y + 1];
			count++;
		}
		else
			i++;
	}
}*/

static void	ptr_on_quotes2(int *in_quotes, int *count, char **ptr, char *c)
{
	int	i;
	
	i = -1;
	if (!(*in_quotes))
		*in_quotes = 1;
	else
		*in_quotes = 0;
	ptr[*count] = c;
	while (c[++i])
		c[i] = c[i + 1];
	(*count)++;
}

static void	ptr_on_quotes(char *str, char **ptr_double, char **ptr_single)
{
	int	i;
	int	in_double;
	int	in_single;
	int	count_d;
	int	count_s;
	
	count_d = 0;
	count_s = 0;
	in_double = 0;
	in_single = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 34 && !in_single)
			ptr_on_quotes2(&in_double, &count_d, ptr_double, &str[i]);
		else if (str[i] == 39 && !in_double)
			ptr_on_quotes2(&in_single, &count_s, ptr_single, &str[i]);
		else
			i++;
	}
}

static int	rm_quotes(char *str)
{
	char	**ptr_double;
	char	**ptr_single;
	//int	i;
	
	ptr_double = NULL;
	ptr_single = NULL;
	if (!init_ptr_on_quotes(ft_strlen(str), &ptr_double, &ptr_single))
		return (0);
	ptr_on_quotes(str, ptr_double, ptr_single);
	//step_aside(str, ptr_double, ptr_single);
	/*i = 0;
	while (ptr_double[i])
		*ptr_double[i++] = ' ';
	i = 0;
	while (ptr_single[i])
		*ptr_single[i++] = ' ';*/
	free_quotes(ptr_double, ptr_single);
	return (1);
}

int	quotes(char *str)
{
	if (!nbr_quotes(str))
		return (0);
	if (!rm_quotes(str))
		return (0);
	return (1);
}