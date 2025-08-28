//queue using linked list

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};
struct node *h = NULL;

void display(struct node*);
void enqueue();
void dequeue(struct node*);

void main()
{
    int n;
    for( ; ; )
    {
        printf("\n1.DISPLAY\n2.ENQUEUE\n3.DEQUEUE\n4.EXIT");
        printf("\nEnter choise: ");
        scanf("%d", &n);

        switch(n)
        {
            case 1: display(h);
                    break;
            case 2: enqueue(h);
                    break;
            case 3: dequeue(h);
                    break;
            case 4: exit(0);
                    break;
            default: printf("Invalid choise"); 

        }
    }
}

void enqueue()
{
    struct node *ls;
    int v;
    printf("Enter the number to insert: ");
    scanf("%d", &v);

    if (h==NULL)
    {
        h=(struct node *)malloc(sizeof(struct node));
        h->val=v;
        h->next=NULL;
    }
    else
    {
        ls=h;
        while(ls->next!=NULL)
        {
            ls=ls->next;   
        }
        ls->next=(struct node *)malloc(sizeof(struct node));
        ls->next->val=v;
        ls->next->next=NULL;
    }
}

void dequeue(struct node *ls)
{
    if(h==NULL)
    {
        printf("Queue underflow");
    }
    else
    {
        h=h->next;
        free(ls);
    }
}

void display(struct node *ls)
{
    if(h==NULL)
    {
        printf("\nEMPTY LINKED LIST");
    }
    else
    {
        while(ls!=NULL)
        {
            printf(" %d", ls->val);
            ls=ls->next;
        }
        printf("\nEND");
    }
}