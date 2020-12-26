/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusaito <yusaito@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:54:33 by yusaito           #+#    #+#             */
/*   Updated: 2020/12/20 22:49:04 by yusaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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
size_t	ft_strlen(char const *str);
char	*ft_gnl_memchr(char **str, char c, int *flag);
void	*ft_memcpy(void *buf, const void *buf2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char **rest, int *flag);

#endif
