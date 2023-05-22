/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panther <panther@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:14:37 by panther           #+#    #+#             */
/*   Updated: 2023/05/22 19:56:49 by panther          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(char const *s)
{
    size_t  i;

    i = 0;
    if (!s)
        return (0);
    while (s[i] != '\0')
        i++;
    return (i);
}

// ft_strchr() recherche la première occurrence d'un caractère spécifié
// dans une chaîne de caractères

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
    size_t  s_len;
    size_t  i;

	if (!s)
		return (NULL);
    s_len = ft_strlen(s);
	if ((size_t)start > s_len)
		start = s_len;
	if (len > (s_len - start))
		len = s_len - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
    i = 0;
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

int ft_islinebreak(char *s)
{
    int i;

    i = 0;
    if (!s)
        return (0);
    while (s[i])
    {
        if (s[i] == "\n")
            return (1);
        i++;
    }
    return (0);
}

char	*ft_strjoin(char *s1, char *s2);