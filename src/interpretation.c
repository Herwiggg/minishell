/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpretation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:56:39 by nadjemia          #+#    #+#             */
/*   Updated: 2024/04/30 15:35:15 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*static void	replace_interpret(char *str, char *value)
{
	int	i;
	i = 0;
	if (!value)
	{
		while (str[0] )
	}
}*/
static int	void_after(char *str, int index)
{
	if (str[index + 1] == ' ' || str[index + 1] == 39
		|| str[index + 1] == 34 || !str[index + 1] || str[index + 1] == '$')
		return (1);
	return (0);
}

void	interpretation(char *str, int index)
{
	int	i;
	int	count;
	char	*var;
	char	*value;
	
	(void)index;
	i = 0;
	count = 0;
	while (str[i] == 34 || str[i] == 39 || str[i] == ' ')
		i++;
	if (void_after(str, i))
		return ;
	while (str[i] != ' ' && str[i] != 34 && str[i++] != 39)
		count++;
	var = (char *)malloc(sizeof(char) * count);
	ft_strlcpy(var, str + 1, count);
	printf("var = %s\n", var);
	value = getenv(var);
	//replace_interpret(str, value);
	printf("value = %s\n", value);
	free(var);
}
