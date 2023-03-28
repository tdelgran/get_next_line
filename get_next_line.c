/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:50:51 by tdelgran          #+#    #+#             */
/*   Updated: 2023/03/28 16:07:56 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

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
	//free (buffer);
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

char	*trim(char *str)
{
	int	i;
	int	j;
	
	i = 0;
	j = ft_strlen(str) - 1;
	while (str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (NULL);
	while (str[j])
		j--;
	return (str);
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
	stock = trim(line);
	//free(line);
	return (stock);
}

int	main(int ac, char **av)
{
	int		i;
	int		fd;
	char	*str;
	if (ac != 2)
	{
		printf("Wrong number of arguments !\n");
		return (-1);
	}
	i = 0;
	fd = open("coucou.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() failed\n");
		return (0);
	}
	while (i++ < atoi(av[1]))
	{
		printf("\n**************** appel %d **************\n\n", i);
		str = get_next_line(fd);
		printf("%s", str);
	}
	if (close(fd) == -1)
		printf("close() failed\n");
	return (0);
}