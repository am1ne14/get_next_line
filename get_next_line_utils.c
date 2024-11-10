/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-am <mohel-am@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:47:49 by mohel-am          #+#    #+#             */
/*   Updated: 2024/11/10 15:51:23 by mohel-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char    *ft_strjoin(char *s1, char *s2)
{
    char    *new_str;
    size_t  i = 0, j = 0;
    size_t  len1 = s1 ? strlen(s1) : 0;
    size_t  len2 = s2 ? strlen(s2) : 0;

    new_str = malloc(len1 + len2 + 1);
    if (!new_str)
        return (NULL);
    while (s1 && s1[i])
    {
        new_str[i] = s1[i];
        i++;
    }
    while (s2 && s2[j])
        new_str[i++] = s2[j++];
    new_str[i] = '\0';
    return (new_str);
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
char    *get_full_line(char **rest)
{
    char    *line;
    char    *tmp;
    int     newline_index = is_new_line(*rest);

    if (newline_index < 0)
    {
        line = strdup(*rest);
        free(*rest);
        *rest = NULL;
        return (line);
    }
    line = strndup(*rest, newline_index + 1);
    tmp = strdup(*rest + newline_index + 1);
    free(*rest);
    *rest = tmp;
    return (line);
}

