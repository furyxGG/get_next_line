/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 05:35:59 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/07/10 01:26:29 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*takedata(int fd, char *allines)
{
	char	*buff;
	char	*tmp;
	int		bytesize;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytesize = 1;
	while (!ft_strchr(allines, '\n') && bytesize > 0)
	{
		bytesize = read(fd, buff, BUFFER_SIZE);
		if (bytesize == -1)
		{
			free(allines);
			free(buff);
			return (NULL);
		}
		buff[bytesize] = '\0';
		tmp = ft_strjoin(allines, buff);
		free(allines);
		allines = tmp;
	}
	free(buff);
	return (allines);
}

static char	*giveline(char **allines)
{
	char	*newpos;
	char	*line;
	int		a;

	a = 0;
	while ((*allines)[a] && (*allines)[a] != '\n')
		a++;
	if ((*allines)[a] == '\n')
		a++;
	line = ft_substr(*allines, 0, a);
	newpos = ft_substr(*allines, a, ft_strlen(*allines) - a);
	free(*allines);
	*allines = newpos;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*allines[4048];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	allines[fd] = takedata(fd, allines[fd]);
	if (!allines[fd] || allines[fd][0] == '\0')
	{
		free(allines[fd]);
		allines[fd] = NULL;
		return (NULL);
	}
	line = giveline(&allines[fd]);
	return (line);
}
