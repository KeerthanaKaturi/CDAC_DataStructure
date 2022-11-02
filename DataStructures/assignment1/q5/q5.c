#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *next;
};

void insert_begin(int );
void find(int );
int del_specific(int );
//int display(struct node *)


struct node *list;
struct node *temp;
struct node *curr;

void insert(int ele)
{
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = ele;
       temp->next = list;
	list = temp;
	 display(list);
}

int del_specific(int a)
{
	int x=-1;
	if(list != NULL)
	{
		if(list->data==a)
		{
			x=list->data;
			temp=list;
			list=temp->next;
			free(temp);
		}
		else
		{
			curr = list;
			while(curr->next!=NULL && curr->next->data != a)
				curr = curr->next;
			if(curr->next!=NULL)
			{
				x=curr->next->data;
				temp = curr->next;
				curr->next = temp->next;
				free(temp);
			}
			else
				printf("Element not found\n");
		}
	}
	else
		printf("List is empty\n");
//	 display(list);
	return x;
}
void find(int a)
{
	int d;
	d=del_specific(a);
	insert(d);
//	display(list);
}

int display(struct node *curr)
{
	 printf("%d ",curr->data);
	if(curr->next != NULL)
		return(display(curr->next));
	//printf("%d ",curr->data);
}
int main()
{
	int i,n,element,c,a;
	while(1)
	{
		printf("\nEnter your choice");
		printf("\n1. Insert");
		printf("\n2. Find\n3. Delete specific\n4. Exit");
		scanf("%d",&n);
		switch(n)
		{
			case 1:printf("\nEnter the element: ");
			       scanf("%d",&element);
			       insert(element);
			       break;
			case 2:printf("\nEnter the element to be found: ");
                               scanf("%d",&a);
                               find(a);
                               break;
			case 3:printf("Which element want to be deleted: \n");
                               scanf("%d",&c);
                               del_specific(c);
                               break;
			case 4:
			       exit(1);
			       break;
			default:printf("\nWrong choice");
				break;
		}
	}
	return 0;
}
