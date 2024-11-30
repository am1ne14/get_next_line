/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-am <mohel-am@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 06:56:33 by mohel-am          #+#    #+#             */
/*   Updated: 2024/11/22 06:57:58 by mohel-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 420
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*get_full_line(char **rest);
int		is_new_line(char *str);
char	*b4_new_line(const char *s, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*read_and_save(int fd, char **rest, char *buffer);

#endif
