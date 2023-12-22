/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfichet <anfichet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:46:07 by anfichet          #+#    #+#             */
/*   Updated: 2023/12/18 12:46:12 by anfichet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(void)
{
	int		file;
	int		i;
	char	*str;

	i = 0;
	file = open("test.txt", O_RDONLY);
	str = get_next_line(file);
	while (str != NULL)
	{
		printf("-%s", str);
		free(str);
		str = get_next_line(file);
		i++;
	}
	close(file);
	return (0);
}
