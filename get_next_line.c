/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:50:51 by tdelgran          #+#    #+#             */
/*   Updated: 2023/04/06 15:12:00 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *line, int fd, char **stock)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*tmp;

	if (!line)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr(line, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(line);
			if (*stock)
				free(*stock);
			*stock = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(line, buffer);
		free(line);
		line = tmp;
	}
	return (line);
}

char	*format_line(char *line, char **stock)
{
	int		i;
	char	*new_stock;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '\n')
		{
			i++;
			break ;
		}
	}
	if (line[i])
	{
		new_stock = ft_strdup(line + i);
		line[i] = '\0';
	}
	else
		new_stock = NULL;
	free(*stock);
	*stock = new_stock;
	return (line);
}

char	*trim(char *str)
{
	int		i;
	char	*result;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
	{
		result = ft_substr(str, 0, i + 1);
		free(str);
		return (result);
	}
	if (str[0] != '\0')
	{
		result = ft_strjoin(str, "");
		free(str);
		return (result);
	}
	free(str);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup("");
	if (!line)
		return (NULL);
	if (stock)
	{
		free(line);
		line = ft_strdup(stock);
	}
	line = read_line(line, fd, &stock);
	if (line)
	{
		line = format_line(line, &stock);
		line = trim(line);
		if (!line && (!stock || *stock == '\0'))
			free(stock);
	}
	return (line);
}
