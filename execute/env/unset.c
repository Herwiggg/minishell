/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:57:41 by almichel          #+#    #+#             */
/*   Updated: 2024/04/15 17:41:29 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

//C'est l'inverse d'export, tu peux supprimer des variables de l'env si tu fais par exemple unset PWD, ca va supprimer la ligne pwd de ton env. cette fonction sert a ca
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
        t_list *temp = *ptr; 
        *ptr = temp->next;    
        free(temp->content);  
        free(temp);           
    }
    else
    {
        ptr = &(*ptr)->next; 
    }
}
if (flag == 0)
{
	while(*ptr2)
	{
		if (ft_strncmp((*ptr2)->content, var, ft_len_equal((*ptr2)->content) - 1) == 0)
		{
			t_list *temp2 = *ptr2; 
        	*ptr2 = temp2->next;    
        	free(temp2->content);
        	free(temp2);  
		}
		 else
		 	ptr2 = &(*ptr2)->next;
	}
}

}
