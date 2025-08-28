//stack using linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};
struct node *h = NULL;

void display(struct node*);
void push();
void pop(struct node*);

void main()
{
    int n;
    for( ; ; )
    {
        printf("\n1.DISPLAY\n2.PUSH\n3.POP\n4.EXIT");
        printf("\nEnter choise: ");
        scanf("%d", &n);

        switch(n)
        {
            case 1: display(h);
                    break;
            case 2: push(h);
                    break;
            case 3: pop(h);
                    break;
            case 4: exit(0);
                    break;
            default: printf("Invalid choise"); 

        }
    }
}

void push()
{
    struct node *ls;
    int v;

    printf("\nEnter a number: ");
    scanf("%d", &v);

    if(h==NULL)
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

void pop(struct node *ls)
{
    if(h==NULL)
    {
        printf("\nStack overflow");
    }
    else if(ls->next==NULL)
    {
        free(ls);
        h=NULL;
    }
    
    else
    {
      while(ls->next->next!=NULL)
      {
        ls=ls->next;
      }
      free(ls->next);
      ls->next=NULL;
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