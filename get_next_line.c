/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:13:36 by panther           #+#    #+#             */
/*   Updated: 2023/05/22 19:49:10 by panther          ###   ########.fr       */
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

char    *get_next_line(int fd)
{
    char        *line;

    if (fd < 0)
        return (NULL);
}