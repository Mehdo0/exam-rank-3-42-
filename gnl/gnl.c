/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:03:03 by mehdi             #+#    #+#             */
/*   Updated: 2025/05/21 22:56:03 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

char	*ft_free(char *res, char *buffer)
{
	char	*tmp;
	
	tmp = ft_strjoin(res, buffer);
	free(res);
	return (tmp);
}

char	*ft_strchr(char *str, int c)
{
	char	*res;

	res = str;
	while (*str && *str != c)
	{
		str++;
	}
	if (*str == c)
		return (str);
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_calloc(int size, int element)
{
	char	*str;
	int		i;

	str = malloc(size * element);
	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		total_size;

	total_size = ft_strlen(s1) + ft_strlen(s2);
	res = ft_calloc(total_size, sizeof(char));
	if (!res)
		return(NULL);
	int	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	int	j = 0;
	while (s2[i])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[total_size] = '\0';
	return (res);
}

char	*ft_line(char *buffer)
{
	int	i;
	char	*line;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_next(char *res)
{
	int	i;
	int	j;
	char	*line;

	i = 0;
	while (res[i] && res[i] != '\n')
		i++;
	if (!res)
	{
		free(res);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(res) - i + 1), sizeof(char));
	j = 0;
	while (res[i])
	{
		line[j] = res[i];
		i++;
		j++;
	}
	fre(res);
	return (line);
}

char	*read_file(char *buffer, int fd)
{
	int	bytes_read = 1;
	char	*res;
	
	if (!buffer)
		buffer = ft_calloc(1,1);
	res = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (bytes_read > 0)
	{
		bytes_read = read(fd, res, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		res[bytes_read] = 0;
		buffer = ft_free(buffer, res);
		if (ft_strchr(buffer, '\n'))
			return (buffer);
	}
	free(res);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);

	buffer = read_file(buffer, fd);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (buffer);
}
