/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 04:53:35 by aet-tass          #+#    #+#             */
/*   Updated: 2023/01/12 06:04:07 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*cast_str;
	char	cast_c;

	i = 0;
	cast_str = (char *)str;
	cast_c = (char )c;
	while (cast_str[i] != '\0' && cast_str[i] != cast_c)
		i++;
	if (cast_str[i] == cast_c)
		return (&cast_str[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(2) + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	else
	{
		while (s1[i])
			new_str[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
		new_str[j++] = s2[i++];
	new_str[j] = '\0';
	return (new_str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*new_str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (NULL);
	if (start <= ft_strlen(s))
	{
		while (i < len)
		{
			new_str[i] = s[start];
			i++;
			start++;
		}
		new_str[i] = '\0';
	}
	else
		new_str[0] = '\0';
	return (new_str);
}
