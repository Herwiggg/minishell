/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsv2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:33:30 by almichel          #+#    #+#             */
/*   Updated: 2024/04/13 17:34:28 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lstlen(t_list **lst)
{
	t_list	*current;

	current = *lst;
	int	count;

	count = 0;
	while (current)
	{
		current = current->next;
		count++;
	}
	return (count);
}
