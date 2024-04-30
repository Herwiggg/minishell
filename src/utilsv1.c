/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsv1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <nadjemia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:59:35 by almichel          #+#    #+#             */
/*   Updated: 2024/04/30 19:53:31 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/argp.h"

char *ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char *ft_str3cat(char *dest, char *src1, char *src2)
{

	int	i;
	int	j;
	int	k;

	k = 0;
	j = 0;
	i = 0;
	while (dest[i])
		i++;
	while (src1[j])
	{
		dest[i] = src1[j];
		i++;
		j++;
	}
	while (src2[k])
	{
		dest[i] = src2[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (dest);
}
