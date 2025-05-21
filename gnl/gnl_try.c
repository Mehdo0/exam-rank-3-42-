/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_try.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:21:29 by mmouaffa          #+#    #+#             */
/*   Updated: 2025/05/15 14:51:39 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	int total_size = ft_strlen(s1) + ft_strlen(s2);
	char	*res = malloc(sizeof(char) * total_size + 1);

	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[total_size] = 0;
	return (res);
}

char	*ft_next(char *buffer)
{
	char	*res;
	int		i = 0;
	
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	res = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	i++;
	int j = 0;
	while (buffer[i])
	{
		res[j] = buffer[i];
		i++;
		j++;
	}
	free(buffer);
	return (res);
}

char	*ft_line(char *buffer)
{
	int	i = 0;
	char	*line;
	
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n' && buffer[i])
		line[i++] = '\n';
	return (line);
}

char	*ft_read(char *res, int fd)
{
	int	bytes_read = 1;
	char	*buffer;
	if (!res)
		res = malloc(sizeof(char));
	
	while (bytes_read)
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if(!buffer)
		{
			free(res);
			return (NULL);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			free(res);
			return (NULL);
		}
		buffer[bytes_read] = 0;
		char	*tmp = ft_strjoin(res, buffer);
		if (!tmp)
		{
			free(buffer);
			free(res);
			return (NULL);
		}
		res = tmp;
		free(buffer);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	const char	*buffer;
	char		*line;
	
	if (fd < 0 || read(fd, buffer, BUFFER_SIZE) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(buffer, fd);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
