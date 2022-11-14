/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:23:10 by djagusch          #+#    #+#             */
/*   Updated: 2022/11/14 17:49:27 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef get_next_line_H
 
 # define get_next_line_H

 # include "stdlib.h"
 # include <sys/types.h>
 #include <unistd.h>

 # define BUFFER_SIZE 42

char	*get_next_line(int fd);
char	*ft_read_stdin(char *cur_line);
void	ft_putstr(char *s);
size_t	ft_linelen(char *s);

#endif