/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:50:43 by tdelgran          #+#    #+#             */
/*   Updated: 2023/04/03 13:58:46 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

#endif

int     back_n(char *str);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char    *read_line(char *line, int fd);
char    *format_line(char *line, char **stock);
char	*trim(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char *get_line_from_stock(char **stock);

#endif