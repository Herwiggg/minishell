/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsv2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:37:45 by nadjemia          #+#    #+#             */
/*   Updated: 2024/05/01 15:46:35 by nadjemia         ###   ########.fr       */
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
		&& str[i] && str[i] != '\t')
	{
		i++;
		if (str[i] == '$')
			return (count + 1);
		count++;
	}
	return (count);
}

char	*get_env_value(char *str)
{
	char	*var;
	char	*value;
	char	*result;
	int		len;

	len = word_len(str);
	var = (char *)malloc(sizeof(char) * len);
	if (!var)
		return (NULL);
	ft_strlcpy(var, str + 1, len + 1);
	var[len - 1] = '\0';
	result = ft_strtrim(var, " ");
	value = getenv(result);
	free(var);
	free(result);
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
