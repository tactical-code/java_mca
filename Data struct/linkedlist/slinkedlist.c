//single linked list

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

void create();
void beginert();
void lastinsert();
void randominsert();
void begindelete();
void lastdelete();
void randomdelete();
void display();
void search();

void main()
{
    int v;
    for ( ; ; )
    {
    printf("\n\t\t 1.INSERTATBEG \n\t\t 2.INSERTATLAST \n\t\t 3.RANDOMINSERT \n\t\t 4.DELETEATBEG \n\t\t 5.DELETEATLAST \n\t\t 6.DELETEATRANDOM \n\t\t 7.DISPLAY \n\t\t 8.SEARCH \n\t\t 9.EXIT \n\t\t10.CREATE");
    printf("\nEnter the function: ");
    scanf("%d", &v);

    
        switch(v)
        {
            case 1: beginert();
                    break;
            case 2: lastinsert();
                    break;
            case 3: randominsert();
                    break;
            case 4: begindelete();
                    break;
            case 5: lastdelete();
                    break;
            case 6: randomdelete();
                    break;
            case 7: display();
                    break;
            case 8: search();
                    break;
            case 10: create();
                    break;
            case 9: exit(0);
        }
    }   

}

void create()
{
    int n;
    char choise = 'y';
    struct node *ls;
    //head=NULL;
    while (choise == 'y')
    {
        printf("\nEnter the data: ");
        scanf("%d", &n);
        if(head==NULL)
        {
             head=(struct node *)malloc(sizeof(struct node));
             head->data=n;
             head->next=NULL;
        }
        else
        {
            ls=head;
            while(ls->next!=NULL)
            {
                ls=ls->next;
            }
            ls->next=(struct node *)malloc(sizeof(struct node));
            ls->next->data=n;
            ls->next->next=NULL;
        }
        printf("\nDo you wants to continue: ");
        fflush(stdin);
        scanf("%c", &choise);
    }
}

void beginert()
{
    struct node *ptr;
    int item;
    ptr=(struct node *)malloc(sizeof(struct node));
    if (ptr==NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter a value: ");
        scanf("%d", &item);
        ptr->data=item;
        ptr->next=head;
        printf("\nNode inserted");
    }
}

void lastinsert()
{
    struct node *ptr, *temp;
    int item;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter a value: ");
        scanf("%d",&item);
        ptr->data=item;
        if(head==NULL)
        {
            ptr->next=NULL;
            head=ptr;
            printf("\nNode inserted");
        }
        else
        {
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=NULL;
            printf("\nNode inserted");
        }
    }
}

void randominsert()
{
    int i, loc, item;
    struct node *ptr, *temp;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter a number: ");
        scanf("%d", &item);
        ptr->data = item;
        printf("\nEnter the location after which you want to insert: ");
        scanf("%d", &loc);
        temp=head;
//traveling to the desired location        
        for(i=1;i<loc;i++)
        {
            temp=temp->next;//travel code 

            if(temp==NULL)
            {
                printf("\ncan't insert\n");
                return;
            }
        }
//connecting new node in the linked list
        ptr->next=temp->next;
        temp->next=ptr;
        printf("\nNode inserted");
    }
}

void begindelete()
{
  struct node *ptr; //extra pointer
  if(head==NULL)
  {
    printf("\nList is empty");
  }  
  else
  {
    ptr=head; //storing head add in new pointer
    head=ptr->next;//pointing head to second node
    free(ptr);
    printf("\nNode deleted from the begining\n");
  }
}

void lastdelete()
{
    struct node *ptr, *ptr1;
    if (head == NULL)
    {
        printf("\nList is empty");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        free (head);
        printf("\nOnly node of the list deleted\n");
    }
    else 
    {
        ptr=head;//pointing 1st pointer to first node
        while(ptr->next!=NULL)
        {
            ptr1=ptr;//pointing 2nd pointer to 1st node
            ptr=ptr->next;//pointing 1st pointer to 2nd node
        }
        ptr1->next=NULL;//storing Null to 2nd last node throung 2nd pointer
        free(ptr);//free last node whose add is in 1st pointer
        printf("\nDeleted node from the last");
    }
}

void randomdelete()
{
    struct node *ptr, *ptr1;
    int loc, i;

    printf("\nEnter the target location to perform deletion: ");
    scanf("%d", &loc);

    ptr=head;
    i=1;
    while (i<loc-1)
    {
        ptr=ptr->next;

        if(ptr==NULL)
        {
            printf("\nCan't delete");
            return;
        }
    }  
    ptr1=ptr->next;//setting ptr1 on target
    ptr->next=ptr1->next;//link both(node) side of the target
    free(ptr1);
    printf("\nDeleted node %d", loc);
}

void search()
{
    struct node *ptr;
    int item, i, flag=0;
    ptr=head;
    if(ptr==NULL)
    {
        printf("\nEmpty list :(");
    }
    else
    {
        printf("\nEnter the target item: ");
        scanf("%d", &item);
        while(ptr!=NULL)
        {
            if (ptr->data==item);
            {
                printf("\nFound at %d :)", i+1);
                flag=1;
            }
            i++;
            ptr=ptr->next;
        }
    }
}

void display()
{
    struct node *ptr;
    ptr=head;
    if(ptr==NULL)
    {
        printf("\nNothing to print :(");
    }
    else
    {
        printf("\nPrinting values .........\n");
        while(ptr!=NULL)
        {
            printf("%d -> ", ptr->data);
            ptr=ptr->next;
        }
    }
}


