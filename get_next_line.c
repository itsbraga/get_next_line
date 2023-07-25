/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:13:36 by panther           #+#    #+#             */
/*   Updated: 2023/07/05 17:03:22 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*use_read_on_line(int fd, char *line)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(line, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*read_line;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = use_read_on_line(fd, line);
	if (!line)
		return (NULL);
	read_line = extract_line(line);
	line = update_line(line);
	return (read_line);
}

// int main(void)
// {
// 	char	*line;
// 	int	fd;

// 	fd = open("tests/figure.txt", O_RDONLY);
// 	printf(BOLD BRIGHT_BLUE "Testing file : tests/figure.txt\n");
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf(RESET WHITE "line : %s\n", line);
// 		free(line);
// 		line = get_next_line(fd);	
// 	}
// 	free(line);
// 	close(fd);
// 	return (0);
// }
