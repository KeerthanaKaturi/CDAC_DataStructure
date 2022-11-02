#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *list;
struct node *curr;
void enque(int element)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	curr = list;
	if(curr==NULL)
	{
		temp->data = element;
        	temp->next = list;
       		list =temp;
       }
	else
	{
		while(curr->next!=NULL)
		{
			curr=curr->next;
		}
	curr->next=temp;
	temp->data = element;
	temp->next=NULL;
	}
}
int deque()
{
	struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
	int x=-1;
	if(list!=NULL)
	{
		temp=list;
		x=temp->data;
		list=temp->next;
		free(temp);
	}
	else
		printf("Queue is empty\n");
	return x;
	
}
void Display()
{
	struct node *curr;
	curr=list;
	while(curr!=NULL)
	{
		printf("%d ",curr->data);
		curr=curr->next;
	}
}
int main()
{
	int num;
	int ele;
	int pele;
	int dele;
	int ch;
	int i;
	int j=1;
	while(1)
	{
		printf("\n1. Create a queue\n2. Enqueue\n3. Dequeue\n4. Display\n5. Quit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter how many elements you want in the list");
				scanf("%d",&num);
				for(i=0;i<num;i++)
				{
					printf("Enter element %d of your list: ",j++);
					scanf("%d",&ele);
					enque(ele);
				}
				printf("\nYour queue: ");
				Display();
				break;
			case 2:
				printf("Enter the element to be enqued: ");
				scanf("%d",&pele);
				enque(pele);
				printf("\nQueue after enqueing an element: ");
				Display();
				break;
			case 3:
				printf("\nElement dequed: %d",deque());
				printf("\nQueue after dequeing an element: ");
				Display();
				break;
			case 4:
				printf("\nQueue:");
				Display();
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("\nInvalid choice");
				break;
		}
	}
	return 0;
}
