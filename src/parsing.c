/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:52:04 by nadjemia          #+#    #+#             */
/*   Updated: 2024/05/02 14:38:41 by nadjemia         ###   ########.fr       */
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
	//printf("%zu\n", mini_split(input->intput_brut));
	input->cmd = result;
	return (1);
}