/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-am <mohel-am@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:48:04 by mohel-am          #+#    #+#             */
/*   Updated: 2024/11/10 21:26:31 by mohel-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*tmp;
	char	*result;
	static char	*rest;
	ssize_t	bytes_read;

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
