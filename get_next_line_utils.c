/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfichet <anfichet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:09:53 by anfichet          #+#    #+#             */
/*   Updated: 2023/12/19 13:56:33 by anfichet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str, int c)
{
	size_t	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len])
	{
		if (c == str[len])
			return (len + 1);
		len++;
	}
	return (len);
}

void	*ft_memmove(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (((char *)src) == 0 && ((char *)dest) == 0)
		return (dest);
	if (dest < src)
	{
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	if (dest > src)
	{
		while (n != 0)
		{
			((char *)dest)[n - 1] = ((char *)src)[n - 1];
			n--;
		}
		return (dest);
	}
	dest[n] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, const char *s2, size_t *n)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = malloc((ft_strlen(s1, '\0') + ft_strlen(s2, '\n') + 1));
	if (result == 0)
		return (free(s1), NULL);
	ft_bzero(result, (ft_strlen(s1, '\0') + ft_strlen(s2, '\n') + 1));
	while (s1[++i])
		result[i] = s1[i];
	while (s2[++j] && s2[j] != '\n')
		result[i + j] = s2[j];
	if (s2[j] == '\n')
		result[i + j] = '\n';
	if (result [i + j] == '\n')
		*n = j + 1;
	else
		*n = j;
	return (free(s1), result);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc((ft_strlen((char *)src, '\0') + 1));
	if (dest == 0)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return (&((char *)str)[i + 1]);
	return (NULL);
}
