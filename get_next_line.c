/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:22:58 by djagusch          #+#    #+#             */
/*   Updated: 2022/11/15 11:34:45 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_clear_tmp(char *buf, char **tmp_buf)
{
	char	*tmp;
	
		tmp = ft_strjoin(buf, *tmp_buf);
		free (*tmp_buf);
		return (tmp);
}
static char	*ft_fill_buffer(int fd, char *buf)
{
	char	*tmp_buf;
	long	bytes;

	if (!buf)
		buf = ft_calloc(1, 1);
	bytes = 1;
	tmp_buf = NULL;
	while (bytes > 0)
	{
		bytes = read(fd, tmp_buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		tmp_buf[bytes] = '\0';
		buf = ft_clear_tmp(buf, &tmp_buf);
		if (ft_strchr(buf, '\n'))
			break;
	}
	return (buf);
}

static char *ft_get_line(char *buf)
{
	long	i;
	char	*line;

	i = 0;
	if (!buf[0] || !buf)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	line = ft_calloc(i + 1 + 1, sizeof(char));
	line[i] = '\n';
	while ((i--) >= 0)
		line[i] = buf[i];
	return (line);
}

static char *ft_prep_buffer(char *buf)
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
	tmp = ft_calloc(ft_strlen(buf) - i + 1, sizeof(char));
	while (buf[i])
		tmp[j++] = buf[i++];
	free(buf);
	return (tmp);
}

char *get_next_line(int fd)
{
	static char	*buf;
	char		*cur_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) > 0)
		return (NULL);
	if (!strchr(buf, '\n'))
		buf = ft_fill_buffer(fd, buf);
	if (!buf)
		return (NULL);
	cur_line = ft_get_line(buf);
	buf = ft_prep_buffer(buf);
	return (cur_line);
}
