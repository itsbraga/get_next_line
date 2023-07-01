/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 01:45:53 by panther           #+#    #+#             */
/*   Updated: 2023/07/01 01:58:37 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	len = 0;
	while (s[len])
		len++;
	i = 0;
	while (i <= len)
	{
		if ((char)c == s[i])
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

	if (!line || !buffer)
		return (NULL);
	len_line = ft_strlen(line);
	len_buffer = ft_strlen(buffer);
	if (!(read_line = malloc(sizeof(char) * (len_line + len_buffer + 1))))
		return (NULL);
	i = 0;
	while (i < len_line)
	{
		read_line[i] = line[i];
		i++;
	}
	i = 0;
	while (i < len_buffer)
	{
		read_line[i] = buffer[i];
		i++;
	}
	read_line[len_line + i] = '\0';
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
	if (!(read_line = malloc(sizeof(char) * (i + 2))))
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
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	while (line[i] && line[i] != '\n')
		i++;
	if (!(updated = malloc(sizeof(char) * (len_line - i + 1))))
		return (NULL);
	i++;
	j = 0;
	while (line[i])
	{
		updated[j] = line[i];
		i++;
		j++;
	}
	updated[j] = '\0';
	free(line);
	return (updated);
}