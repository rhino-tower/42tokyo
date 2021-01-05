/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuki <yuki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:54:33 by yusaito           #+#    #+#             */
/*   Updated: 2021/01/05 21:15:48 by yuki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define MAX_FD 256
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
/*
** get_next_line.c
*/
int		get_next_line(int fd, char **line);
/*
** get_next_line_utils.c
*/
int		ft_strlen(char const *str);
int		find_indent(char *str);
void	*ft_memcpy(void *buf, const void *buf2, size_t n);
char	*ft_strjoin(const char *s1, char const *s2, int n);
char	*ft_strndup(char *str, int size);

#endif
