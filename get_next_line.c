/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:13:36 by panther           #+#    #+#             */
/*   Updated: 2023/06/29 20:24:53 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*  Description:
    Écrire une fonction qui retourne une ligne lue depuis un
    descripteur de fichier.

    Valeur de retour:
    - Une string avec le contenu de la ligne lue, suivi d'un '\n' : 
      comportement correct
    - NULL : rien d’autre à lire ou une erreur s’est produite

    HELP:
    ssize_t read(int fd, void *buffer, size_t count);
    
    fd : L'entier représentant le descripteur de fichier à partir
         duquel lire les données.
    buffer : Un pointeur vers la mémoire où les données lues seront
             stockées.
    count : Le nombre maximal d'octets à lire.
    
    read() tente de lire jusqu'à count octets à partir du descripteur
    de fichier spécifié, et les place dans le tampon (buffer).
    Elle renvoie le nombre d'octets réellement lus. Si la valeur
    retournée est négative, cela indique une erreur de lecture.
*/

char  *read_line(int fd, char *line)
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
	char        *line_read;
  static char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
  line = read_line(fd, line);
  if (!line)
    return (NULL);
  line_read = extract_line(line);
  line = update_line(line);
  return (line_read);  
}