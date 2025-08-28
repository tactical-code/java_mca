#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
# define max 5
void enqueue();
void dequeue();
void show();
int a[max], rear = - 1, front = - 1, count = 0;

void main()
{
    int n;
        printf("\t\t\t1.Enqueue Operation\n");
        printf("\t\t\t2.Dequeue Operation\n");
        printf("\t\t\t3.Display the Queue\n");
        printf("\t\t\t4.Exit\n");

        for ( ; ;)
        {
        printf("\nEnter your noice of operations : ");
        scanf("%d", &n);
            switch (n)
            {
                case 1:
                enqueue();
                break;
                case 2:
                dequeue();
                break;
                case 3:
                show();
                break;
                case 4:
                exit(0);
                default:
                printf("Incorrect noice \n");
            }    
        } 
} 

void enqueue()
{
    int v;

    if (count == max)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        printf("Enter a number: \n");
        scanf("%d", &v);
        rear++;
         
        if (rear > max - 1)
        {
            rear = 0;
        }
        a[rear]=v;
        count++;
    }
}

void dequeue()
{
    if (count == max)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("%d is Deleted", a[front]);
        front++;
        if (front > max - 1)
        {
            front = 0;
        }
    }
    count++;
}

void show()
{
    int i;
    if (count == 0)
    {
        printf("Queue Empty\n");
    }
    else
    {
        if (rear >= front)
        {
            for (i=front; i<=rear; i++)
            {
                printf("%d ", a[i]);
            }
        }

        if (rear < front)
        {
            for (i=front; i<=max-1; i++)
            {
                printf("%d ", a[i]);
            }
             for(i=0; i<=rear; i++)
             {
                printf("%d ", a[i]);
             }
        }
    }
}