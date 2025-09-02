#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct Node{
	int data;
	struct Node *next;
}node;

void insert(node *list, int dataX){
	node *start = list;
	while(list->next!=NULL)	{
		list = list -> next;
	}

	list->next = (node *)malloc(sizeof(node));
	list = list->next;
	list->data = dataX;
	list->next = NULL;
}

void insertAsFirst(node *list){
	node *nn = (node *)malloc(sizeof(node));
	printf("\nEnter the data to enter as first node: ");
	scanf("%d", &nn->data);
	nn->next =list->next;
	list->next = nn;
}

int find(node *list, int Key)
{
	node *start = list;
	list =  list -> next; //First node is dummy node.

	 while(list!=NULL)
	{
		if(list->data == Key) //Key is found.
		{
			return 1;
		}
		list = list -> next;//Search in the next node.
	}
	/*Key is not found */
	return 0;
}

void deleteNode(node *list, int data)
{
	node *start = list, *tmp;

	while(list->next!=NULL && (list->next)->data != data)
	{
		list = list -> next;
	}
	if(list->next==NULL)
	{
		printf("Element %d is not present in the list\n",data);
		return;
	}


	tmp = list -> next;
	list->next = tmp->next;
	free(tmp);
	return;
}

void pList(node *start,node *list)
{
	if(list==NULL)
	{
		return;
	}
	printf("%d->",list->data);
	pList(start,list->next);
}

void count(node *start){
  node *list;
  int c = 0;
  for(list = start; list->next != NULL; list = list->next){
	c =c+1;
  }
  printf("\n%d data present", c);
}

int main()
{

	node *start,*tmp;
	int data, flag, op;
	start = (node *)malloc(sizeof(node));
	start -> next = NULL;
	clrscr();
	while(1){
	printf("\n\n");
	printf("1. Insert\n");
	printf("2. Insert as first\n");
	printf("3. Delete\n");
	printf("4. Print\n");
	printf("5. Find\n");
	printf("6. To count\n");
	printf("7. Update the content of the list\n");
	printf("8. To exit\n");

		printf("Enter the option: ");
		scanf("%d",&op);
		clrscr();

		switch(op){
		case 1:
			printf("Enter the data to insert: ");
			scanf("%d",&data);
			insert(start,data);
			clrscr();
			printf("The list is: ");
			pList(start, start->next);
			break;

		case 2:
			clrscr();
			insertAsFirst(start);
			pList(start, start->next);
			break;
		case 3:
			clrscr();
			printf("\nBefore deletion the list is: ");
			pList(start, start->next);
			printf("\n Enter the data to delete: ");
			scanf("%d",&data);
			deleteNode(start,data);
			printf("\nAfter deletion the list is: ");
			pList(start, start->next);
			break;

		case 4:
			clrscr();
			printf("The list is: ");
			pList(start,start->next);
			printf("\n");
			break;

		case 5:
			clrscr();
			pList(start, start->next);
			printf("\n Enter the data to serach for: ");
			scanf("%d",&data);
			flag = find(start,data);
			if(flag) printf("\n%d is present", data);
			else printf("\n%d is not present", data);
			break;

		case 6:
			clrscr();
			count(start);
			break;
		case 7:
			//updateAnyPosition(start);
			break;
		case 8:
		       exit(0);
		 }

	    }
	}


