/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:50:51 by tdelgran          #+#    #+#             */
/*   Updated: 2023/03/03 16:25:23 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *line, int fd)
{
	char	*buffer;
	ssize_t	bytes_read;
	
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes_read = BUFFER_SIZE;
	while (bytes_read == BUFFER_SIZE && ft_strchr(line, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		line = ft_strjoin(line, buffer);
	}
	return (line);
}

void	format_line(char *line, char *stock)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			break ;
		i++;
	}
	
}

char    *get_next_line(int fd)
{
	char		*line;
	static char	*stock;
	
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = malloc(sizeof(char));
	*line = '\0';
	line = read_line(line, fd);
	format_line(line, stock);
	return (line);
}


