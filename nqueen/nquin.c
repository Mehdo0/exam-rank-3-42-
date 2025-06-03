/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nquin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:15:34 by mmouaffa          #+#    #+#             */
/*   Updated: 2025/06/03 12:06:38 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	print_comb(int *positions, int n)
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

int	is_valid(int *poisitons,int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		if (col == poisitons[i] || abs(poisitons[i] - col) == row - i)
			return (0);
	}
	return (1);
}

void	nqueen(int *positions, int n, int row)
{
	if (row == n)
	{
		print_comb(positions, n);
		return ;
	}
	for (int col = 0; col < n; col++)
	{
		if (is_valid(positions, col, row))
		{
			positions[row] = col;
			nqueen(positions, n, row + 1);
		}
	}
	
}

int	main (int ac, char **av)
{
	if (ac != 2)
		return (1);
	int	n = atoi(av[1]);
	if (n == 2 || n == 3)
	{
		printf("Error : pas de combinaison vbfinaiuuagsiusijbiusdkjncuabgasiudgvbuasibdiugfiuBkuzkixbcovoizxicvnndjclKSKDJNvlND aapoajjpdkkdvhthijthiubbalide .\n");
		return (1);
	}
	int	*positions = malloc(sizeof(int) * n);
	if (!positions)
		return (1);
	nqueen(positions, n, 0);
	free(positions);
	return (0);
}