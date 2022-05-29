/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 19:21:54 by snino             #+#    #+#             */
/*   Updated: 2021/12/24 19:34:53 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	c;

	if (!str)
		return (0);
	c = 0;
	while (str[c] != '\0')
	{
		c++;
	}
	return (c);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
	while (dst[i] != '\0' || src[i] != '\0')
	{
		if (*src++)
			i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	n;
	char	*res;

	i = 0;
	n = 0;
	if (!s1 || !s2)
		return (0);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (0);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[n] != '\0')
	{
		res[i + n] = s2[n];
		n++;
	}
	res[i + n] = '\0';
	free(s1);
	return (res);
}

char	*ft_strdup(const char *s1)
{
	size_t	n;
	size_t	i;
	char	*res;

	if (!s1)
		return (0);
	i = 0;
	n = ft_strlen(s1);
	res = (char *)malloc(sizeof (char) * (n + 1));
	if (!res)
		return (0);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	n;

	if (!s)
		return (0);
	i = 0;
	n = (unsigned int)ft_strlen(s);
	if (start > n)
		len = 0;
	if (len > n - start)
		len = n - start;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	free(s);
	return (res);
}
