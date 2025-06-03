#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{int i = 0; while (str[i])i++;return (i);}

void    print_comb(char *str, int l, int p)
{
    for (int i = 0; str[i]; i++)
    {
        if (i == p)
            printf("(");
        else if (i == l)
        {
            printf(")\n");
            return ;
        }
        else
            printf(" ");
    }
}

void    solve(char *str, int l, int r, int p)
{
    if (l > r)
        return ;
    if (str[l] == ' ')
        solve(str, l + 1, r, p);
    else if (str[l] == '(')
    {
        if (p == -1)
        {
            solve(str, l + 1, r, l);
            solve(str, l + 1, r, -1);
        }
        else
            solve(str, l + 1, r, p);
    }
    else if (str[l] == ')' && p != -1)
    {
        print_comb(str, l, p);
        solve(str, l + 1, r, p);
    }
    else
        solve(str, l + 1, r, p);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    solve(av[1], 0, ft_strlen(av[1]) - 1, -1);
    return (0);
}