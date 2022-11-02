#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   int power;
   struct node *next;
   
};
struct node *list;
struct node *temp;
struct node *curr;
struct node *list3=NULL;
struct node *list1=NULL;
struct node *list2=NULL;
struct node *insert(struct node *list,int power,int ele)
{
   temp=(struct node *)malloc(sizeof(struct node *));
   temp->data=ele;
   temp->power=power;
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
     printf("%dx^%d\t",curr->data,curr->power);
     curr=curr->next;
   }
}

struct node *add(struct node *list3,struct node *list1,struct node *list2)
{
    struct node *c1;
    struct node *c2;
    c1=list1;
    c2=list2;
    while(c1!=NULL&&c2!=NULL)
      {
         if(c1->power > c2->power)
           {
            list3=insert(list3,c1->power,c1->data);
             c1=c1->next;
           }
         else if(c2->power > c1->power)
            {
              list3=insert(list3,c2->power,c2->data);
              c2=c2->next;
           } 
         else
          {
           list3=insert(list3,c1->power,c1->data+c2->data);
           c1=c1->next;
           c2=c2->next;
          }
       }
    return list3;
}     

void main()
{
int element,n,power;
   while(1)
  {
  printf("\nenter your choice:");
  printf("\n1.enter element of list 1\n2.enter the element of list 2:\n3.print list\n4.exit\n");
  scanf("%d",&n);
  switch(n)
   {
     case 1:printf("\n\tenter the elements:");
            scanf("%d",&element);
            printf("\n\tenter the power:");
            scanf("%d",&power);
            list1=insert(list1,power,element);
            break;
     case 2:printf("\n\tenter the elements:");
            scanf("%d",&element);
             printf("\n\tenter the power:");
            scanf("%d",&power);
            list2=insert(list2 ,power,element);
            break;
     case 3:printf("\n\tfirst list:\n\t");
            forward(list1);
            printf("\n\tsecound list:\n\t");
            forward(list2);
            list3=add(list3,list1,list2);
            printf("\n\taddition of polynomial list :\n\t");
            forward(list3);
            break;
       case 4:exit(1);
           break;
   }
 }
}




