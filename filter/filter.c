/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:45:37 by mmouaffa          #+#    #+#             */
/*   Updated: 2025/04/16 15:36:46 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//gcc -Wall -Wextra -Werror foltre.c

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void    filter(char *str, char *s)
{
    int i = 0;
    int j = 0;
    int valid = 0;
    
    while (str[i])
    {
        j = 0;
        while (str[i + j] == s[j] && str[i + j] && s[j])
        {
            j++;
            if (j == (int)strlen(s))
                valid = 1;
        }
        while (valid == 1 && i <= j)
        {
            str[i] = '*';
            i++;
        }
        valid = 0;
        i++;
    }
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *res = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
    int i = 0;
    int j = 0;

    if (!s1 || !s2 || !res)
        return (NULL);
    while (s1[i])
    {
        res[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        res[i] = s2[j];
        i++;
        j++;
    }
    res[i + j] = '\0';
    return (res);
}

int main(int ac, char **av)
{
    char    *buffer = NULL;
    char    *res = malloc(1);
    int     bytes_read = BUFFER_SIZE;
    
    if (ac != 2)
        return (1);
    while (bytes_read)
    {
        buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!buffer)
        {
            free(res);
            return (1);
        }
        bytes_read = read(0, buffer ,BUFFER_SIZE);
        if (!bytes_read)
        {
            free(buffer);
            free(res);
            return (1);
        }
        buffer[bytes_read] = '\0';
        if (buffer[0] == '\n')
        {
            free(buffer);
            free(res);
            break ;
        }
        char    *tmp = ft_strjoin(res, buffer);
        if (!tmp)
        {
            free(res);
            free(buffer);
            return (1);
        }
        free(res);
        res = tmp;
        free(buffer);
    }
    filter(res, av[1]);
	printf("%s", res);
    free(res);
    return (0);
}