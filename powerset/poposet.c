#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void    solve(int target, int size, int *set, int *subset, int subidx, int idx)
{
    if (idx == size)
    {
        int sum = 0;
        for (int i = 0; i < subidx; i++)
            sum += subset[i];
        if (sum == target)
        {
            for (int i = 0; i < subidx; i++)
                printf("%i ", subset[i]);
            printf("\n");
        }
        return ;
    }
    subset[subidx] = set[idx];
    solve(target, size, set, subset, subidx + 1, idx + 1);
    solve(target, size, set, subset, subidx, idx + 1);

}

int main(int ac, char **av)
{
    if (ac < 3)
        return (1);
    int target = atoi(av[1]);
    int size = ac - 2;
    int *set = malloc(sizeof(int)*size);
    int *subset = malloc(sizeof(int)*size);
    if (!set || !subset)
        return (1);
    for (int i = 0; i < size; i++)
        set[i] = atoi(av[i + 2]);
    solve(target, size, set, subset, 0, 0);
    free(set);
    free(subset);
    return (0);
}