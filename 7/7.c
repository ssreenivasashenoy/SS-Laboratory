#include <stdio.h>
int main()
{
    int ch, n, i, time_quantum, remain, time, count, flag = 0, waittime = 0, turnaroundtime = 0;
    int swaittime = 0, sturnaroundtime = 0, smallest, endtime;
    int rt[10], at[10], bt[10];
    printf("1.Round Robin\n2.SRTF\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("Enter the number of processes: ");
        scanf("%d", &n);
        printf("Enter arrival time: ");
        for (i = 0; i < n; i++)
        {
            scanf("%d", at[i]);
        }
        printf("Enter burst time: ");
        for (i = 0; i < n; i++)
        {
            scanf("%d", bt[i]);
            rt[i] = bt[i];
        }
        printf("Enter the time quantum:");
        scanf("%d", &time_quantum);
        remain = n;
        printf("PROCESS\t|COMPLETION TIME\t|TURNAROUND TIME\t|WAITING TIME");
        for (time = 0, count = 0; remain != 0;)
        {
            if (rt[count] <= time_quantum && rt[count] > 0)
            {
                time += rt[count];
                rt[count] = 0;
                flag = 1;
            }
            else if (rt[count] > 0)
            {
                rt[count] -= time_quantum;
                time += time_quantum;
            }
            if (rt[count] == 0 && flag == 1)
            {
                remain--;
                printf("%d\t|\t%d\t|\t%d\t|\t%d\t", count + 1, time, time - at[count], time - at[count] - bt[count]);
                waittime += time - at[count] - bt[count];
                turnaroundtime += time - at[count];
                flag = 0;
            }
            if (count == n - 1)
            {
                count = 0;
            }
            else if (at[count + 1] <= time)
            {
                count++;
            }
            else
            {
                count = 0;
            }
        }
        printf("Avg Waiting time:%f", (waittime * 1.0) / n);
        printf("Avg Turn around time:%f", (turnaroundtime * 1.0) / n);
        break;
    case 2:
        printf("Enter the number of processes: ");
        scanf("%d", &n);
        printf("Enter arrival time: ");
        for (i = 0; i < n; i++)
        {
            scanf("%d", at[i]);
        }
        printf("Enter burst time: ");
        for (i = 0; i < n; i++)
        {
            scanf("%d", bt[i]);
            rt[i] = bt[i];
        }
        remain = 0;
        printf("PROCESS\t|COMPLETION TIME\t|TURNAROUND TIME\t|WAITING TIME");
        rt[9] = 999;
        for (time = 0; remain != n; time++)
        {
            smallest = 9;
            for (i = 0; i < n; i++)
            {
                if (at[i] <= time && rt[i] < rt[smallest] && rt[i] > 0)
                {
                    smallest = i;
                }
                rt[smallest]--;
                if (rt[smallest] == 0)
                {
                    remain++;
                    endtime = time + 1;
                    printf("%d\t|\t%d\t|\t%d\t|\t%d\t", smallest + 1, endtime, endtime - at[smallest], time - bt[smallest] - at[smallest]);
                    swaittime += endtime - bt[smallest] - at[smallest];
                    sturnaroundtime += endtime - at[smallest];
                }
            }
        }
        printf("Avg Waiting time:%f", (swaittime * 1.0) / n);
        printf("Avg Turn around time:%f", (sturnaroundtime * 1.0) / n);
        break;
    default:
        printf("Invalid input!");
    }
    return 0;
}