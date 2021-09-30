#include <stdio.h>
#include <stdlib.h>
#define Max 10
void push();
void pop();
void display();
int top=-1;

int a[Max];
 int main()
{
	
	
	int choice;
	while(1)
	{
	
	printf("1.Enter 1 to push\n2.Enter 2 to pop\n3.Enter 3 to display\n4.Enter 4 to exit\n");
	printf("Enter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		{
		push();
		break;}
		case 2:pop();
		break;
		case 3:display();
		break;
		case 4:exit(0);
		default:printf("\nWrong Choice\n");
	}
}
}

void push()
{
	int value;
	if(top==Max-1)
	printf("STACK OVERFLOW\n");
	else
	{
		printf("enter the value\n");
		scanf("%d",&value);
		top++;
		a[top]=value;
	}
}
void pop()
{ 
	if(top==-1)
	{
		printf("STACK UNDERFLOW\n");
	}
	else
	{
		
		printf("The poped item is %d\n",a[top]);
		top--;
		
	}
	}
	void display()
	{
		if(top==-1)
	{
		printf("STACK IS EMPTY");
	}
	else
	{
		for(int i=top;i>=0;i--)
		printf("%d\n",a[top]);
	}
}


