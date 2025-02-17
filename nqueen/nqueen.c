#include <stdio.h>
#include <stdlib.h>

void print_tab(char **tab, int n)
{
    for (int i = 0; i < n; i++)
        printf("%s\n", tab[i]);
}

void free_tab(char **tab, int n)
{
    for (int i = 0; i < n; i++)
        free(tab[i]);
    free(tab);
}

char **create_tab(int n)
{
    char **tab = malloc(sizeof(char *) * n);
    if (!tab)
        return (NULL);
    for (int i = 0; i < n; i++)
    {
        tab[i] = malloc(sizeof(char) * (n + 1));
        if (!tab[i])
        {
            for (int j = 0; j < i; j++)
                free(tab[j]);
            free(tab);
            return (NULL);
        }
        for (int j = 0; j < n; j++)
            tab[i][j] = '.';
        tab[i][n] = '\0';
    }
    return (tab);
}

int is_safe(char **tab, int n, int row, int col)
{
    int i, j;

    for (i = 0; i < row; i++)
    {
        if (tab[i][col] == 'Q')
            return (0);
    }
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (tab[i][j] == 'Q')
            return (0);
    }
    for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (tab[i][j] == 'Q')
            return (0);
    }
    return (1);
}


int solveNQueens(char **tab, int n, int row)
{
    if (row == n)
        return (1);

    for (int col = 0; col < n; col++)
    {
        if (is_safe(tab, n, row, col))
        {
            tab[row][col] = 'Q';
            if (solveNQueens(tab, n, row + 1))
                return (1);
            tab[row][col] = '.';
        }
    }
    return (0);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (0);

    int n = atoi(argv[1]);
    if (n < 1)
        return (0);

    char **tab = create_tab(n);
    if (!tab)
        return (1);

    if (!solveNQueens(tab, n, 0))
        printf("Aucune solution trouvée.\n");
    else
        print_tab(tab, n);

    free_tab(tab, n);
    return (0);
}
