/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:52:04 by nadjemia          #+#    #+#             */
/*   Updated: 2024/04/29 08:36:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	parsing(t_input	*input)
{
	if (!quotes(input->intput_brut))
		return (printf("minishell : Syntax error\n"), 0);
	printf("%s\n", input->intput_brut);
	//printf("%zu\n", mini_split(input->intput_brut));
	input->cmd = input->intput_brut;
	return (1);
}