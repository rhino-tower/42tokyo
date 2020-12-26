/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusaito <yusaito@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:31:15 by yusaito           #+#    #+#             */
/*   Updated: 2020/12/27 01:38:51 by yusaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_indent_next(char *buf, int *flag)
{
	int	i;

	i = 0;
	*flag = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			*flag = 1;
			return (buf + i + 1);
		}
		i++;
	}
	return (NULL);
}

static int	read_one_line(int fd, char **line, char **rest)
{
	char	*buf;
	char	*tmp;
	int		rc;
	int		flag;

	if ((buf = malloc(BUFFER_SIZE + 1)) == NULL)
		return (-1);
	while ((rc = read(fd, buf, BUFFER_SIZE)) != 0)
	{
		buf[rc] = '\0';
		tmp = *line;
		*line = ft_strjoin(tmp, buf);
		free(tmp);
		if (*line == NULL)
		{
			free(buf);
			return (-1);
		}
		*rest = get_indent_next(buf, &flag);
		if (flag == 1)
			return (1);
	}
	free(buf);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			flag;
	int			read_res;
	static char	*rest;

	flag = 0;
	if (line == NULL || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (rest != NULL)
	{
		if ((*line = ft_strdup(&rest, &flag)) == NULL)
			return (-1);
	}
	else
	{
		if ((*line = malloc(1)) == NULL)
			return (-1);
		**line = '\0';
	}
	if (flag == 1)
		return (1);
	read_res = read_one_line(fd, line, &rest);
	return (read_res);
}
