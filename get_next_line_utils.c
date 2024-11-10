/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-am <mohel-am@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:47:49 by mohel-am          #+#    #+#             */
/*   Updated: 2024/11/10 21:35:59 by mohel-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	size_t	s1_len;
	size_t	s2_len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	j = 0;
	concat = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!concat)
		return (NULL);
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	while (s2[j])
		concat[i++] = s2[j++];
	concat[i] = '\0';
	return (concat);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int is_new_line(char *str)
{
    int i = 0;

    if (!str)
        return (-1);
    while (str[i])
    {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	lenght;
	size_t	i;

	lenght = ft_strlen(s);
	i = 0;
	dup = malloc((lenght + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char    *get_full_line(char **rest)
{
    char    *line;
    char    *tmp;
    int     newline_index = is_new_line(*rest);

    if (newline_index < 0)
    {
        line = ft_strdup(*rest);
        free(*rest);
        *rest = NULL;
        return (line);
    }
    line = ft_strdup(*rest);
    tmp = ft_strdup(*rest + newline_index + 1);
    free(*rest);
    *rest = tmp;
    return (line);
}
