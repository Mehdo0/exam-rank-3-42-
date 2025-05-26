/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perputation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:26:57 by mmouaffa          #+#    #+#             */
/*   Updated: 2025/05/26 16:02:57 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char    *swap(char  *str, int i , int j)
{
    char    tmp;

    tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
    return (str);
}

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])i++;
    return (i);
}

void    bubble_sort(char *str, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (str[j] > str[j + 1])
                swap(str, j, j + 1);
        }
    }
}

int next_permutation(char *str, int size)
{
    int i = size - 2;
    while (i >= 0 && str[i] >= str[i + 1])
        i--;
    if (i < 0)
        return (0);
    int j = size -1;
    while (str[j] <= str[i])
        j--;
    swap(str, i, j);
    int start = i + 1;
    int end = size - 1;
    while (start < end)
    {
        swap(str, start, end);
        start++;
        end--;
    }
    return (1);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    int len = 0;
    while (av[1][len])
        len++;
    char    *str = malloc(len + 1);
    if (!str)
        return (1);
    for (int i = 0; i < len; i++)
    {
        str[i] = av[1][i];
    }
    bubble_sort(str, len);
    do{
        printf("%s\n", str);
    }while (next_permutation(str, len));
    free(len);
    return (0);
}