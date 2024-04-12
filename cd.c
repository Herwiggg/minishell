/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 00:05:45 by almichel          #+#    #+#             */
/*   Updated: 2024/04/12 01:29:57 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(t_data *data)
{

	data->path = data->str + 3;
	if (chdir(data->path) == 0)
			{
				data->pwd = getcwd(data->buf, sizeof(data->buf));
				//free(data->total_setup);
				data->total_setup = init_lobby(data);

			}
			else
				ft_printf("cannot access\n");
}
