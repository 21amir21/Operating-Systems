// -----------------------------------------------------------------------------
// Sequential File Allocation
// -----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

void store(int blocks[])
{
    int available_storage = 1, startBlock, len, i, j, ch;

    printf("Enter the index of the starting block: ");
    scanf_s("%d", &startBlock);
    printf("Enter the length of the file: ");
    scanf_s("%d", &len);

    for (i = startBlock; i < (startBlock + len); i++)
    {
        if (blocks[i] != 0)
        {
            available_storage = 0;
            break;
        }
    }

    if (available_storage == 1)
    {
        for (j = startBlock; j < (startBlock + len); j++)
        {
            if (blocks[j] == 0)
            {
                blocks[j] = 1;
                printf("%d\t%d\n", j, blocks[j]);
            }
        }

        if (j == (startBlock + len))
            printf("\nThe file is allocated to the disk\n");
    }
    else
        printf("There are no available storage for storing the file on the disk\n");

    printf("\nDo you want to enter more files?\n");
    printf("Press 1 for YES, 0 for NO: ");
    scanf_s("%d", &ch);
    if (ch == 1)
        store(blocks);
    else
        exit(0);
    return;
}

int main()
{
    int blocks[50];
    for (int i = 0; i < 50; i++)
        blocks[i] = 0;

    printf("Files Allocated are :\n");
    store(blocks);

    return 0;
}