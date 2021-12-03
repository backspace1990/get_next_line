/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandis <tgrandis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:28:06 by tgrandis          #+#    #+#             */
/*   Updated: 2021/11/26 18:10:57 by tgrandis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
	{
		while (*s)
			s++;
		return ((char *) s);
	}
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	return (NULL);
}

void	*ft_bzero(void *dst, size_t n)
{
	size_t	i;
	char	*tmp_buf;

	tmp_buf = dst;
	i = 0;
	while (i < n)
	{
		*tmp_buf = '\0';
		tmp_buf++;
		i++;
	}
	return (dst);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		return (0);
	ft_bzero(p, count * size);
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	char	*res;
	char	*ptr_s1;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ptr_s1 = (char *) s1;
	mem = malloc(ft_strlen((char *) s1) + ft_strlen((char *) s2) + 2);
	if (!(mem))
	{
		free((char *) s1);
		return (NULL);
	}
	res = mem;
	while (*s1)
		*mem++ = *s1++;
	while (*s2)
		*mem++ = *s2++;
	*mem = 0;
	free((char *) ptr_s1);
	return (res);
}
