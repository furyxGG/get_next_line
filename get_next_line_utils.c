/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 05:36:21 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/07/06 07:35:11 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	a;

	if (!s)
		return (0);
	a = 0;
	while (s[a])
		a++;
	return (a);
}

void	ft_addall(char **allfile, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		bytes;

	*allfile = (char *)malloc(1);
	*allfile[0] = '\0';
	bytes = read(fd, buff, BUFFER_SIZE);
	while (bytes > 0)
	{
		buff[bytes] = '\0';
		*allfile = ft_strjoin(*allfile, buff);
		bytes = read(fd, buff, BUFFER_SIZE);
	}
}

char	*ft_strchr(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		a;
	int		b;

	if (!s1)
	{
		s1 = (char *)malloc (1 * sizeof(char));
		s1[0] = '\0';
	}
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	a = 0;
	b = 0;
	while (s1[a])
		str[b++] = s1[a++];
	a = 0;
	while (s2[a])
		str[b++] = s2[a++];
	if (s1)
		free(s1);
	str[b] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subptr;
	size_t	a;

	a = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		subptr = (char *)malloc(1 * sizeof(char));
		if (!subptr)
			return (0);
		subptr[0] = '\0';
		return (subptr);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	subptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!subptr)
		return (0);
	while (a < len)
	{
		subptr[a++] = s[start++];
	}
	subptr[a] = '\0';
	return (subptr);
}
