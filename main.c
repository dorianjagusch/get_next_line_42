/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:44:32 by djagusch          #+#    #+#             */
/*   Updated: 2022/11/15 11:04:11 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_putstr(char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

int main(void)
{
	int fd;
	size_t i;
	
	i = 0;
	fd = open("moby_dick.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() failed");
		return (1);
	}
	while (i < 20000)
	{
		printf("%s", get_next_line(fd));
		ft_putstr("------");
		i++;
	}
	if (close (fd) == -1)
	{
		ft_putstr("open() failed");
		return (1);
	}
	return (0);
}
