#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

size_t	ft_strlen(char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);

#endif
