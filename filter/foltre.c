/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foltre.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:45:37 by mmouaffa          #+#    #+#             */
/*   Updated: 2025/05/08 14:12:59 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char    *filter(char *str, char *c)
{
    int i = 0;
    int j;
    
    while (str[i])
    {
        j = 0;
        while (str[i + j] == c[j] && str[i + j] && c[j])
        {
            j++;
        }
        if (j == (int)strlen(c))
        {
            int temp = i;
            while (i - j + 1 <= temp)
            {
                str[i] = '*';
                i++;
            }
        }
        i++;        
    }
    return (str);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *res;
    int i = 0;
    size_t total_size = strlen(s1) + strlen(s2);

    res = malloc(sizeof(char) * total_size + 1);
    if (!res || !s1 || !s2)
        return (NULL);
    while (s1[i])
    {
        res[i] = s1[i];
        i++;
    }
    int j = 0;
    while (s2[j])
    {
        res[i] = s2[j];
        i++;
        j++;
    }
    res[total_size] = 0;
    return (res);
}

int main(int ac, char **av)
{
    char    *buff;
    char    *res;
    int     bytes_read = 1;
    res = malloc(1);
    if (ac != 2)
        return (1);
    while (bytes_read)
    {
        buff = malloc(sizeof(char) * BUFFER_SIZE);
        if (!buff)
        {
            free(res);
            return (1);   
        }
        bytes_read = read(0, buff, BUFFER_SIZE);
        if (!bytes_read)
        {
            free(buff);
            return (1);
        }
        buff[bytes_read] = '\0';
        if (buff[0] == '\n')
        {
            free(buff);
            break ;
        }
        char    *tmp = ft_strjoin(res, buff);
        if (!tmp)
        {
            free(res);
            free(buff);
            return (1);
        }
        free(res);
        res = tmp;
        free(buff);
    }
    filter(res, av[1]);
    printf("%s\n", res);
    return (0);
}