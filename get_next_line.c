/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:13:36 by panther           #+#    #+#             */
/*   Updated: 2023/07/01 02:27:34 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Description:
    Écrire une fonction qui retourne une ligne lue depuis un
    descripteur de fichier.

    Valeur de retour:
    - Une string avec le contenu de la ligne lue, suivi d'un '\n' : 
      comportement correct
    - NULL : rien d’autre à lire ou une erreur s’est produite

    HELP:
    ssize_t read(int fd, void *buffer, size_t count);
    
    read() tente de lire jusqu'à count octets à partir du descripteur
    de fichier spécifié, et les place dans le tampon (buffer).
    Elle renvoie le nombre d'octets réellement lus. Si la valeur
    retournée est négative, cela indique une erreur de lecture.
*/

#include "get_next_line.h"

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

static char  *use_read_on_line(int fd, char *line)
{
  char  *buffer;
  int   read_bytes;
  
  if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
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

char	*get_next_line(int fd)
{
	char        *read_line;
  static char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
  line = use_read_on_line(fd, line);
  if (!line)
    return (NULL);
  read_line = extract_line(line);
  line = update_line(line);
  return (read_line);  
}

int main(void)
{
  char  *line;
  int		i;
  int		fd1;
  int		fd2;
  int		fd3;

  fd1 = open("tests/bigline_no_nl.txt", O_RDONLY);
  fd2 = open("tests/bigline_with_nl.txt", O_RDONLY);
  fd3 = open("tests/empty.txt", O_RDONLY);
  i = 1;
  while (i < 3)
  {
    line = get_next_line(fd1);
    printf("line [%02d]: %s", i, line);
    free(line);
    line = get_next_line(fd2);
    printf("line [%02d]: %s", i, line);
    free(line);
    line = get_next_line(fd3);
    printf("line [%02d]: %s", i, line);
    free(line);
    i++;
	}
  close(fd1);
  close(fd2);
  close(fd3);
  return (0);
}