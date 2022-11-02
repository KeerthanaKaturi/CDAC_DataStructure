#include<stdio.h>
#include<stdlib.h>
struct stack{
	int size;
	int tos;
	int s[];
}sta;

int IsEmpty()
{
	if(sta.tos == -1)
		return 1;
	return 0;
}

int IsFull()
{
	if(sta.tos == sta.size -1)
		return 1;
	return 0;
}
int length()
{
	return sta.tos+1;
}
void Display()
{
	int i=0;
	if(!IsEmpty())
	{
		for(;i<=sta.tos;i++)
		{
			printf("Element at %d is %d",i,sta.s[i]);
		}
	}
	else 
		printf("Stack is Empty");
}
void push(int element)
{
	if(!IsFull())
	{
		sta.tos++;
		sta.s[sta.tos] = element;
		printf("Pushed element: %d\n",sta.s[sta.tos]);
	}
	else
		printf("Stack is full");
}
int pop()
{
	int x = -1;
	if(!IsEmpty())
	{
		x= sta.s[sta.tos];
		sta.tos--;
	}
	else 
		printf("Stack is Empty\n");
	return x;
}
int peek()
{
	int x = -1;
        if(!IsEmpty())
        {
                x= sta.s[sta.tos];
        }
        else
                printf("Stack is Empty\n");
	return x;
}
int main()
{
	sta.size;
	sta.tos = -1;
	printf("Enter no. of elements: ");
	scanf("%d",&sta.size);
	sta.s[sta.size];
	printf("Enter the %d elements of array: ",sta.size);
	int i;
	for(i=0;i<sta.size;i++)
	{
		int j;
		scanf("%d",&j);
		push(j);
	}
	printf("Top element is %d\n",peek());
	printf("Stack size is %d\n",length());
	for(i=0;i<sta.size;i++)
	{
		printf("Popped element is %d\n",pop());
	}
	return 0;
}


