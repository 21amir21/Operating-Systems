#include <stdio.h>
#include <stdlib.h>

/*
 * Producer - Consumer Problem
 *
 * is a synchronization problem where there is a fixed size buffer where the
 * producer produces items and that is consumed by a consumer process
 *
 *
 * We have a buffer of fixed size.
 * A producer can produce an item and can place in the buffer.
 * A consumer can pick items and can consume them.
 * We need to ensure that when a producer is placing an item in the buffer,
 * then at the same time consumer should not consume any item. In this problem, buffer is the critical section.
 *
 *
 * A semaphore 'S' is an integer variable that can be accessed only through two standard operations :
 * wait() and signal().
 *
 * The wait() operation reduces the value of semaphore by 1
 * and the signal() operation increases its value by 1.
 */

// Global Variables // All the semaphores
int mutex = 1, full = 0, empty = 3, x = 0;

int wait(int s)
{
    return (--s);
}

int signal(int s)
{
    return (++s);
}

void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\nProducer produces the item %d", x);
    mutex = signal(mutex);
}

void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nConsumer consumes the item %d", x);
    x--;
    mutex = signal(mutex);
}

int main()
{
    int n;
    printf("\n1.Producer\n2.Consumer\n3.Exit");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            if (mutex == 1 && empty != 0)
                producer();
            else
                printf("Buffer is full!!");
            break;

        case 2:
            if (mutex == 1 && full != 0)
                consumer();
            else
                printf("Buffer is empty!!");
            break;

        case 3:
            exit(0);
            break;
        }
    }

    return 0;
}