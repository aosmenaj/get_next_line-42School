/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosmenaj <aosmenaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:42:45 by aosmenaj          #+#    #+#             */
/*   Updated: 2023/12/12 16:23:19 by aosmenaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	{
		temp[j++] = buf[i++];
	}
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
	static char	*buf[1048576];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	buf[fd] = ft_read(fd, buf[fd], tmp);
	if (!buf[fd])
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	line = ft_line(buf[fd]);
	buf[fd] = ft_next(buf[fd]);
	return (line);
}

// int main ()
// {
// 	char	*p;
// 	int fd1;
// 	int	fd2;
// 	int fd3;
// 	fd1 = open("fileditesto.txt", O_RDONLY);
// 	fd2 = open("file2.txt", O_RDONLY);
// 	fd3 = open("file3.txt", O_RDONLY);
// 	int j = 0;
// 	while (j++ < 2)
// 	{
// 		p = get_next_line(fd1);
// 		printf("%s", p);
// 		free(p);
// 		p = get_next_line(fd2);
// 		printf("%s\n", p);
// 		free(p);
// 	}
// 	free(p);
// 	j = 0;
// 	while (j++ < 3)
// 	{
// 		p = get_next_line(fd3);
// 		printf("%s\n", p);
// 		free(p);
// 	}
// }
