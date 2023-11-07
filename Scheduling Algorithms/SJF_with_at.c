#include <stdio.h>
#include <stdlib.h>

void arr_swapping(int *arr, int i, int j)
{
    int temp;

    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main()
{
    int *p, *at, *bt, *ct, *wt, *tat, n, temp;
    float awt = 0, atat = 0;
    int bt_min, bt_min_pos;

    printf("Enter number of processess -- ");
    scanf("%d", &n);

    p = (int *)malloc(n * sizeof(int));
    at = (int *)malloc(n * sizeof(int));
    bt = (int *)malloc(n * sizeof(int));
    ct = (int *)malloc(n * sizeof(int));
    wt = (int *)malloc(n * sizeof(int));
    tat = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
        printf("Enter the burst time of process %d -- ", i + 1);
        scanf("%d", &bt[i]);

        printf("Enter the arrival time of process %d -- ", i + 1);
        scanf("%d", &at[i]);
    }

    // da5l el bt w el at bta3 el process
    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
        printf("Enter the burst time of process %d -- ", i + 1);
        scanf("%d", &bt[i]);

        printf("Enter the arrival time of process %d -- ", i + 1);
        scanf("%d", &at[i]);
    }

    // now the loops for swapping and sorting

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                arr_swapping(p, i, j);
                arr_swapping(at, i, j);
                arr_swapping(bt, i, j);
            }
            else if (at[i] == at[j])
            {
                if (p[i] > p[j])
                {
                    arr_swapping(p, i, j);
                    arr_swapping(at, i, j);
                    arr_swapping(bt, i, j);
                }
            }
        }
    }

    // now the logic
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            ct[i] = at[i] + bt[i];
        else
        {
            bt_min = bt[0];
            for (int j = i; j < n; j++)
            {
                if (at[j] <= ct[i - 1])
                {
                    if (bt[j] < bt_min)
                    {
                        bt_min = bt[j];
                        bt_min_pos = j;
                    }
                }
            }

            arr_swapping(p, i, bt_min_pos);
            arr_swapping(at, i, bt_min_pos);
            arr_swapping(bt, i, bt_min_pos);

            if (ct[i - 1] < at[i])
            {
                ct[i] = ct[i - 1] + bt[i] + (at[i] - ct[i - 1]);
            }
            else
            {
                ct[i] = ct[i - 1] + bt[i];
            }
        }

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        awt += wt[i];
        atat += tat[i];
    }

    // hna el print b2aa

    return 0;
}