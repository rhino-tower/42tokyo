/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuki <yuki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:31:15 by yusaito           #+#    #+#             */
/*   Updated: 2021/01/05 21:37:53 by yuki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_one_line(char **line, char *buf, char **rest)
{
	int		n;
	int		flag;
	char	*tmp;

	flag = 1;
	if (buf == NULL)
		return (-1);
	if ((n = find_indent(buf)) == -1)
	{
		flag = 0;
		n = ft_strlen(buf);
	}
	if ((tmp = ft_strjoin(*line, buf, n)) == NULL)
		return (-1);
	free(*line);
	*line = tmp;
	tmp = NULL;
	if (flag == 1)
		if ((tmp = ft_strndup(buf + n + 1, -1)) == NULL)
			return (-1);
	free(*rest);
	*rest = tmp;
	return (flag);
}

static void	all_free(char **line, char **rest, char **buf, int ret)
{
	free(*buf);
	if (ret == -1)
	{
		free(*line);
		free(*rest);
	}
}

static int	error_check(char **line, char **rest, int fd)
{
	if (line == NULL || BUFFER_SIZE <= 0)
	{
		free(*rest);
		return (1);
	}
	else if (fd < 0)
	{
		return (1);
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	int			rc;
	char		*buf;
	static char	*rest[MAX_FD];

	ret = 0;
	if (error_check(line, rest, fd))
		return (-1);
	if ((*line = malloc(1)) == NULL)
		ret = -1;
	else
		**line = '\0';
	if (rest[fd])
		if ((ret = read_one_line(line, rest[fd], &(rest[fd]))) == 1)
			return (1);
	if ((buf = malloc(BUFFER_SIZE + 1)) == NULL)
		ret = -1;
	while (ret == 0 && ((rc = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[rc] = '\0';
		ret = read_one_line(line, buf, &(rest[fd]));
	}
	all_free(line, &(rest[fd]), &buf, ret);
	return (ret);
}
