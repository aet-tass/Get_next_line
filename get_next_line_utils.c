#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

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
	while(cast_str[i] != '\0' && cast_str[i] != cast_c)
		i++;
	if(cast_str[i] == cast_c)
			return (&cast_str[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = malloc(sizeof(char) * len);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (!s1)
		s1 = strdup("\0");
	else
	{
		while (s1[i])
		{
			new_str[j++] = s1[i++];
		}
	}
	i = 0;
	while (s2[i])
		new_str[j++] = s2[i++];
	new_str[j] = '\0';
	return (new_str);
}

char	*ft_strdup(char *s1)

{
	char	*str;
	int		len;
	int		i;

	len = ft_strlen(s1) + 1;	
	str = (char *)malloc(sizeof(char) * len);
	if(!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
