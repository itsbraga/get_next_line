/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:07:11 by panther           #+#    #+#             */
/*   Updated: 2023/07/01 02:38:06 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/resource.h>
# include <limits.h>
# include <fcntl.h> // to comment before pushing into vogsphere
# include <stdio.h> // to comment before pushing into vogsphere

# define BUFFER_SIZE 6
# define MAX_FD 1024 + 1 // RLIMIT_NOFILE
 
size_t  ft_strlen(char const *s);
char	*ft_strchr(const char *s, int c);
char    *ft_strjoin(char *line, char *buffer);
char    *extract_line(char *line);
char    *update_line(char *line);
char    *use_read_on_line(int fd, char *line);

char    *get_next_line(int fd);

#endif