#include <stdio.h>
#include <stdlib.h>
/*
 * Round Robin algorithm
 *
 * you take the burst time of each process as input from user
 * take the Time Slice (Quantum) from the user
 * get the highest value of the Burst time and store it in the max in order to know
 * how many times we need to loop over the whole processes
 *
 * We assume that all the processes have arrived at the same time
 */

int main()
{
    int bt[10], wt[10], tat[10], ct[10], i, j, n, t, max;
    float awt = 0, att = 0, temp = 0; // temp el 5t el a5drr
                                      // bt 5t a7mrr

    printf("Enter the number of processess -- ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the Burst Time for process %d -- ", i + 1);
        scanf("%d", &bt[i]);
        ct[i] = bt[i];
    }

    printf("Enter the size of time slice -- ");
    scanf("%d", &t);

    max = bt[0];
    for (int i = 1; i < n; i++)
    {
        if (max < bt[i])
        {
            max = bt[i];
        }
    }

    for (int i = 0; i < (max / t) + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (bt[j] != 0)
            {
                if (bt[j] <= t) // ana 5alst el process
                {
                    tat[j] = temp + bt[j];
                    temp += bt[j];
                    bt[j] = 0;
                }
                else // el process lsa ma5lstshh w hatd5ol tanyy
                {
                    bt[j] -= t;
                    temp += t;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - ct[i];
        att += tat[i];
        awt += wt[i];
    }

    printf("\nThe Average Turnaround Time is -- %f", att / n);
    printf("\nThe Average Waiting Time is -- %f", awt / n);
    printf("\n\n\t PROCESS\t BURST TIME \t WAITING TIME \t TURNAROUND TIME\n");
    for (int i = 0; i < n; i++)
    {
        printf("\t %d \t\t %d \t\t %d \t\t %d \n", i + 1, ct[i], wt[i], tat[i]);
    }

    return 0;
}