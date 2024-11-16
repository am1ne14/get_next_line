/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-am <mohel-am@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:28:46 by mohel-am          #+#    #+#             */
/*   Updated: 2024/11/16 22:12:31 by mohel-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*result;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	rest = read_and_save(fd, &rest, buffer);
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

int	is_new_line(char *str)
{
	int	i;

	i = 0;
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

char	*get_full_line(char **rest)
{
	char	*line;
	char	*tmp;
	int		index;

	index = is_new_line(*rest);
	if (index < 0)
	{
		line = ft_strdup(*rest);
		free(*rest);
		*rest = NULL;
		return (line);
	}
	line = b4_new_line(*rest, index + 1);
	tmp = ft_strdup(*rest + index + 1);
	free(*rest);
	*rest = tmp;
	return (line);
}

char	*read_and_save(int fd, char **rest, char *buffer)
{
	char	*tmp;
	ssize_t	bytes_read;

	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = 0;
		tmp = *rest;
		*rest = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!*rest)
			return (NULL);
		if (is_new_line(*rest) >= 0 || bytes_read == 0)
			break ;
	}
	return (*rest);
}
