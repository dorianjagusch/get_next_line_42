/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:23:30 by djagusch          #+#    #+#             */
/*   Updated: 2022/11/14 17:59:15 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_min(size_t a, size_t b)
{
	if (!a && !b)
		return (0);
	if (a < b)
		return (a);
	return (b);
}

size_t	ft_linelen(char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\n' && i < BUFFER_SIZE)
		i++;
	i++;
	return (i);
}

char	*ft_read_whole_line(int *fd, char *line, int iter)
{
	char	*line;
	size_t	i;
	size_t	line_len;

	i = 1;
	*(line + (i * BUFFER_SIZE)) = (char *)malloc(BUFFER_SIZE+ 1);
	if (!line)
		return (NULL);
	read(fd, line, BUFFER_SIZE * i);
	line_len = ft_linelen(*(line + (BUFFER_SIZE * i)))
	if (ft_linelen(line) < BUFFER_SIZE)
	{
			line[line_len + BUFFER_SIZE * (i - 1)] = 0;
			return (line);
	}
	ft_read_whole_line(fd, line, i++);
	ret
	
}

ft_is_end_line(char *line)
{
	size_t	i;
	
	while (line[i] != '\n' && i <= BUFFER_SIZE)
		i++;
}


