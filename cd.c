/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 00:05:45 by almichel          #+#    #+#             */
/*   Updated: 2024/04/15 16:54:51 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction principale de cd, le message d'erreur est temporaire c'etait juste un test
//  A chaque cd, je dois update le dossier dans le quel on se trouve
// la fonction update_env que j'appelle permet d'update la ligne PWD et OLDPWD a chaque cd

void	ft_cd(t_data *data, t_list **env)
{

	data->path = data->str + 3;
	if (chdir(data->path) == 0)
			{
				data->pwd = getcwd(data->buf, sizeof(data->buf));
				free(data->total_setup);
				data->total_setup = init_lobby(data);
				update_env(env);
			}
			else
				ft_printf("cannot access\n");
}



