/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfichet <anfichet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:38:32 by anfichet          #+#    #+#             */
/*   Updated: 2023/12/19 13:56:51 by anfichet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str, int c);
char	*ft_strjoin(char *s1, char const *s2, size_t *n);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *str, int c);
void	*ft_memmove(char *dest, const char *src, size_t n);
void	ft_bzero(void *s, size_t n);
char	*get_empty_line(char *stash, size_t *n);
int		reading_line(int fd, char *stash, char **next_line, size_t *n);

#endif