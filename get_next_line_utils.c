/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:14:37 by panther           #+#    #+#             */
/*   Updated: 2023/07/03 12:43:20 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *line, char *buffer)
{
	char	*read_line;
	size_t	len_line;
	size_t	len_buffer;
	size_t	i;
	size_t	j;

	if (!line || !buffer)
		return (NULL);
	len_line = ft_strlen(line);
	len_buffer = ft_strlen(buffer);
	read_line = malloc(sizeof(char) * (len_line + len_buffer + 1));
	if (!read_line)
		return (NULL);
	i = 0;
	while (i < len_line)
	{
		read_line[i] = line[i];
		i++;
	}
	j = 0;
	while (j < len_buffer)
	{
		read_line[i] = buffer[j];
		i++;
		j++;
	}
	read_line[len_line + len_buffer] = '\0';
	free(line);
	return (read_line);
}

char	*extract_line(char *line)
{
	int		i;
	char	*read_line;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	read_line = malloc(sizeof(char) * (i + 2));
	if (!read_line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		read_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		read_line[i] = line[i];
		i++;
	}
	read_line[i] = '\0';
	return (read_line);
}

char	*update_line(char *line)
{
	int		i;
	int		j;
	size_t	len_line;
	char	*updated;
	
	len_line = ft_strlen(line);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	updated = malloc(sizeof(char) * (len_line - i + 1));
	if (!updated)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
	{
		updated[j++] = line[i++];
	}
	updated[j] = '\0';
	free(line);
	return (updated);
}