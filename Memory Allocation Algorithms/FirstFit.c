#include <stdio.h>
#include <conio.h>
#define max 25

// First-FIT ALGORITHM
void main()
{
    int frag[max], b[max], displayBlock[max], f[max], i, j, nb, nf, temp = 0;
    static int used_block_num[max], block_file_num[max];

    printf("\nMemory Management Scheme - First Fit");

    printf("\nEnter the number of blocks:");
    scanf_s("%d", &nb);

    printf("Enter the number of files:");
    scanf_s("%d", &nf);

    printf("\nEnter the size of the blocks:-\n");
    for (i = 1; i <= nb; i++)
    {
        printf("Block %d:", i);
        scanf_s("%d", &b[i]);
    }

    printf("Enter the size of the files :-\n");
    for (i = 1; i <= nf; i++)
    {
        printf("File %d:", i);
        scanf_s("%d", &f[i]);
    }

    for (i = 1; i <= nf; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (used_block_num[j] != 1)
            {
                temp = b[j] - f[i];
                if (temp >= 0)
                {
                    block_file_num[i] = j;
                    break;
                }
                // else if (block_file_num[i] == 0)
                //     block_file_num[i] = -1;
            }
        }

        if (block_file_num[i] == 0)
        {
            displayBlock[i] = -1;
            frag[i] = -1;
            block_file_num[i] = -1;
        }
        else
        {
            used_block_num[block_file_num[i]] = 1;
            frag[i] = temp;
            displayBlock[i] = b[block_file_num[i]];
        }
    }

    printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
    for (i = 1; i <= nf; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], block_file_num[i], displayBlock[i], frag[i]);
}