/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandis <tgrandis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:59:19 by tgrandis          #+#    #+#             */
/*   Updated: 2021/11/29 13:38:55 by tgrandis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	adder_nl(char **str)
{
	char	*str_end;

	str_end = *str;
	while (*str_end)
		str_end++;
	*str_end = '\n';
	*++str_end = '\0';
}

static char	*get_str_line(char *buf, char *str)
{
	int			i;
	char		*temp;

	temp = ft_strchr(buf, '\n');
	*temp = '\0';
	*temp++;
	str = ft_strjoin(str, buf);
	if (!str)
		return (NULL);
	i = 0;
	while (*temp)
		buf[i++] = *temp++;
	buf[i] = '\0';
	adder_nl(&str);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*str;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_calloc(1, sizeof(char) * BUFFER_SIZE + 1);
	if (ft_strchr(buf, '\n'))
		return (get_str_line(buf, str));
	str = ft_strjoin(str, buf);
	read_bytes = 1;
	while (read_bytes)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes <= 0 && !*str)
		{
			free(str);
			return (0);
		}
		buf[read_bytes] = 0;
		if (ft_strchr(buf, '\n'))
			return (get_str_line(buf, str));
		str = ft_strjoin(str, buf);
	}
	return (str);
}
