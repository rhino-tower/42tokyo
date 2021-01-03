/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusaito <yusaito@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 00:43:44 by yusaito           #+#    #+#             */
/*   Updated: 2021/01/03 16:27:01 by yusaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char const *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int		find_indent(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*src;
	size_t				i;

	dest = (unsigned char *)buf1;
	src = (const unsigned char *)buf2;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (buf1);
}

char	*ft_strjoin(const char *s1, char const *s2, int n)
{
	char	*str;
	size_t	size_s1;
	size_t	size_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = n;
	if ((str = malloc(size_s1 + size_s2 + 1)) == NULL)
		return (NULL);
	ft_memcpy(str, s1, size_s1);
	ft_memcpy(str + size_s1, s2, size_s2);
	str[size_s1 + size_s2] = '\0';
	return (str);
}

char	*ft_strndup(char *str, int size)
{
	int		i;
	char	*s;

	if (size == -1)
		size = ft_strlen(str);
	if ((s = malloc(size + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
