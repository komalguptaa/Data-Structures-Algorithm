#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
struct node *creation(struct node *start);
void insertatend(struct node *start,int data);
struct node *insertatbeg(struct node *start,int data);
struct node *deletefirstnode(struct node *start);
struct node *inbetween(struct node *start,int k);
struct node *lastnode(struct node *start);
void display(struct node *start);
	int main()
	{
		struct node *start=NULL;
	start=creation(start);
		int ch;
		while(1)
		{
			printf("ENTER 1 FOR DELETING FIRST NODE\n");
			printf("ENTER 2 FOR DELETING NODE IN BETWEEN\n");
			printf("ENTER 3 FOR DELETING LAST NODE\n");
			printf("ENTER 4 FOR DISPLAYING ELEMENTS\n");
			printf("ENTER 5 TO EXIT\n");
			scanf("%d",&ch);
			if(ch==5)
			exit(1);
			switch(ch)
			{
				case 1:
					start=deletefirstnode(start);
					break;
				case 2:
					int k;
					printf("Enter the position where the node to be is deleted\n");
					scanf("%d",&k);
					start=inbetween(start,k);
					break;
				case 3:
					start=lastnode(start);
					break;
				case 4:
					display(start);
					break;
				default:
					printf("INVALID CHOICE\n");
			}
		}
	}

struct node *creation(struct node *start)
{
	int i,n,data;
	printf("Enter number of nodes\n");
	scanf("%d",&n);
	if(n==0)
	return start;
	
	printf("Enter first element to be inserted\n");
	scanf("%d",&data);
	start= insertatbeg(start,data);
	
	for(i=2;i<=n;i++)
	{
		printf("Enter next element\n");
		scanf("%d",&data);
		insertatend(start,data);
	}
	return start;
			
}
struct node *insertatbeg(struct node *start,int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
				temp->info=data;
				temp->link=start;
				start=temp;
				return start;
}
void insertatend(struct node *start,int data)
{
	struct node *temp, *p;
	temp=(struct node *)malloc(sizeof(struct node*));
	temp->info=data;
	
	p=start;
	while(p->link!=NULL)
	p=p->link;
	p->link=temp;
	temp->link=NULL;
	
}
struct node *deletefirstnode(struct node *start)
{
	struct node *p;
	p=start;
	start=start->link;

	free(p);
	return start;
	
}
struct node *inbetween(struct node *start,int k)
{
	struct node *p,*temp;
	int i;
	p=start;
	for(i=1;i<k-1&&p!=NULL;i++)
	{
		
		p=p->link;
	}
	if(p==NULL)
	{
		printf("INVALID POSITION\n");
		return start;
	}
	temp=p->link;
	p->link=temp->link;

	free(temp);
	return start;
}
struct node *lastnode(struct node *start)
{
	struct node *p,*temp;
	p=start;
	int i;
	while(p->link->link!=NULL)
	{
		p=p->link;
	}
	temp=p->link;
	p->link=NULL;

	free(temp);
	return start;
	
}
void display(struct node *start)
{
	struct node *p;
	printf ("THE LIST IS : ");
	p=start;
	while(p!=NULL)
	{
		
		printf("%d ",p->info);
		p=p->link;
		
	}
	printf("\n");
	
}
