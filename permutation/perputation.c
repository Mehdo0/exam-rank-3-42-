/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perputation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:26:57 by mmouaffa          #+#    #+#             */
/*   Updated: 2025/05/06 12:42:22 by mmouaffa         ###   ########.fr       */
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

void    try_all_comb(char *str, int size, int l)
{
    int i;
    if (l == size - 1)
    {
        write(1, str, size);
        write(1, "\n", 1);
        return;
    }
    for(i = l; i < size; i++)
    {
        swap(str, l, i);
        try_all_comb(str, size, l + 1);
        swap(str, l, i);
    }
}

void    bubble_sort(char *str, int size)
{
    int i;
    int j;
    
    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if (str[j] > str[j + 1])
                swap(str, j, j + 1);
            j++;
        }
        i++;
    }
}

int main(int ac, char **av)
{
    int	i;
    
    i = 0;
    if (ac != 2)
    {
        write(1, "Error\n", 6);
        return (1);
    }
    while (av[1][i])
        {i++;}
	bubble_sort(av[1], i);
    try_all_comb(av[1], i, 0);
    return(0);
}