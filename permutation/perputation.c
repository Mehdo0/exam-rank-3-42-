#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str){int i=0;while(str[i])i++;return(i);}

void    swap(char *str, int i, int j)
{
    char    tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
}

void    bubble_sort(char *str, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (str[j] > str[j + 1])
            {
                swap(str, j, j + 1);
            }
        }
    }
}

int next_permutation(char *str, int len)
{
    int i = len - 2;
    while (i >= 0 && str[i] >= str[i + 1])
        i--;
    if (i < 0)
        return (0);
    int j = len - 1;
    while (str[j] <= str[i])
        j--;
    swap(str, i, j);
    int start = i + 1;
    int end = len - 1;
    while (start < end)
    {
        swap(str, start, end);
        start ++;
        end--;
    }
    return (1);
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    int len = ft_strlen(av[1]);
    char    *str = malloc(len + 1);
    if (!str)
        return (1);
    for (int i = 0; i < len;i++)
        str[i] = av[1][i];
    bubble_sort(str, len);
    do {
        printf("%s\n", str);
    }while (next_permutation(str, len));
    free(str);
    return (0);
}