#include <stdio.h>
#include <stdlib.h>
/*
 * Shortest Job First algorithm
 *
 * you take the burst time of each process as input from user
 * sort them from lowest to highest based on their burst time
 * then you calculate the waiting time and turnaround time of each process
 */

int main()
{
    int p[20], bt[20], wt[20], tat[20], i, j, n, temp;
    float wtavg, tatavg;

    printf("\nEnter number of processes -- ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
        printf("\nEnter Burst Time for Process %d -- ", i + 1);
        scanf("%d", &bt[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (bt[i] > bt[j])
            {
                // swapping the burst time to sort it ascending
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                // swapping the process ID to sort it ascending as well
                // you have to swap the process IDs to keep everything in track
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];

    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\n\t PROCESS \t BURST TIME \t WAITING TIME \t TURNAROUND TIME\n");
    for (i = 0; i < n; i++)
    {
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", p[i], bt[i], wt[i], tat[i]);
    }
    printf("\n\nAverage Waiting Time --> %f", wtavg / n);
    printf("\nAverage Turnaround Time --> %f", tatavg / n);

    return 0;
}