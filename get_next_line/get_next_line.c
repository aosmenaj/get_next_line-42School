/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:11:34 by aosmenaj          #+#    #+#             */
/*   Updated: 2024/10/10 09:45:05 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//#include "get_next_line_utils.c"

char	*ft_next(char *buf)
{
	char	*temp;
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	temp = ft_calloc(ft_strlen(buf) - i + 2, sizeof(char));
	if (!temp)
		return (NULL);
	if (buf[i] != '\0')
		i++;
	while (buf[i] != '\0')
		temp[j++] = buf[i++];
	free(buf);
	return (temp);
}

char	*ft_read(int fd, char *buf, char *tmp)
{
	int		bytes;

	if (buf == NULL)
		buf = ft_calloc (1, sizeof(char));
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes <= 0 && ft_strlen(buf) == 0)
		{
			free(buf);
			buf = NULL;
			return (NULL);
		}
		tmp[bytes] = '\0';
		buf = ft_strjoin(buf, tmp);
		if (!buf)
			return (NULL);
		if (ft_strchar(buf, '\n') == 1)
			break ;
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*tmp;
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	buf = ft_read(fd, buf, tmp);
	if (!buf)
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	line = ft_line(buf);	
	buf = ft_next(buf);
	return (line);
}

int main ()
{
	char	*p;
	int fd;
	fd = open("fileditesto.txt", O_RDONLY);

	int j = 0;

	while (j++ < 100)
	{
		p = get_next_line(fd);
		printf("%s", p);
	}
	free(p);
	close(fd);
	return (0);
}
