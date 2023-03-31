/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:50:51 by tdelgran          #+#    #+#             */
/*   Updated: 2023/03/31 18:06:29 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*read_line(char *line, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr(line, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buffer[bytes_read] = '\0';
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
		{
			i++;
			break ;
		}
		i++;
	}
	if (line[i] && stock != NULL)
		stock = ft_strdup(line + i);
	return (stock);		
}

char	*trim(char *str)
{
	int	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		return (ft_strdup(str + i));
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(char));
	*line = '\0';
	line = read_line(line, fd);
	stock = format_line(line, stock);
	line = trim(line);
    return (stock);
}


// int	main(int ac, char **av)
// {
// 	int		i;
// 	int		fd;
// 	char	*str;
// 	if (ac != 2)
// 	{
// 		printf("Wrong number of arguments !\n");
// 		return (-1);
// 	}
// 	i = 0;
// 	fd = open("coucou.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("open() failed\n");
// 		return (0);
// 	}
// 	while (i++ < atoi(av[1]))
// 	{
// 		printf("\n**************** appel %d **************\n\n", i);
// 		str = get_next_line(fd);
// 		printf("%s", str);
// 	}
// 	if (close(fd) == -1)
// 		printf("close() failed\n");
// 	return (0);
// }

