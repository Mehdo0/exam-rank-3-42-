#include <stdlib.h>
#include <stdio.h>

void find_subsets(int *set, int size, int target, int *subset, int subsize, int idx)
{
    if (idx == size)
    {
        int sum = 0;
        int i = 0;
        while (i < subsize)
        {
            sum += subset[i];
            i++;
        }
        if (sum == target)
        {
            i = 0;
            while (i < subsize)
            {
                printf("%i ", subset[i]);
                i++;
            }
            printf("\n");
        }
        return ;
    }
    subset[subsize] = set[idx];
    find_subsets(set, size, target, subset, subsize + 1, idx + 1);
    find_subsets(set, size, target, subset, subsize, idx + 1);
}

int main(int argc, char **argv)
{
    if (argc < 3) return 1;
    int size = argc - 2;
    int target = atoi(argv[1]);
    int *set = malloc(sizeof(int) * size);
    int *subset = malloc(sizeof(int) * size);
    int i = 0;
    while (i < size)
    {
        set[i] = atoi(argv[i + 2]);
        i++;
    }
    find_subsets(set, size, target, subset, 0, 0);
    free(set);
    free(subset);
    return (0);
}