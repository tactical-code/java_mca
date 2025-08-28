#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
# define max 5
void enqueue();
void dequeue();
void show();
int inp_arr[max], Rear = - 1, Front = - 1;

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
    if (Rear == max - 1)
       printf("Overflow \n");
    else
    {
        if (Front == - 1)
        {
        Front = 0;
        }
        printf("\nInsert Element: ");
        scanf("%d", &v);
        Rear++;
        inp_arr[Rear] = v;
    }
} 
 
void dequeue()
{
    if (Front == - 1 || Front > Rear)
    {
        printf("Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from the Queue: %d\n", inp_arr[Front]);
        Front++;
    }
} 
 
void show()
{
    
    if (Front == - 1)
        printf("\nEmpty Queue :(\n");
    else
    {
        printf("\nQueue: \n");
        for (int i = Front; i <= Rear; i++)
            printf("%d ", inp_arr[i]);
        printf("\n");
    }
}