/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:15:03 by aet-tass          #+#    #+#             */
/*   Updated: 2023/01/12 06:47:25 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_saved(int fd, char *saved)
{
	char	*buffer;
	int		count;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	count = 1;
	if (!buffer)
		return (0);
	while (count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			free(buffer);
			if (saved)
				free(saved);
			return (NULL);
		}
		saved = ft_strjoin(saved, buffer);
		buffer[count] = '\0';
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (saved);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;
	int		bytes;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	bytes = i + 2;
	line = malloc(sizeof(char) * bytes);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
			line [i] = buffer[i];
			i++;
	}
	if (buffer[i] && buffer[i] == '\n')
	{
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	return (line);
}

char	*ft_get_rest(char *buffer)
{
	char	*rest;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	while (buffer[i])
	{
		if (buffer[i] && buffer[i] == '\n')
		{
			rest = ft_substr(buffer, i + 1, ft_strlen(buffer) - (i + 1));
			free (buffer);
			return (rest);
		}
		i++;
	}
	free (buffer);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_get_saved(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_get_rest(buffer);
	return (line);
}
