/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:50:51 by tdelgran          #+#    #+#             */
/*   Updated: 2023/02/17 10:48:16 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	back_n(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char	*buffer [BUFFER_SIZE + 1];
	char	*res;
	char	*temp;
	int		ret;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        if (!res[fd])
            res[fd] = ft_strdup(buffer);
        else
        {
            temp = ft_strjoin(res[fd], buffer);
            free(res[fd]);
            res[fd] = temp;
        }
        if (ft_strchr(res[fd], '\n'))
            break ;
    }
    if (ret == 0 && !res[fd])
    {
        return (ft_strdup(""));
    }
    if (ret == -1)
        return (NULL);
    temp = ft_strjoin(res[fd], '\0');
    free(res[fd]);
    res[fd] = NULL;
    return (temp);
}
