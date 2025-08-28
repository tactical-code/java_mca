//single linked list lab code (working)

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};
struct node *h = NULL;
void create();
void display(struct node*);
void insert(struct node*);
void delet(struct node*);
void reverse(struct node*);
void sort(struct node*);
void search(struct node*);

void main()
{
    int n;
    for( ; ; )
    {
        printf("\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.REVERSE\n6.SORT\n7.SEARCH\n8.EXIT");
        printf("\nEnter choise: ");
        scanf("%d", &n);

        switch(n)
        {
            case 1: create(h);
                    break;
            case 2: display(h);
                    break;
            case 3: insert(h);
                    break;
            case 4: delet(h);
                    break;
            case 5: reverse(h);
                    break;
            case 6: sort(h);
                    break;
            case 7: search(h);
                    break;
            case 8: exit(0);
                    break;
            default: printf("Invalid choise"); 

        }
    }
}

void create(struct node *ls)
{
   int n;
   char ch='y';
   while(ch=='y')
   {
    printf("Enter a number: ");
    scanf("%d", &n);
        if(h==NULL)
        {
            h=(struct node *)malloc(sizeof(struct node));
            h->val=n;
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
            ls->next->val=n;
            ls->next->next=NULL;
        }
        printf("\nDO YOU WANTS TO CONTINUE: ");
        fflush(stdin);
        scanf("%c", &ch);
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

void insert(struct node *ls)
{
    int v, pos, i;
    struct node *temp;
    printf("\nEnter a numeber to insert: ");
    scanf("%d", &v);
    printf("\nEnter the target position: ");
    scanf("%d", &pos);
    temp=(struct node *)malloc(sizeof(struct node));
    temp->val=v;
    if(pos==1)
    {
        temp->next=h;
        h=temp;
    }
    else
    {
        for(i=1;i<=pos-2;i++)
        {
            ls=ls->next;
        }
        temp->next=ls->next;
        ls->next=temp;
    }
}

void delet(struct node *ls)
{
    int pos, i;
    struct node *t;
    printf("\nEnter the target position: ");
    scanf("%d", &pos);
        if(pos==1)
        {
            h=h->next;
            free(ls);
        }
        else
        {
            for(i=1;i<=pos-2;i++)
            {
                ls=ls->next;
            }
            t=ls->next;
            ls->next=ls->next->next;
            free(t);
        }
}

void reverse(struct node *ls)
{
    int count=1, i;
    struct node *d;
    while(ls->next!=NULL)
    {
        count++;
        ls=ls->next;
    }
    while(count-2>=0)
    {
        d=h;
        for(i=1;i<=count-2;i++)
        {
            d=d->next;
        }
        d->next->next=d;
        count--;
    }
    h->next=NULL;
    h=ls;
}

void sort(struct node *ls)
{
    struct node *d;
    int t;
    while(ls->next!=NULL)
    {
        d=ls->next;
        while(d!=NULL)
        {
            if(ls->val>d->val)
            {
                t=ls->val;
                ls->val=d->val;
                d->val=t;
            }
            d=d->next;
        }
        d=ls->next;
    }
}

void search(struct node *ls)
{
    int count=1, k, f=0;
    printf("\nEnter the target value: ");
    scanf("%d", &k);
    while(ls!=NULL)
    {
        if(ls->val==k)
        {
            printf("\nFound at %d", count);
            f=1;
        }
        ls=ls->next;
        count++;
    }
    if(f==0)
    {
        printf("\nNOT FOUND");
    }
}