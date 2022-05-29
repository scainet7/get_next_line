/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:58:01 by snino             #+#    #+#             */
/*   Updated: 2021/12/26 19:20:28 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strchr(char *s, int c)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)s;
	while (str[i] != '\0' && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return (str + i);
	else
		return (0);
}

static char	*ft_check_end(ssize_t byte, char *line)
{
	if (!byte && line[byte] == '\0')
	{
		free(line);
		return (0);
	}
	return (line);
}

static char	*ft_read_line(char *line, char **save, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	byte_read;

	byte_read = 1;
	while (byte_read)
	{
		byte_read = read (fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(line);
			return (0);
		}
		buffer[byte_read] = '\0';
		line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n'))
		{
		*save = ft_strdup(ft_strchr(line, '\n') + 1);
		line = ft_substr(line, 0, ft_strlen(line) - ft_strlen(*save));
			break ;
		}
	}
	return (ft_check_end(byte_read, line));
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[256];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (0);
	if (!save[fd])
		save[fd] = ft_strdup("");
	line = ft_strdup(save[fd]);
	free(save[fd]);
	save[fd] = NULL;
	line = ft_read_line(line, &save[fd], fd);
	return (line);
}
