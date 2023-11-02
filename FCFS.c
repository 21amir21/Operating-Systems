#include <stdio.h>
#include <stdlib.h>
/*
 * First Come First Serve algorithm
 *
 * you take the burst time of each process as input from user
 * then you calculate the waiting time and turnaround time of each process
 *
 */
int main()
{
    // int bt[20], wt[20], tat[20], i, n;
    int *bt, *wt, *tat, i, n;
    float wtavg, tatavg;

    printf("\nEnter number of processes -- ");
    scanf("%d", &n);

    // in C99 and later versions you don't have to type cast malloc functions,
    // (if you are using Visual Studio u MUST do the type cast as in wt & tat)
    bt = malloc(n * sizeof(int)); // it automatically cast it to the right data type based on the var
    wt = (int *)malloc(n * sizeof(int));
    tat = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        printf("\nEnter Burst Time for Process %d -- ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];

    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1]; // waiting time = waiting time of prev + burst time of prev
        tat[i] = tat[i - 1] + bt[i];   // turnaround time = turnaround of prev + my burst time
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\n\t PROCESS \t BURST TIME \t WAITING TIME \t TURNAROUND TIME\n");
    for (i = 0; i < n; i++)
    {
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", i + 1, bt[i], wt[i], tat[i]);
    }
    printf("\n\nAverage Waiting Time --> %f", wtavg / n);
    printf("\nAverage Turnaround Time --> %f", tatavg / n);

    free(bt);
    free(wt);
    free(tat);

    return 0;
}