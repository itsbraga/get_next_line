/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 01:43:39 by panther           #+#    #+#             */
/*   Updated: 2023/07/01 02:22:14 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	test_gnl(int fd, char const *current_file)
{
	char	*current_line;
	int		line_counter;

	printf("Testing file %s\n", current_file);
	line_counter = 0;
	while (1)
	{
		current_line = get_next_line(fd);
		if (!current_line)
			break ;
		line_counter++;
		printf("LINE [%02d]: '%s'\n", line_counter, current_line);
		free(current_line);
	}
	printf("LAST RETURN: %d\n", current_line);
	printf("---------------------------------------------------------------\n");
	close(fd);
}

int main(void)
{
	char const *current_file;
	int			current_fd;

	current_file = "tests/bigline_no_nl.txt";
	current_fd = open(current_file, O_RDONLY);
	test_gnl(current_fd, current_file);

	current_file = "tests/bigline_with_nl.txt";
	current_fd = open(current_file, O_RDONLY);
	test_gnl(current_fd, current_file);

	current_file = "tests/empty.txt";
	current_fd = open(current_file, O_RDONLY);
	test_gnl(current_fd, current_file);

	current_file = "tests/figure.txt";
	current_fd = open(current_file, O_RDONLY);
	test_gnl(current_fd, current_file);

	current_file = "tests/mult_nl.txt";
	current_fd = open(current_file, O_RDONLY);
	test_gnl(current_fd, current_file);

	current_file = "tests/multl_with_nl.txt";
	current_fd = open(current_file, O_RDONLY);
	test_gnl(current_fd, current_file);

	current_file = "tests/poem_wsp_nl.txt";
	current_fd = open(current_file, O_RDONLY);
	test_gnl(current_fd, current_file);

	current_file = "tests/largefile.txt";
	current_fd = open(current_file, O_RDONLY);
	test_gnl(current_fd, current_file);

	return (0);
}