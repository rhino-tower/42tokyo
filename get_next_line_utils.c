/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusaito <yusaito@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 00:43:44 by yusaito           #+#    #+#             */
/*   Updated: 2020/12/27 01:14:52 by yusaito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	return (len);
}

char	*ft_gnl_memchr(char **str, char c, int *flag)
{
	size_t	i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
		{
			*flag = 1;
			(*str)[i] = '\0';
			return (&((*str)[i + 1]));
		}
		i++;
	}
	*flag = 0;
	return (NULL);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size_s1;
	size_t	size_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	if ((str = malloc(size_s1 + size_s2 + 1)) == NULL)
		return (NULL);
	ft_memcpy(str, s1, size_s1);
	ft_memcpy(str + size_s1, s2, size_s2);
	str[size_s1 + size_s2] = '\0';
	return (str);
}

char	*ft_strdup(char **rest, int *flag)
{
	size_t	i;
	char	*str;

	*flag = 0;
	if ((str = malloc(ft_strlen(*rest) + 1)) == NULL)
		return (NULL);
	i = 0;
	while ((*rest)[i])
	{
		if ((*rest)[i] == '\n')
		{
			*rest += i + 1;
			*flag = 1;
			break;
		}
		str[i] = (*rest)[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
