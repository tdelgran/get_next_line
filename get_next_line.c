/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:50:51 by tdelgran          #+#    #+#             */
/*   Updated: 2023/02/01 13:17:55 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	back_n(char *str)
{
	int	i;

	i = 0;
	while (str)
	{
		if (str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*res;
	int		read;
	
	buffer = malloc(sizeof(char)) + ()
}