#include <stdio.h>
#include <stdlib.h>
struct Node {
  int item;
  struct Node *next;
};
void traverse(struct node* head){
	struct node* current=head; 
	int count=0; 
	printf("\n traversing the list\n");
	while(current!=NULL){ 
		count++; 
		printf("%d ",current->data);
		current=current->next; 
		
	}
	printf("\ntotal no of nodes : %d\n",count);
}

void insertAtBeginning(struct Node** ref, int data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->item = data;
  new_node->next = (*ref);
  (*ref) = new_node;
}



void printList(struct Node* node) {
  while (node != NULL) {
    printf(" %d ", node->item);
    node = node->next;
  }
}

int length(struct Node*head)
{
    int cnt=0;
    struct Node*t=head ;
    while(t!=NULL)
    {
        cnt++;
        t=t->next;
    }
    return cnt;
}
struct Node* insert_at_pos(int pos,struct Node*head,int value)
{
    if(pos<=0) return head ;
    struct Node*t=head ;
    struct Node*prev=NULL  ;
    int k=pos ;
     struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->item=value ;
    new_node->next=NULL ;
    while(k!=1 && t)
    {
        prev=t ;
        t=t->next ;
        k-- ;
    } 
    if(prev==NULL)
    {
        new_node->next=t ;
        return new_node ;
    }
    else
    {
        prev->next=new_node ;
        new_node->next=t ;
    }
    return head ;
}


int main() {
  struct Node* head = NULL;
  struct Node *temp,*prev;
		  int m,n,c,i=1,j,k;
    while(1)
	{
		
	 int choice;
	printf("\nEnter 1 to insert at head\nEnter 2 to insert at specified\nEnter 3 to delete end\nEnter 4 to exit\n\n");
	printf("Enter your choice\n");
	scanf("%d",&choice);
  switch(choice)
  {
      case 1 :
      {
      int no;
      scanf("%d",&no);
      insertAtBeginning(&head,no);
      break;
      }
      
      case 2:
      {
      int pos;
      int no_2;
      scanf("%d",&pos);
      scanf("%d",&no_2);
      struct Node* head1 =insert_at_pos(pos,head,no_2);
      printList(head1);
      break;
      }
          case 3 : 
          {
		  
		temp=head->next;
	    prev=head;
	while(temp->next!=NULL){
		temp=temp->next;
		prev=prev->next;
	} 
	// after traversal temp points to the last 
	//node and prev to the previous node of the last node
	prev->next=NULL;
	free(temp);
	traverse(head);
	printf("\last node deleted................\n");
	break;
}
        
        case 4:
        	{
        		exit(0);
			}
      default:
      printf("Wrong choice");
      exit(0);
}
}
}
