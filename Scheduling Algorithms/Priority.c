#include <stdio.h>
#include <stdlib.h>
/*
 * Priority algorithm
 *
 * you take the burst time & priority of each process as input from user
 * sort them according to their priority
 *
 * They will be executed based on their priority
 */

int main()
{
    int p[20], bt[20], pri[20], wt[20], tat[20], i, j, n, temp;
    float wtavg, tatavg;
    printf("Enter the number of processes --- ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
        printf("Enter the Burst Time & Priority of Process %d --- ", i + 1);
        scanf("%d %d", &bt[i], &pri[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (pri[i] > pri[j])
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pri[i];
                pri[i] = pri[j];
                pri[j] = temp;
            }
        }
    }
    wtavg = wt[0] = 0;
    tatavg = tat[0] = bt[0];

    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\n\n\t PROCESS\t PRIORITY \t BURST TIME \t WAITING TIME \t TURNAROUND TIME");
    for (int i = 0; i < n; i++)
    {
        printf("\n\t %d \t\t %d \t\t %d \t\t %d \t\t %d ", p[i], pri[i], bt[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time --> %f", wtavg / n);
    printf("\nAverage Turnaround Time --> %f", tatavg / n);

    return 0;
}