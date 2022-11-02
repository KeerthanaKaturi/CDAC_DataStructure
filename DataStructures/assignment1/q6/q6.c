#include<stdio.h>
#include<stdlib.h>
void insert_begin(int ele);
void insert_end(int ele);
void insert_before(int a,int ele);
void insert_after(int a,int ele);
void forward();
int del_begin();
int del_last();
void del_specific(int a);
void travel_back();
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *dll;
struct node *temp;
struct node *curr;
void insert_begin(int ele)
{
	temp = (struct node *)malloc(sizeof(struct node *));
	temp->data = ele;
	temp->next = NULL;
	temp->prev=dll;
	if(dll!=NULL)
		dll->prev=temp;
	dll=temp;
}
void forward()
{
	curr=dll;
	while(curr != NULL)
	{
		printf("%d\t",curr->data);
		curr= curr->next;
	}
}
void insert_end(int ele)
{
	temp = (struct node *)malloc(sizeof(struct node *));
	temp->data=ele;
	temp->next=NULL;
	if(dll!=NULL)
	{
		curr=dll;
		while(curr->next!=NULL)
			curr=curr->next;
		temp->prev=curr;
		curr->next=temp;
	}
	else
	{
		temp->prev=dll;
		dll=temp;
	}
}
void insert_after(int a,int ele)
{
	if(dll!=NULL)
	{
		curr=dll;
		while(curr!=NULL && curr->data!=a)
		{
			curr = curr->next;
		}
		if(curr!=NULL)
		{
			temp = (struct node *)malloc(sizeof(struct node *));
			temp->data=ele;
			temp->prev=curr;
			temp->next=curr->next;
			if(curr->next!=NULL)
				curr->next->prev=temp;
			curr->next=temp;
		}
		else
			printf("element not present");
	}
	else
		printf("List is not present");
}
void insert_before(int a,int ele)
{
	if(dll!=NULL)
	{
		curr=dll;
		while(curr!=NULL && curr->next->data !=a)
			curr=curr->next;
		if(curr==NULL)
			printf("Node is not present\n");
		else
		{
			temp = (struct node *)malloc(sizeof(struct node *));
			temp->data=ele;
			temp->prev= curr->next->prev;
			temp->next=curr->next;
			if(curr->prev==NULL)
				dll=temp->prev;
			curr->next->prev=temp;
			curr->next=temp;
		}
	}
	else
		printf("List is not present\n");

}
int del_begin()
{
	int x=-1;
	if(dll!=NULL)
	{
		temp=dll;
		x=temp->data;
		dll=temp->next;
		if(temp->next!=NULL)
			temp->next->prev=NULL;
		free(temp);
	}
	else
		printf("List is empty\n");
	return x;
}
int del_last()
{
	int x=-1;
	if(dll!=NULL)
	{
		curr=dll;
		while(curr->next!=NULL)
			curr=curr->next;
		x=curr->data;
		if(curr->prev!=NULL)
			curr->prev->next=NULL;
		else
			dll=NULL;
	}
	else
		printf("list empty\n");
	return x;
}
void del_specific(int a)
{
	if(dll!=NULL)
	{
		curr=dll;
		while(curr!=NULL && curr->data!=a)
			curr=curr->next;
		if(curr!=NULL)
		{
			if(curr->prev!=NULL)
				curr->prev->next=curr->next;
			else
				dll=curr->next;
			if(curr->next != NULL)
				curr->next->prev=curr->next;
		}
		else
			printf("element not found\n");
	}
	else
		printf("List is empty\n");
}
void travel_back()
{
	curr=dll;
	if(curr!=NULL)
	{
		while(curr->next!=NULL)
			curr=curr->next;
		while(curr!=NULL)
		{
			printf("%d",curr->data);
			curr=curr->prev;
		}
	}
}
int main()
{
	int i,n,element,c,a;
	while(1)
	{
		printf("\nEnter your choice");
		printf("\n1. Insert at begining\n2. Insert at the end\n3. Move forward\n4. Insert after\n5. Insert Before");
		printf("\n6. Delete begining\n7. Delete last\n8. Delete specific\n9. Travel back\n10. Exit");
		scanf("%d",&n);
		switch(n)
		{
			case 1:printf("\nEnter the element: ");
			       scanf("%d",&element);
			       insert_begin(element);
			       break;
			case 2:printf("\nEnter the element: ");
                               scanf("%d",&element);
                               insert_end(element);
                               break;
			case 3:forward();
			       break;
			case 4:printf("\nEnter the element and new element: ");
                               scanf("%d%d",&a,&element);
                               insert_after(a,element);
                               break;
			case 5:printf("\nEnter the element and new element: ");
                               scanf("%d%d",&a,&element);
                               insert_before(a,element);
                               break;
			case 6:del_begin();
			       break;
			case 7:del_last();
			       break;
			case 8:printf("Which element want to be deleted: \n");
			       scanf("%d",&c);
			       del_specific(c);
			       break;
			/*case 9:
			       rev();
			       break;*/
			case 9:
			       travel_back();
			       break;
			case 10:
			       exit(1);
			       break;
			default:printf("\nWrong choice");
				break;
		}
	}
return 0;
}
