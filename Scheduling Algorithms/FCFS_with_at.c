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

    printf("Enter number of processess -- ");
    scanf("%d", &n);

    p = (int *)malloc(n * sizeof(int));
    at = (int *)malloc(n * sizeof(int));
    bt = (int *)malloc(n * sizeof(int));
    ct = (int *)malloc(n * sizeof(int));
    wt = (int *)malloc(n * sizeof(int));
    tat = (int *)malloc(n * sizeof(int));

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
            if (ct[i - 1] < at[i]) // low el ablyy 5ls abl ma ana awsl
            {
                ct[i] = ct[i - 1] + bt[i] + (at[i] - ct[i - 1]);
            }
            else // low el ablyy 5ls fy nfs el wa2t el ana wslt fyh aw b3d ma ana wslt
            {
                ct[i] = ct[i - 1] + bt[i];
            }
        }

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        awt += wt[i];
        atat += tat[i];
    }

    // hna b2a el print

    return 0;
}