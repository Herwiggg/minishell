/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:52:04 by nadjemia          #+#    #+#             */
/*   Updated: 2024/05/03 10:19:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	parsing(t_input	*input)
{
	char	*result;

	result = quotes(input->intput_brut);
	if (!result)
		return (printf("minishell : Syntax error\n"), 0);
	printf("%s\n", result);
	input->cmd = result;
	return (1);
}
