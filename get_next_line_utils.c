/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:50:54 by tdelgran          #+#    #+#             */
/*   Updated: 2023/03/24 12:01:13 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*titi;
	int		i;

	if (!s1 || !s2)
		return (0);
	titi = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!titi)
		return (0);
	i = 0;
	while (*s1 != '\0')
	{
		titi[i] = *s1;
		s1++;
		i++;
	}
	// free(s1);
	while (*s2 != '\0')
	{
		titi[i] = *s2;
		s2++;
		i++;
	}
	titi[i] = '\0';
	return (titi);
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!res)
		return (0);
	while (s1[i])
		i++;
	while (j < i)
	{
		res[j] = s1[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char	i;

	i = c;
	if (i == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	return (0);
}
