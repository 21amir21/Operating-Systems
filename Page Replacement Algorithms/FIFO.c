// C program for FIFO page replacement algorithm
#include <stdio.h>
#define frames 3

int main()
{
    int incomingStream[] = {4, 1, 2, 4, 5};
    int temp[frames]; // frames array
    int pageFaults = 0;

    int hit, pages;

    pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

    printf("Incoming \t Frame 1 \t Frame 2 \t Frame 3");

    for (int i = 0; i < frames; i++)
    {
        temp[i] = -1;
    }

    for (int i = 0; i < pages; i++)
    {
        hit = 0;

        for (int j = 0; j < frames; j++)
        {
            if (incomingStream[i] == temp[j])
            {
                hit++;
            }
        }
        if (hit == 0)
        {
            pageFaults++;
        }

        if ((pageFaults <= frames) && (hit == 0))
        {
            temp[i] = incomingStream[i];
        }
        else if (hit == 0)
        {
            temp[(pageFaults - 1) % frames] = incomingStream[i];
        }

        printf("\n");

        printf("%d\t\t", incomingStream[i]);
        for (int i = 0; i < frames; i++)
        {
            if (temp[i] != -1)
                printf(" %d\t\t", temp[i]);
            else
                printf("- \t\t");
        }
    }

    printf("\nTotal Page Faults:\t%d\n", pageFaults);
    return 0;
}