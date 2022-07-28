#include <stdio.h>
#include <stdlib.h>
int main()
{
    int max[10][10], alloc[10][10], need[10][10], avail[10], instance[10], completed[10], safeseq[10];
    int p, process, r, i, j, count = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &p);
    for (i = 0; i < p; i++)
    {
        completed[i] = 0;
    }
    printf("Enter the number of resources: ");
    scanf("%d", &r);
    printf("Enter the Instances : ");
    for (i = 0; i < r; i++)
    {
        avail[i] = 0;
        scanf("%d", &instance[i]);
    }
    printf("Enter the max matrix:");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the allocation matrix:");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            scanf("%d", &alloc[i][j]);
            avail[j] += alloc[i][j];
        }
    }
    for (i = 0; i < r; i++)
    {
        avail[i] = instance[i] - avail[i];
    }
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    do
    {
        printf("\nMax allocation:\tAllocation matrix:\n");
        for (i = 0; i < p; i++)
        {
            for (j = 0; j < r; j++)
            {
                printf("%d", max[i][j]);
                printf("\t");
            }
            printf("\t");
            for (j = 0; j < r; j++)
            {
                printf("%d", alloc[i][j]);
                printf("\t");
            }
            printf("\n");
        }
        process = -1;
        for (i = 0; i < p; i++)
        {
            if (completed[i] == 0)
            {
                process = i;
                for (j = 0; j < r; j++)
                {
                    if (avail[j] < need[i][j])
                    {
                        process = -1;
                        break;
                    }
                }
            }
            if (process != -1)
                break;
        }
        if (process != -1)
        {
            printf("Process %d runs to completeion", process + 1);
            safeseq[count] = process + 1;
            count++;
            for (j = 0; j < r; j++)
            {
                avail[j] += alloc[process][j];
                alloc[process][j] = 0;
                max[process][j] = 0;
                completed[process] = 1;
            }
        }
    } while (count != p && process != -1);
    if (count == p)
    {
        printf("Safe state\n");
        printf("<");
        for (i = 0; i < p; i++)
        {
            printf("%d", safeseq[i]);
        }
        printf(">\n");
    }
    else
    {
        printf("Unsafe state");
    }
}