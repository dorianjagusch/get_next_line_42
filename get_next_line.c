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

char	*ft_fill_buffer(int fd, char *buf)
{
	char	*tmp_buf;
	size_t	bytes;

	if (!buf)
		buf = ft_calloc(1, 1);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, tmp_buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		tmp_buf[bytes] = '\0';
		buf = ft_strjoin(buf, tmp_buf);
		free (tmp_buf);
		if (strchr(buf, '\n') || ft_strchr(buf, '\0'))
			return (buf);
	}
	return (buf);
}

void ft_get_line(char *buf, char **line)
{
	long	i;

	i = 0;
	if (!buf[0])
		return ;
	while (buf[i] && buf[i] != '\n')
		i++;
	*line = ft_calloc(i + 1 + 1, sizeof(char));
	*line[i] = '\n';
	while ((i--) >= 0)
		*line[i] = buf[i];
	return (line);
}

ft_prep_buffer(char *buf)
{
	long	i;
	long	j;
	char	*tmp;

	if (!buf)
		return (NULL);
	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	tmp = ft_calloc(strlen(buf) - i + 1, sizeof(char));
	while (buf[i])
		tmp[j++] = buf[i++];
	free(buf);
	return (tmp);
}

char *get_next_line(int fd)
{
	static char	*buf;
	char		*cur_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_fill_buffer(fd, buf);
	if (!buf)
		return (NULL);
	cur_line = NULL;
	ft_get_line(buf, &cur_line);
	buf = ft_prep_buffer(buf);
	return (cur_line);
}
