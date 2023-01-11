/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:15:03 by aet-tass          #+#    #+#             */
/*   Updated: 2023/01/11 04:31:09 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
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
			break;
		saved = ft_strjoin(saved, buffer);
	    buffer[count] = '\0';
		if (ft_strchr(buffer, '\n'))
			break;
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
		line[i] = '\0';
		line[i+1] = '\n';
	}
	return (line);
}

char *get_next_line(int fd)
{
	static char	*buffer;
	char	*line;

	buffer = ft_get_saved(fd, buffer);
	line  = ft_get_line(buffer);
	return (line);
	
}

int	main()
{
	int	fd;
	fd = open("ayoub.txt", O_RDWR);
	char	str[100]="tassehasaratarapaeinprobasubject\nwelldone";
	printf("%s", ft_get_line(str));
}
