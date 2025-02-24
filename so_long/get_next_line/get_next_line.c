/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:21:14 by eel-garo          #+#    #+#             */
/*   Updated: 2025/02/24 11:20:14 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*ft_filljoin(char *line, const char *str_buf, const char *buf)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str_buf[i])
	{
		line[i] = str_buf[i];
		i++;
	}
	j = 0;
	while (buf[j])
	{
		line[i] = buf[j];
		i++;
		j++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_add(char *map, char *buffer)
{
	char	*new_buff;
	size_t	len;

	if (!map && !buffer)
		return (NULL);
	if (!map)
		return (ft_strdup(buffer));
	if (!buffer)
		return (ft_strdup(map));
	len = ft_strlen(map) + ft_strlen(buffer);
	new_buff = malloc((len + 1) * sizeof(char));
	if (!new_buff)
		return (NULL);
	new_buff = ft_filljoin(new_buff, map, buffer);
	free(map);
	return (new_buff);
}

static char	*ft_process_line(char **map_line)
{
	char		*newline_pos;
	char		*line;
	char		*remaining;

	newline_pos = ft_strchr(*map_line, '\n');
	if (newline_pos)
	{
		*newline_pos = '\0';
		line = ft_strdup(*map_line);
		remaining = ft_strdup(newline_pos + 1);
		free(*map_line);
		*map_line = remaining;
		return (line);
	}
	if (*map_line && **map_line)
	{
		line = ft_strdup(*map_line);
		free(*map_line);
		*map_line = NULL;
		return (line);
	}
	return (free(*map_line), *map_line = NULL, NULL);
}

static int	ft_read_and_store(int fd, char **map_line, char *buffer)
{
	ssize_t	bytes_read;
	char	*newline_pos;

	while (1)
	{
		if (*map_line)
			newline_pos = ft_strchr(*map_line, '\n');
		else
			newline_pos = NULL;
		if (newline_pos)
			return (1);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (bytes_read);
		buffer[bytes_read] = '\0';
		*map_line = ft_add(*map_line, buffer);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*map_line;
	char		*buffer;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = ft_read_and_store(fd, &map_line, buffer);
	free(buffer);
	if (bytes_read < 0 || !map_line)
		return (free(map_line), map_line = NULL, NULL);
	return (ft_process_line(&map_line));
}
