#include <stdio.h>
#define max 5
int a[max], left = -1, right = -1;

void display();
void insert_left();
void insert_right();
void delete_right();
void delete_left();
void output_que();
void input_que();

int main()
{
    int choice;
    printf("1.Input restricted dequeue\n2.Output restricted dequeue\n");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1: input_que();
                break;
        case 2: output_que();
                break;
        default: printf("Wrong choice\n");
    }
}

void input_que()
{
    int choice;
	do
	{	printf("1.Insert at right\n");
		printf("2.Delete from left\n");
		printf("3.Delete from right\n");
		printf("4.Display\n");
		printf("5.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{	case 1:
			insert_right();
			break;
		 case 2:
			delete_left();
			break;
		 case 3:
			delete_right();
			break;
		 case 4:
			display();
			break;
		 case 5:
            break;
		 default:
			printf("Wrong choice\n");
		}
	}while(choice!=5);
}

void output_que()
{
    int choice;
	do
	{	printf("1.Insert at right\n");
		printf("2.Insert at left\n");
		printf("3.Delete from left\n");
		printf("4.Display\n");
		printf("5.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1:
			insert_right();
			break;
		 case 2:
			insert_left();
			break;
		 case 3:
			delete_left();
			break;
		 case 4:
			display();
			break;
		 case 5:
			break;
		 default:
			printf("Wrong choice\n");
		}
	}while(choice!=5);
}

void delete_right()
{
    if(left==-1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from the queue is : %d\n", a[max]);
    if(left==right)
    {
        left=-1;
        right=-1;
    }
    else
    {
        if(right==0)
        {
            right=max-1;
        }
        else
        {
            right=right-1; //right--
        }
    }
}

void delete_left()
{
    if(left==-1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Enter deleted from queue is: %d\n", a[max]);
    if(left==right)
    {
        left=-1;
        right=-1;
    }
    else
    {
        if(left==max-1)
        left=0;
        else
        left=left+1;
    }
} 

void insert_right()
{
    int item;
    if((left==0 && right ==max-1) || (left == right+1)) 
    {
        printf("Queue Overflow\n");
        return;
    }
        if(left==-1)//empty queue
        {
            left=0;
            right=0;
        }
        else
            if(right==max-1) //if right at the last cell
                right=0;
            else
                right=right+1; //normal insert
        printf("Input the element for adding in queue: ");
        scanf("%d", &item);
        a[right]=item;   
}

void insert_left()
{
    int item;
    if((left==0 && right==max-1) || (left==right+1))
    {
        printf("Queue Overflow\n");
        return;
    }
    if(left==-1)
    {
        left=0;
        right=0;
    }
    else
        if(left==0)
            left=max-1;
        else
            left=left-1;

    printf("Input the element for adding in queue: ");
    scanf("%d", &item);
    a[max]=item;
}

void display()
{
    int front_pos = left, rear_pos = right;
    if(left==-1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue element :  \n ");
    if(front_pos <= rear_pos)
    {
        while(front_pos <= rear_pos)
        {
            printf("%d", a[front_pos]);
            front_pos++;
        }
    }
    else
    {
        while(front_pos <= max-1)
        {
            printf("%d", a[front_pos]);
            front_pos++;
        }

        front_pos=0;
        while(front_pos <= rear_pos)
        {
            printf("%d", a[front_pos]);
            front_pos++;
        }
    }

    printf("\n");
}

