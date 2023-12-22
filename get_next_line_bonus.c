/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfichet <anfichet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:09:31 by anfichet          #+#    #+#             */
/*   Updated: 2023/12/19 13:56:23 by anfichet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	stash[1024][BUFFER_SIZE + 1] = {0};
	char		*next_line;
	size_t		n;

	n = 0;
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (ft_bzero(stash[fd], BUFFER_SIZE + 1), NULL);
	if (ft_strchr(stash[fd], '\n'))
		return (get_empty_line(stash[fd], &n));
	next_line = ft_strdup(stash[fd]);
	if (next_line == 0 || (reading_line(fd, stash[fd], &next_line, &n) == -1))
		return (NULL);
	ft_memmove(stash[fd], &stash[fd][n], ft_strlen(&stash[fd][n], '\0') + 1);
	return (next_line);
}

char	*get_empty_line(char *stash, size_t *n)
{
	char	*next_line;
	char	*temp;

	temp = ft_strdup("");
	if (!temp)
		return (NULL);
	next_line = ft_strjoin(temp, stash, n);
	ft_memmove(stash, (stash + *n), ft_strlen((stash + *n), '\0') + 1);
	return (next_line);
}

int	reading_line(int fd, char *stash, char **next_line, size_t *n)
{
	ssize_t		size_read;

	size_read = 1;
	while (size_read > 0 && !ft_strchr(stash, '\n'))
	{
		size_read = read(fd, stash, BUFFER_SIZE);
		if (size_read == -1)
		{
			ft_bzero(stash, 1);
			return (free(*next_line), -1);
		}
		stash[size_read] = '\0';
		*next_line = ft_strjoin(*next_line, stash, n);
		if (*next_line == 0)
			return (-1);
	}
	if (*next_line[0] == '\0')
		return (free(*next_line), -1);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}
