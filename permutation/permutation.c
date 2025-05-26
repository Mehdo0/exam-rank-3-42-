/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:56:02 by mmouaffa          #+#    #+#             */
/*   Updated: 2025/05/26 15:29:49 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void afficher_chaine(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    write(1, str, len);
    write(1, "\n", 1);
}

void swap(char *str, int i, int j)
{
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
}

void bubble_sort(char *str, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (str[j] > str[j + 1])
                swap(str, j, j + 1);
        }
    }
}


int permutation_suivante(char *str, int len)
{
    int i = len - 2;
    while (i >= 0 && str[i] >= str[i + 1])
        i--;
    if (i < 0)
        return 0;

    int j = len - 1;
    while (str[j] <= str[i])
        j--;
    swap(str, i, j);
    int start = i + 1, end = len - 1;
    while (start < end)
    {
        swap(str, start, end);
        start++;
        end--;
    }
    return 1;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;
    int len = 0;
    while (av[1][len])
        len++;
    char *str = malloc(len + 1);
    if (!str)
        return 1;
    for (int i = 0; i <= len; i++)
        str[i] = av[1][i];
    bubble_sort(str, len);
    do {
        afficher_chaine(str);
    } while (permutation_suivante(str, len));

    free(str);
    return 0;
}
