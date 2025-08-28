#include <stdio.h>
#include <stdlib.h>
#define max 5

void push();
void pop();
void display();
int a[max], top = -1;

int main()
{
    int n;
        printf("\t\t1.Push\n\t\t2.Pop\n\t\t3.Diaplay\n\t\t4.Exit\n");
        
        for ( ; ;)
        {
            printf("\nEnter a value: ");
            scanf("%d", &n);
            
            switch(n)
            {
                case 1: push();
                        break;
                case 2: pop();
                        break;
                case 3: display();
                        break;
                case 4: exit(0);
            }
        }
}

void push()
{
    int v;
        if (top == max-1)
        {
            printf("Stack overflow");
        }
        else
        {
            printf("Enter a number: ");
            scanf("%d", &v);
            
            top++;
            a[top] = v;
        }
        
}

void pop()
{
    if (top == -1)
    {
        printf("Stack underflow");
    }
    else
    {
        top--;
    }
}

void display()
{
    int i;
        if (top == -1)
        {
          printf("\nStack is empty");
        }
        else
        {
          for (i=0 ; i<=top; i++)
          {
            printf("%d ", a[i]);
          }
        }
}