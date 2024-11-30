/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-am <mohel-am@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:03:24 by mohel-am          #+#    #+#             */
/*   Updated: 2024/11/22 06:58:12 by mohel-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdlib.h>
# include<stdio.h>
# include<string.h>
# include<unistd.h>

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
void	init_vars(size_t *i, size_t *j, size_t *len1, size_t *len2);

#endif
