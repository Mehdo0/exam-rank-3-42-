/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perputation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:31:21 by mehdi             #+#    #+#             */
/*   Updated: 2025/05/05 18:20:22 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}

char    *swap(char *str, int i, int j){
    char    tmp;

    tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
    return (str);
}

void	bubble_sort(char *str, int size)
{
	int	i;
	int	j;

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

void	try_all_comb(int size, char *input, int l)
{
    int		i;
    
    if (l == size - 1)
    {
        write(1, input, size);
        write(1, "\n", 1);
        return;
    }
    for (i = l; i < size; i++)
    {
        swap(input, l, i);
        try_all_comb(size, input, l + 1);
        swap(input, l, i); // Restore the string to its original state
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    int i = ft_strlen(av[1]);
    if (i < 2)
        return (1);
    bubble_sort(av[1], i);
    try_all_comb(i, av[1], 0);
    return (0);
}