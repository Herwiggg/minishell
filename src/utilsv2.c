/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsv2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:37:45 by nadjemia          #+#    #+#             */
/*   Updated: 2024/04/30 21:17:47 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	word_len(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i] != ' ' && str[i] != 39 && str[i] != 34
		&& str[i++])
		count++;
	return (count);
}

char	*get_env_value(char *str)
{
	char	*var;
	char	*value;

	var = (char *)malloc(sizeof(char) * word_len(str));
	if (!var)
		return (NULL);
	ft_strlcpy(var, str + 1, word_len(str) + 1);
	value = getenv(var);
	free(var);
	return (value);
}

int	total_len_str(char *str, int *index_of_var)
{
	int	count;
	int	i;
	char	*value;
	
	count = ft_strlen(str);
	i = 0;
	while (index_of_var[i] != -1)
	{
		count -= word_len(&str[index_of_var[i]]);
		value = get_env_value(&str[index_of_var[i]]);
		if (value)
			count += ft_strlen(value);
		i++;
	}
	return (count);
}
