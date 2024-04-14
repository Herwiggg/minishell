/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:57:41 by almichel          #+#    #+#             */
/*   Updated: 2024/04/15 00:34:11 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_list **env, t_list **exp_var, char *var)
{
t_list **ptr = env; 
t_list	**ptr2 = exp_var;
int flag = 0;

while (*ptr)
{
    if (ft_strncmp((*ptr)->content, var, ft_len_equal((*ptr)->content) - 1) == 0)
    {
        flag = 1;
        t_list *temp = *ptr;  // Sauvegarder le nœud à supprimer
        *ptr = temp->next;    // Faire pointer le pointeur actuel vers le nœud suivant
        free(temp->content);  // Libérer la mémoire du contenu
        free(temp);           // Libérer la mémoire du nœud
    }
    else
    {
        ptr = &(*ptr)->next;  // Passer à l'adresse du pointeur au nœud suivant
    }
}
if (flag == 0)
{
	while(*ptr2)
	{
		if (ft_strncmp((*ptr2)->content, var, ft_len_equal((*ptr2)->content) - 1) == 0)
		{
			t_list *temp2 = *ptr2;  // Sauvegarder le nœud à supprimer
        	*ptr2 = temp2->next;    // Faire pointer le pointeur actuel vers le nœud suivant
        	free(temp2->content);
        	free(temp2);  
		}
		 else
		 	ptr2 = &(*ptr2)->next;
	}
}

}
