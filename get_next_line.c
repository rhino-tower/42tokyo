/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusaito <yusaito@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:31:15 by yusaito           #+#    #+#             */
/*   Updated: 2021/01/03 16:26:18 by yusaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_one_line(char **line, char *buf, char **rest)
{
	int		n;
	int		flag;
	char	*tmp;

	flag = 1;
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

int			get_next_line(int fd, char **line)
{
	int			ret;
	int			rc;
	char		*buf;
	static char	*rest;

	if (line == NULL || fd < 0 || BUFFER_SIZE <= 0)
		ret = -1;
	ret = 0;
	if ((*line = malloc(1)) == NULL)
		ret = -1;
	else
		**line = '\0';
	if (rest)
		if ((ret = read_one_line(line, rest, &rest)) == 1)
			return (1);
	if ((buf = malloc(BUFFER_SIZE + 1)) == NULL)
		ret = -1;
	while (ret == 0 && ((rc = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[rc] = '\0';
		ret = read_one_line(line, buf, &rest);
	}
	all_free(line, &rest, &buf, ret);
	return (ret);
}
