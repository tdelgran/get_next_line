/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:50:51 by tdelgran          #+#    #+#             */
/*   Updated: 2023/04/04 15:30:06 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*read_line(char *line, int fd)
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

	if (!line)
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			// printf("dwadwadaw\n");
			i++;
			break ;
		}
		i++;
	}
	if (line[i])
	{
		new_stock = ft_strdup(line + i);
		free(*stock);
		*stock = new_stock;
		line[i - 1] = '\0';
	}
	else
	{
		free(*stock);
		*stock = NULL;
	}
	if (line[0] == '\0' && i > 0)
	{
		free(line);
		return (ft_strdup("\n"));
	}
	return (line);
	}

char	*trim(char *str)
{
	int		i;
	char	*result;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
	{
		result = ft_substr(str, 0, i + 1);
		if (!result)
			return (NULL);
		free(str);
		return (result);
	}
	if (str[0] != '\0') // Ajout de cette condition pour inclure le caractère de retour à la ligne
	{
		result = ft_strjoin(str, "\n");
		free(str);
		return (result);
	}
	else
	{
		free(str);
		return (NULL);
	}
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
	line = read_line(line, fd);
	if (line)
	{
		line = format_line(line, &stock);
		line = trim(line);
		if (!line && (stock == NULL || *stock == '\0'))
			free(stock);
	}
	return (line);
}

// int main ()
// {
// 	int fd = open("coucou.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));

// }

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
