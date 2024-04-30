/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpretation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:56:39 by nadjemia          #+#    #+#             */
/*   Updated: 2024/04/30 21:21:49 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	*init_index_of_var(char *str)
{
	int	count;
	int	i;
	int	*index;
	
	count = 0;
	i = 0;
	while (str[i])
		if (str[i++] == '$')
			count++;
	index = (int *)malloc(sizeof(int) * (count + 1));
	i = 0;
	while (i < count + 1)
		index[i++] = -1;
	return (index);
}

/*static void	replace_interpret(char *str, char *value)
{
	int		i;
	int		tmp;
	char	*result;
	i = 0;
	while (str[i] != '$')
		i++;
	while (str[i] != 39 && str[i] != 34 && str[i] != ' ' && str[i])
	{
		tmp = i - 1;
		while (str[++tmp])
			str[tmp] = str[tmp + 1];
	}
	if (value)
	{
		result = insert(str, value);
		str = result;
	}

}*/

/*static int	void_after(char *str, int index)
{
	if (str[index + 1] == ' ' || str[index + 1] == 39
		|| str[index + 1] == 34 || !str[index + 1] || str[index + 1] == '$')
		return (1);
	return (0);
}*/

static void	var_to_val(char *dest, char *str, int *index_of_var)
{
	int		i;
	int		y;
	int		count;
	int		z;
	char	*value;

	count = 0;
	i = 0;
	y = 0;
	while (str[i])
	{
		if (i == index_of_var[count])
		{
			value = get_env_value(str + i);
			z = 0;
			if (value)
			{
				while (value[z])
					dest[y++] = value[z++];
				i += z;
			}
			else
				dest[y++] = str[i++];
		}
		else
			dest[y++] = str[i++];
	}
	dest[y] = '\0';
}

char	*interpretation(char *str, int *index_of_var)
{
	int	i;
	int	total_len;
	char	*result;
	
	i = 0;
	total_len = total_len_str(str, index_of_var);
	if (total_len < 0)
		return (NULL);
	result = (char *)malloc(sizeof(char) * total_len + 1);
	if (!result)
		return (NULL);
	var_to_val(result, str, index_of_var);
	free(index_of_var);
	return (result);
}
