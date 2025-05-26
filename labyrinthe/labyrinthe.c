/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labyrinthe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:25:26 by mehdi             #+#    #+#             */
/*   Updated: 2025/05/26 11:25:27 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void print_way(char **lab) {
	int i = -1;
	while (lab[++i])
		printf("%s\n", lab[i]);
}

int ft_lab(char **lab, int x, int y) {
	if (x < 0 || y < 0 || !lab[y] || !lab[y][x])
		return (0);
	if (lab[y][x] == 'E')
		return(printf("\nSolution Trouvée : x = %d, y = %d\n", x, y), print_way(lab), 0);
	if (lab[y][x] == 'X' || lab[y][x] == '0')
		return (0);
	lab[y][x] = '0';
	ft_lab(lab, x + 1, y);
	ft_lab(lab, x, y + 1);
	ft_lab(lab, x - 1, y);
	ft_lab(lab, x, y - 1);
	lab[y][x] = '.';
	return (0);
}

int main(void) {
	char *lab[6];
	char l1[] = "....E";
	char l2[] = ".X...";
	char l3[] = "..X..";
	char l4[] = "...X.";
	char l5[] = ".....";
	lab[0] = l1;
	lab[1] = l2;
	lab[2] = l3;
	lab[3] = l4;
	lab[4] = l5;
	lab[5] = 0;
	ft_lab(lab, 0, 0);
	return (0);
}