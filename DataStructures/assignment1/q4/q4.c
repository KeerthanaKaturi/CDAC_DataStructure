#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node*next;
   
};
struct node*list;
struct node*temp;
struct node*curr;
struct node*list3=NULL;
struct node*list1=NULL;
struct node*list2=NULL;
struct node *insert(struct node *list,int ele)
{
   temp=(struct node *)malloc(sizeof(struct node *));
   temp->data=ele;
   temp->next=NULL;
   if(list==NULL)
      list=temp;
    else
      {
        curr=list;
        while(curr->next!=NULL)
            curr=curr->next;
        curr->next=temp;
         
      }
   return list;
}

void forward(struct node *list)
{
  curr=list;
   while(curr!=NULL)
   {
     printf("%d\t",curr->data);
     curr=curr->next;
   }
   list3 = NULL;
}
struct node *merge(struct node *list3,struct node *list1,struct node *list2)
{
   struct node *c1,*c2;
   c1=list1;
   c2=list2;
   while(c1!=NULL&&c2!=NULL)
    {
      if(c1->data<c2->data)
       {
        list3=insert(list3,c1->data);
        c1=c1->next;
       }
     else if(c2->data<c1->data)
        {
          list3=insert(list3,c2->data);
           c2=c2->next;
        }
      else
        {
          list3=insert(list3,c1->data);
            c1=c1->next;
            c2=c2->next;
        }
     }
        while(c1!=NULL)
          {
             list3=insert(list3,c1->data);
              c1=c1->next;

          }
            while(c2!=NULL)
          {
             list3=insert(list3,c2->data);
              c2=c2->next;

          }
        
  return list3;
}
      

int main()
{  

  int element,n,a;
   while(1)
  {
  printf("\nenter your choice:");
  printf("\n1.Enter element of list 1\n2.Enter the element of list 2:\n3.Print list\n4.Exit\n");
  scanf("%d",&n);
  switch(n)
   {
     case 1:printf("Enter the no. of elements in list1:");
            scanf(" %d",&a);
	    for(int i =0;i<a;i++)
	    {
		    printf("Enter element %d: ",i);
		    scanf("%d",&element);
           		 list1=insert(list1,element);
	    }
            break;
     case 2:printf("\nEnter the no. of elements in list2:");
            scanf(" %d",&a);
            for(int i =0;i<a;i++)
            {
		    printf("Enter element %d: ",i);
                    scanf("%d",&element);
                         list2=insert(list2,element);
            }
            break;
     case 3:printf("\n\tfirst list:\n\t");
            forward(list1);
            printf("\n\tsecound list:\n\t");
            forward(list2);
            printf("\n\tmegered list :\n\t");
            list3=merge(list3,list1,list2);
            forward(list3);
            break;
    case 4:exit(1);
           break;
   }
 }
}
