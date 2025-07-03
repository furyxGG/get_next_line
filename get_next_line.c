/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 05:35:59 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/07/03 14:05:26 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*allines;
	char		*line;
	char		*temp;
	int 		bytesize;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!allines)
		allines = ft_addall(fd);
	if (!allines)
		return (NULL);
	temp = ft_strchr(allines, '\n');
	if (temp)
		bytesize = temp - allines + 1;
	else
		bytesize = ft_strlen(allines);
	line = ft_substr(allines, 0, bytesize);
	if ()
	{
		
	}
	//free(temp);
	return (line);
}

int main()
{
	int fd = open("deneme.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
