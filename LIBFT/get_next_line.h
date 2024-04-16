/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjemia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:03:40 by nadjemia          #+#    #+#             */
/*   Updated: 2024/01/12 14:04:45 by nadjemia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char		*get_next_line(int fd);
void		my_bzero(char *buf, size_t size);
int			ft_isnl(char *buf, int len, int *i);
void		fill(char *buf, char *buffer, size_t size);
char		*ft_str(char *buffer);
size_t		len(char *buffer);
void		ft_clean(char *buffer);
char		*my_strdup(char *str);
int			ft_verif(int r, char *buf, char *buffer);
size_t		my_strlen(char *str);

#endif
