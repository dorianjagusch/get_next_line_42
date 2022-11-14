/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:22:58 by djagusch          #+#    #+#             */
/*   Updated: 2022/11/14 17:45:39 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*cur_line;
	char		*tmp_nl;
	size_t		line_len;
	size_t		extend;
	
	if (fd <= 0)
		return (NULL);
	if (fd == 2)
	{
		ft_read_stdin(cur_line);
		return (cur_line);
	}
	tmp_nl = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp_nl)
		return (NULL);
	tmp_nl = ft_get_whole_line(&fd);
	cur_line = tmp_nl;
	if (fd == 0)
	{
		if (close(fd) == -1)
			return (NULL);
		ft_putstr("##### Reached end of file #####\n");
	}
	return (cur_line);
}
