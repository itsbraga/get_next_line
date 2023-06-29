/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:07:11 by panther           #+#    #+#             */
/*   Updated: 2023/06/29 20:36:29 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 6

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);

char	*read_line(int fd, char *line);
size_t	ft_strlen(char const *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *line, char *buffer);
char	*extract_line(char *line);
char	*update_line(char *line);

#endif