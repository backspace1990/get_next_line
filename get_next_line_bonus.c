/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandis <tgrandis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:00:30 by tgrandis          #+#    #+#             */
/*   Updated: 2021/11/16 18:00:31 by tgrandis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	*temp++ = '\0';
	str = ft_strjoin(str, buf);
	if (!str)
		return (NULL);
	i = 0;
	while (*temp)
		buf[i++] = *temp++;
	buf[i] = 0;
	adder_nl(&str);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buf[1024][BUFFER_SIZE + 1];
	char		*str;
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	str = ft_calloc(1, sizeof(char) * BUFFER_SIZE + 1);
	if (ft_strchr(buf[fd], '\n'))
		return (get_str_line(buf[fd], str));
	str = ft_strjoin(str, buf[fd]);
	read_bytes = 1;
	while (read_bytes)
	{
		read_bytes = read(fd, buf[fd], BUFFER_SIZE);
		if (read_bytes <= 0 && !*str)
		{
			free(str);
			return (0);
		}
		buf[fd][read_bytes] = 0;
		if (ft_strchr(buf[fd], '\n'))
			return (get_str_line(buf[fd], str));
		str = ft_strjoin(str, buf[fd]);
	}
	return (str);
}
