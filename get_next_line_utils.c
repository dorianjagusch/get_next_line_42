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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s2;

	i = 0;
	s2 = s;
	while (i < n)
		s2[i++] = '\0';
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem_arr;

	if ((nmemb * size) / nmemb != size && size > 0 && nmemb > 0)
		return (NULL);
	mem_arr = (void *)malloc(sizeof(*mem_arr) * (nmemb * size));
	if (!mem_arr)
		return (NULL);
	ft_bzero(mem_arr, nmemb * size);
	return (mem_arr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	result = (char *) malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!result)
		return (NULL);
	while (s1[i] != '\0')
	{
		result[i] = (char) s1[i];
		i++;
	}
	while (s2[i - len_s1] != '\0')
	{
		result[i] = (char) s2[i - len_s1];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *) s;
	while (str[i] != c % 256 && str[i] != '\0')
		i++;
	if (str[i] != '\0' || c == '\0')
		return (str + i);
	return (NULL);
}
