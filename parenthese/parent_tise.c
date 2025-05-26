/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_tise.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdi <mehdi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:33:40 by mehdi             #+#    #+#             */
/*   Updated: 2025/05/26 14:49:33 by mehdi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])i++;
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

void    ft_parse(char *str, int r, int l, int p)
{
    if (l > r)
        return ;
    else if (str[l] == ' ')
        ft_parse(str, r, l + 1, p);
    else if (str[l] == '(')
    {
        if (p == -1)
        {
            ft_parse(str, r, l + 1, l);
            ft_parse(str, r, l + 1, -1);
        }
        else
            ft_parse(str, r, l + 1, p);
    }
    else if (str[l] == ')' && p != -1)
    {
        print_comb(str, l, p);
        ft_parse(str, r, l + 1, p);
    }
    else
        ft_parse(str, r, l + 1, p);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    ft_parse(av[1], ft_strlen(av[1]) - 1, 0, -1);
    return (0);
}