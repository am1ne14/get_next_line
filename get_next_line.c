/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-am <mohel-am@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:48:04 by mohel-am          #+#    #+#             */
/*   Updated: 2024/11/10 15:52:17 by mohel-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
char    *ft_strjoin(char *s1, char *s2);
int     is_new_line(char *str);
char    *get_full_line(char **rest);

char    *get_next_line(int fd)
{
    char            *buffer;
    char            *tmp;
    char            *result;
    static char     *rest;
    ssize_t         bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);

    while (1)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
        {
            free(buffer);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        tmp = rest;
        rest = ft_strjoin(tmp, buffer);
        free(tmp);
        if (!rest)
        {
            free(buffer);
            return (NULL);
        }
        if (is_new_line(rest) >= 0 || bytes_read == 0)
            break;
    }
    free(buffer);
    if (rest && *rest)
    {
        result = get_full_line(&rest);
        return (result);
    }
    free(rest);
    rest = NULL;
    return (NULL);
}

