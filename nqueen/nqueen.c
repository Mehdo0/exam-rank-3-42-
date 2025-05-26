/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nqueen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:26:45 by mehdi             #+#    #+#             */
/*   Updated: 2025/05/26 14:25:12 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int is_valid(int row, int col, int *positions)
{
    for (int i = 0; i < row; i++)
    {
        if (positions[i] == col || abs(positions[i] - col) == row - i)
            return 0;
    }
    return 1;
}

void print_solution(int *positions, int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d", positions[i] + 1);
        if (i < n - 1)
            printf(", ");
    }
    printf("]\n");
}

void N_queen(int *positions, int row, int n)
{
    if (row == n)
    {
        print_solution(positions, n);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (is_valid(row, col, positions))
        {
            positions[row] = col;
            N_queen(positions, row + 1, n);
        }
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);

    int n = atoi(av[1]);

    if (n == 1)
    {
        printf("[1]\n");
        return (0);
    }
    else if (n == 2 || n == 3)
    {
        printf("Error : aucune solution trouvee..\n");
        return (1);
    }

    int *positions = malloc(sizeof(int) * n);
    if (!positions)
        return (1);

    N_queen(positions, 0, n);

    free(positions);
    return (0);
}
