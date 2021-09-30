#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 5
struct stack
{
	int data;
	struct stack *next;
};
struct stack *top=NULL;
struct stack *push(struct stack *, int);
struct stack *display(struct stack *);
struct stack *pop(struct stack *);

int main()
{
	int val,ch;
	while(1)
	{
		printf("\n ***MAIN MENU***");
		printf("\n 1.PUSH\n 2.POP \n 3.DISPLAY \n 4.EXIT");
		printf("\n Enter your option: ");
		scanf("%d",&ch);
		if(ch==4)
		exit(1);
		switch(ch)
		{
			case 1:
				printf("\n Enter number to be pushed on stack: ");
				scanf("%d",&val);
				top=push(top,val);
				break;
			case 2:
			    top=pop(top);
				break;
			case 3: 
			    top=display(top);
				break;
			default:
			    printf("\n INVALID CHOICE ");		
		}
	}
}

struct stack *push(struct stack *top, int val)
{
	struct stack *ptr;
	ptr=(struct stack *)malloc(sizeof(struct stack));
	ptr -> data= val;
	if(top == NULL)
	{
		ptr->next=NULL;
		top=ptr;
    }
    else
    {
    	ptr -> next =top;
    	top=ptr;
	}
    return top;
}
struct stack *display(struct stack *top)
{
	struct stack *ptr;
	ptr=top;
	if(top == NULL)
	printf("\n STACK EMPTY");
	else
	{
		while(ptr != NULL)
		{
			printf("\n %d",ptr->data);
			ptr= ptr -> next;
		}
	}
	return top;
}
struct stack *pop(struct stack *top)
{
	struct stack *ptr;
	ptr=top;
	if(top == NULL)
	printf("\n STACK UNDERFLOW");
	else
	{
		top= top -> next;
		printf("\n Value that is deleted = %d",ptr -> data);
		free(ptr);
	}
	return top;
}






