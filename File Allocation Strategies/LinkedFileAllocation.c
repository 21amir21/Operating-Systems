// -----------------------------------------------------------------------------
// Linked File Allocation
// -----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

void recursivePart(int blocks[])
{
    int st, len, k, ch, i;

    printf("Enter the index of the starting block: ");
    scanf_s("%d", &st);
    printf("Enter the length of the file: ");
    scanf_s("%d", &len);

    k = len;
    if (blocks[st] == 0)
    {
        for (i = st; i < (st + k); i++)
        {
            if (blocks[i] == 0)
            {
                blocks[i] = 1;
                printf("%d------>%d\n", i, blocks[i]);
            }
            else
            {
                printf("The block %d is already allocated \n", i);
                k++;
            }
        }
    }
    else
        printf("The block %d is already allocated \n", st);

    printf("\nDo you want to enter more files? \n");
    printf("Enter 1 for Yes, Enter 0 for No: ");
    scanf_s("%d", &ch);

    if (ch == 1)
        recursivePart(blocks);
    else
        exit(0);
    return;
}

int main()
{
    int blocks[50], p, a; // p is num of blocks already allocated
                          // a is the blocks that are allocated

    for (int i = 0; i < 50; i++)
        blocks[i] = 0;

    printf("Enter the number of blocks already allocated: ");
    scanf_s("%d", &p);

    for (int i = 0; i < p; i++)
    {
        printf("Enter the %d block already allocated: ", i + 1);
        scanf_s("%d", &a);
        blocks[a] = 1;
    }

    recursivePart(blocks);

    return 0;
}