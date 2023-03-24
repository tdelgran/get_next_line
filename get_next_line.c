/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:50:51 by tdelgran          #+#    #+#             */
/*   Updated: 2023/03/24 12:25:21 by tdelgran         ###   ########.fr       */
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

char	*format_line(char *line, char *stock)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			break ;
		i++;
	} //line[i] vaut \n apres la boucle
	if (line[i])
		stock = ft_strdup(line + i);
	return (stock);		
}

char	*hanmin_trim(char *str)
{
	char	*start;
	char	*end;
	char	*trimmed;

	if (!str)
		return (NULL);
	start = str;
	while (*start == ' ' || *start == '\t' || *start == '\n')
		start++;
	end = str + ft_strlen(str) - 1;
	while (end > start && (*end == ' ' || *end == '\t' || *end == '\n'))
		end--;
	trimmed = ft_strdup(start + 1);
	return (trimmed);
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
	stock = format_line(line, stock);
	stock = hanmin_trim(line);
	return (line);
}
