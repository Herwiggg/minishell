/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:52:04 by nadjemia          #+#    #+#             */
/*   Updated: 2024/04/30 14:48:00 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	parsing(t_input	*input, char **env)
{
	if (!quotes(input->intput_brut, env))
		return (printf("minishell : Syntax error\n"), 0);
	printf("%s\n", input->intput_brut);
	//printf("%zu\n", mini_split(input->intput_brut));
	input->cmd = input->intput_brut;
	return (1);
}