/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:10:12 by aosmenaj          #+#    #+#             */
/*   Updated: 2023/11/13 16:13:30 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*t;
	size_t			i;

	t = malloc(num * size);
	if (!t)
		return (0);
	i = 0;
	while (i < num * size)
	{
		t[i] = '\0';
		i++;
	}
	return ((void *)t);
}

char	*ft_line(char *buf)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (j <= i)
	{
		line[j] = buf[j];
		j++;
	}
	return (line);
}

int	ft_strchar(const char *s, int c)
{
	size_t			i;
	char			*s1;
	unsigned char	k;

	k = c;
	s1 = (char *)s;
	i = 0;
	while (s[i])
	{
		if (s1[i] == k)
			return (1);
		i++;
	}
	if (s1[i] == k)
		return (1);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l;
	char	*res;
	int		i;
	int		j;

	i = 0;
	l = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (l + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		res[i++] = s2[j];
		j++;
	}
	res[l] = '\0';
	free((char *)s1);
	return (res);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
