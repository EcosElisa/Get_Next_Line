/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrinh <esobrinh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:46:02 by esobrinh          #+#    #+#             */
/*   Updated: 2022/10/27 21:16:56 by esobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*fd_read(int fd, char *full_str)
{
	char		*buffer;
	ssize_t		read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(full_str, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		buffer[read_bytes] = '\0';
		full_str = ft_strjoin(full_str, buffer);
	}
	free (buffer);
	if (read_bytes == -1)
		return (NULL);
	return (full_str);
}

char	*get_line(char *full_str)
{
	int		i;
	char	*line;

	i = 0;
	line = "";
	if (!full_str)
		return (NULL);
	while (full_str[i] && full_str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (full_str[i] && full_str[i] != '\n')
	{
		line[i] = full_str[i];
			i++;
	}
	if (full_str[i] == '\n')
	{
		line[i] = full_str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_rest(char *full_str)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (full_str[i] && full_str[i] != '\n')
		i++;
	if ((full_str[i] == '\n' && full_str[i + 1] == '\0') || !full_str[i])
	{
		free (full_str);
		return (NULL);
	}
	rest = (char *)malloc(sizeof(char) * (ft_strlen(full_str) - i + 1));
	if (!rest)
		return (0);
	i++;
	j = 0;
	while (full_str[i])
		rest[j++] = full_str[i++];
	rest[j] = '\0';
	free(full_str);
	return (rest);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*full_str[1024];

	line = "";
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	full_str[fd] = fd_read(fd, full_str[fd]);
	if (!full_str[fd])
		return (NULL);
	line = get_line(full_str[fd]);
	full_str[fd] = get_rest(full_str[fd]);
	return (line);
}
