#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
   struct node *prev;
};
struct node *temp;
struct node *dll;
struct node *curr;
void insertfront(int ele)
{
	temp = (struct node *)malloc(sizeof(struct node *));
	temp->data = ele;
	temp->next = dll;
	temp->prev=NULL;
	if(dll!=NULL)
	dll->prev=temp;
	dll=temp;
}
void insertlast(int ele)
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
void deletefront()
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
}
void deletelast()
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
}

void dequeue()
{
	int n,k;
   printf("\nEnter the choice\n1. Output restricted deque\n2. Input restricted deque");
   scanf("%d",&n);
   switch(n)
   {
           case 1: printf("\nChoice is Output restricted deque");
                   printf("\nInsert 1.front or 2.back: ");
                   scanf("%d",&k);
                   switch(k)
                {
                        case 1:deletefront();
                                break;
                        case 2:deletelast();
                                 break;
                        default:printf("\nInvalid choice");
                                   break;
                }
					break;
           case 2: printf("\nChoice is Input restricted deque");
                   printf("\nYou can access any end for taking output");
                   deletefront();
                   deletelast();
                        break;
           default:printf("\nInvalid choice");
		   break;
}
}

void enqueue(int ele)
{
   int n,k;
   printf("\nEnter the choice\n1. Input restricted deque\n2. Output restricted deque");
   scanf("%d",&n);
   switch(n)
   {
           case 1: printf("\nChoice is input restricted deque");
                   printf("\nInsert 1.front or 2.back: ");
                   scanf("%d",&k);
                   switch(k)
                {
                        case 1:insertfront(ele);
                                break;
                        case 2:insertlast(ele);
                                 break;
                        default:printf("\nInvalid choice");
                                   break;
                }
					break;
           case 2: printf("\nChoice is output restricted deque");
                   printf("\nYou can access any end for giving input");
                   insertfront(ele);
                   insertlast(ele);
                        break;
           default:printf("\nInvalid choice");
                   break;
	}

}

void display()
{
curr = dll;
    while(curr!=NULL)
       {
		printf("%d  ",curr->data);
		curr=curr->next;
		}
}


void main()
{
   int n,c,element;
   while(1)
   {
      printf("\n1.Enque\n2.Deque\n3.display\n4.exit\n");
      printf("\nenter your choice:");
      scanf("%d",&n);
      switch(n)
        {
            case 1: printf("\n\tenter the element:");
                    scanf("%d",&element);
                    enqueue(element);
                    break;
            case 2: dequeue();
                    //printf("\n\tdeteled front element:%d",c);
                    break;
           case 3:display();
                  break;
           case 4:exit(1);
                  break;
           default :printf("\n\tenter worng choice");
       }//switch
   }//while
 }//main                 
