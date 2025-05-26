/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthese.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:24:34 by mehdi             #+#    #+#             */
/*   Updated: 2025/05/26 11:24:35 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_strlen(char *s) {
	if (!s)
		return (0);
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

void print_comb(char *s, int l, int p) {
	int i = -1;
	while (s[++i])
	{
		if (i == p)
			printf("(");
		else if (i == l) {
			printf(")\n");
			return ;
		}
		else
			printf(" ");
	}
}

void ft_par(char *s, int l, int r, int p) {
	if (l > r)
		return ;
	if (s[l] == ' ')
		ft_par(s, l + 1, r, p);
	else if (s[l] == '(') {
		if (p == -1) {
			ft_par(s, l + 1, r, l);
			ft_par(s, l + 1, r, -1);
		}
		else 
			ft_par(s, l + 1, r, p);
	}
	else if (p != -1 && s[l] == ')') {
		print_comb(s, l, p);
		ft_par(s, l + 1, r, p);
	}
	else
		ft_par(s, l + 1, r, p);
}

int main(int ac, char **av) {
	if (ac != 2)
		return (1);
	ft_par(av[1], 0, ft_strlen(av[1]) - 1, -1);
	return (0);
}