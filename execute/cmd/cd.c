/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 00:05:45 by almichel          #+#    #+#             */
/*   Updated: 2024/04/15 18:20:34 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// Fonction principale de cd, le message d'erreur est temporaire c'etait juste un test
//  A chaque cd, je dois update le dossier dans le quel on se trouve
// la fonction update_env que j'appelle permet d'update la ligne PWD et OLDPWD de l'env a chaque cd

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

//Quand tu fais cd ~ ca te ramene a ton HOME, cette fonction permet de faire ca
void	ft_cd_home(t_data *data, t_list **env)
{
	data->path = NULL;
	get_home_path(data, env);
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
// J'extrait la variable Home de mon env pour la donner a la fonction au dessus
void	get_home_path(t_data *data, t_list	**env)
{
	t_list	*current;

	current = *env;

	while (current)
	{
		if (ft_strncmp("HOME=", current->content, 5) == 0)
			data->path = current->content + 5;
		current = current->next;
	}
}
