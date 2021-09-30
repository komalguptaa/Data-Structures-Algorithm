#include <stdio.h>
#include <stdlib.h>
#define max 5
int cqueue[max];
int front=-1;
int rear=-1;
void insert( int );
void deletee();
void display();

int main()
{
	while(1)
	{
	 int choice;
	printf("\nEnter 1 to insert\nEnter 2 to delete\nEnter 3 to display\nEnter 4 to exit\n");
	printf("Enter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			{
				int val;
				printf("Enter the value to be entered\n");
				scanf("%d",&val);
				insert(val);
				break;
			}
	   case 2:
	   	{
	   		deletee();
	   		break;
		   }
		case 3:
		   	{
		   	display();
		   	break;
		   }
		case 4:exit(0);
		default:
		   	printf("Wrong Choice!!Please try again");		   	
	}		
  }
}
void insert(int val)
 {
	if((rear==(max-1) && front==0)||(front==rear+1))
	printf("QUEUE OVERFLOW\n");
	else if (rear==-1)
	{
		rear++;
		front++;
	}
	else if(rear==(max-1) && (front>0))
		rear=0;
	else 
	rear=rear+1;
	cqueue[rear]=val;
    }

void deletee()
{

	int val;
	if(front==-1 && rear==-1)
	{
	printf("QUEUE UNDERFLOW\n");
    }
    else
    {
	val= cqueue[front];
	if(front==rear)
	{
	front=-1;
	rear=-1;
    }
	else
	{
		if(front==max-1)
		front=0;
		else
	    front++;
	}	
	printf("The deleted element is %d : \n",val);
 }
}
void display()
{
	int i;
		if(front==-1)
	printf("QUEUE IS EMPTY\n");
	else
	{
		printf("The QUEUE elements are:\n");
		if(rear>=front)
		{
			for( i=front;i<=rear;i++)
			{
				printf("%d ",cqueue[i]);
			}	
		}
		else
		{
		
		for( i=front;i<max;i++)
	{
		printf("%d ",cqueue[i]);
	}
	for( i=0;i<=rear;i++)
	{
		printf("%d ",cqueue[i]);
	}
	printf("\n");
   }
}
}
