// --------------------------------------------------------------------------------
// Single Level Directory
// --------------------------------------------------------------------------------
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct
{
    char fname[10][10];
    int fcnt;
} dir;

int main()
{
    int i, ch;
    char f[30];
    dir.fcnt = 0;
    while (1)
    {
        printf("\n\n1. Create File\t2. Delete File\t3. Search File \n 4. Display Files\t5.Exit\nEnter your choice-- ");
        scanf_s("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter the name of the file -- ");
            scanf_s("%s", dir.fname[dir.fcnt], sizeof(dir.fname[dir.fcnt]) / sizeof(dir.fname[dir.fcnt][0]));
            dir.fcnt++;
            break;
        case 2:
            printf("\nEnter the name of the file -- ");
            scanf_s("%s", f, sizeof(f) / sizeof(f[0]));
            for (i = 0; i < dir.fcnt; i++)
            {
                if (strcmp(f, dir.fname[i]) == 0)
                {
                    printf("File %s is deleted ", f);
                    strcpy_s(dir.fname[i], sizeof(dir.fname[i]), dir.fname[dir.fcnt - 1]);
                    break;
                }
            }

            if (i == dir.fcnt)
                printf("File %s not found", f);
            else
                dir.fcnt--;
            break;
        case 3:
            printf("\nEnter the name of the file -- ");
            scanf_s("%s", f, sizeof(f) / sizeof(f[0]));

            for (i = 0; i < dir.fcnt; i++)
            {
                if (strcmp(f, dir.fname[i]) == 0)
                {
                    printf("File %s is found ", f);
                    break;
                }
            }

            if (i == dir.fcnt)
                printf("File %s not found", f);
            break;
        case 4:
            if (dir.fcnt == 0)
                printf("\nDirectory Empty");
            else
            {
                printf("\nThe Files are -- ");
                for (i = 0; i < dir.fcnt; i++)
                    printf("\t%s", dir.fname[i]);
            }
            break;
        default:
            exit(0);
        }
    }
}