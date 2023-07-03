/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 01:40:54 by panther           #+#    #+#             */
/*   Updated: 2023/07/01 11:37:38 by panther          ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

# ifndef MAX_FD
#  define MAX_FD RLIMIT_NOFILE
# endif

/*
** Le descripteur de fichier va de 0 à OPEN_MAX (défini dans <limits.h>)
** La valeur maximale du descripteur de fichier peut être obtenue avec :
**
** Mac : launchctl limit maxfiles
** Linux : ulimit -n 
*/

size_t  ft_strlen(char *s);
char    *ft_strchr(char *s, int c);
char    *ft_strjoin(char *line, char *buffer);
char    *extract_line(char *line);
char    *update_line(char *line);
char    *use_read_on_line(int fd, char *line);

char    *get_next_line(int fd);

#endif