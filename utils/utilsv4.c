/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsv4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 00:57:46 by almichel          #+#    #+#             */
/*   Updated: 2024/04/27 15:37:13 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strlen_space(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_is_digit(char *str)
{
	int	i;

	i = 0;

	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (-1);
	}
	return (1);
}

int	ft_check_long(char *str)
{

	if (str[0] == '-')
		if (ft_strlen(str) >= ft_strlen("-9223372036854775807"))
			if (check_nbr(str, "-9223372036854775807") == -1)
				return (-1);
	if (str[0] == '+')
		if (ft_strlen(str) >= ft_strlen("+9223372036854775807"))
			if (check_nbr(str, "+9223372036854775807") == -1)
				return (-1);
	if (str[0] != '+' && str[0] != '-')
		if (ft_strlen(str) >= ft_strlen("9223372036854775807"))
			if (check_nbr(str, "9223372036854775807") == -1)
				return (-1);
	return (0);
}

int	check_nbr(char *str, char *cmpr)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > ft_strlen(cmpr))
		return (-1);
	while (str[i])
	{
		if (str[i] <= cmpr[i])
			i++;
		else
			return (-1);
	}
	return (0);
}
long long  ft_atoi_long(const char *nptr)
{
	int			i;
	int			sign;
	long long  result;

	result = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10;
		result = result + nptr[i] - 48;
		i++;
	}
	return (sign * result);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

int check_file(char *str)
{
	int	i;

	i = 0;

	while (str[i])
	{
		if (str[i] == '/')
			return (-1);
		i++;
	}
	return (0);
}