/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foltre.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:45:37 by mmouaffa          #+#    #+#             */
/*   Updated: 2025/05/21 23:10:50 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 11
#endif

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

char	*ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	char	*res;
	int total_size = ft_strlen(s1) + ft_strlen(s2);
	
	res = malloc(sizeof(char) * total_size + 1);
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
	if (i + j != total_size)
		printf("error : strjoin\n");
	else{};
	res[total_size] = 0;
	return (res);
}

char	*filter(char *str, char *c)
{
	int	i = 0, j = 0;
	int	str_size = ft_strlen(str);
	int c_size = ft_strlen(c);
	
	while (i < str_size)
	{
		j = 0;
		while (str[i + j] && str[i + j] == c[j] && c[j])
		{
			j++;
		}
		if (j == c_size)
		{
			j = 0;
			while (j < c_size)
			{
				str[i + j] = '*';
				j++;
			}
		}
		i++;
	}
	return (str);
}

int	main(int ac, char **av)
{
	int	bytes_read = 1;
	char	*res = malloc(1);
	char	*buffer;
	
	if (ac != 2)
		return (1);
	while (bytes_read && !ft_strchr(res, '\n'))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
		{
			free(res);
			return (1);
		}
		bytes_read = read(0, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(res);
			return (1);
		}
		buffer[bytes_read] = 0;
		char	*tmp = ft_strjoin(res, buffer);
		free(res);
		free(buffer);
		res = tmp;
		if (!res)
			return (1);
	}
	filter(res, av[1]);
	printf("%s\n", res);
	free(res);
	return (0);
}