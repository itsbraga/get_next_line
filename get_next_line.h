/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:07:11 by panther           #+#    #+#             */
/*   Updated: 2023/05/22 19:57:05 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char    *get_next_line(int fd);

size_t  ft_strlen(char const *s);
char    *ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int     ft_islinebreak(char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif