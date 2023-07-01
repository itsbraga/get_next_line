/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 22:39:22 by panther           #+#    #+#             */
/*   Updated: 2023/07/01 02:23:50 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void  ft_putstr_fd(char *s, int fd)
{
  int i;

  if (!s)
    return ;
  i = 0;
  while (s[i])
  {
    write(fd, &s[i], ft_strlen(s));
    i++;
  }
}

static char    *use_read_on_line(int fd, char *line)
{
    char  *buffer;
    int   read_bytes;
    
    if (!(buffer = malloc((BUFFER_SIZE + 1) * sizeof(char))))
        return (NULL);
    read_bytes = 1;
    while (!ft_strchr(line, '\n') && read_bytes != 0)
    {
        read_bytes = read(fd, buffer, BUFFER_SIZE);
        if (read_bytes == -1)
        {
            ft_putstr_fd("-----------\n An error happened\n", fd);
            free(line);
            return (NULL);
        }
        buffer[read_bytes] = '\0';
        line = ft_strjoin(line, buffer);
    }
    free(buffer);
    return (line);
}

char    *get_next_line(int fd)
{
	char        *read_line;
    static char *line[MAX_FD];

	if ((fd < 0 || fd >= MAX_FD) || BUFFER_SIZE <= 0)
		return (NULL);
    line[fd] = use_read_on_line(fd, line[fd]);
    if (!line[fd])
        return (NULL);
    read_line = extract_line(line[fd]);
    line[fd] = update_line(line[fd]);
    return (read_line);  
}