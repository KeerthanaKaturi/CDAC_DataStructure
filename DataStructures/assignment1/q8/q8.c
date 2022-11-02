#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *list;
struct node *curr;
void Push(int element)
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
int Pop()
{
	struct node *temp;
	int x=-1;
	if(list != NULL)
	{
		if(list->next==NULL)
		{
			temp=list;
			x=temp->data;
			list = NULL;
			free(temp);
		}
		else
		{
			curr=list;
			while(curr->next->next != NULL)
			{
				curr=curr->next;
			}
			temp = curr->next;
			x = temp->data;
			curr->next = NULL;
			free(temp);
		}
	}
	else
		printf("Stack is empty\n");
	return x;
}
int peek()
{
	if(list == NULL)
		printf("\n Stack is empty");
	else
	{
		curr=list;
		while(curr->next!=NULL)
		{
			//printf("\nTop of stack is %d",curr->data);
			curr = curr->next;
		}
		printf("\nTop of stack is %d",curr->data);

	}
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
		printf("\n1. Create a stack\n2. Push\n3. Pop\n4. Peek\n5. Display\n6. Quit");
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
					Push(ele);
				}
				printf("\nYour stack: ");
				Display();
				break;
			case 2:
				printf("Enter the element to be pushed: ");
				scanf("%d",&pele);
				Push(pele);
				printf("\nStack after pushing an element: ");
				Display();
				break;
			case 3:
				printf("\nElement popped: %d",Pop());
				printf("\nStack after popping an element: ");
				Display();
				break;
			case 4:
				peek();
				break;
			case 5:
				printf("\nStack:");
				Display();
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("\nInvalid choice");
				break;
		}
	}
	return 0;
}
