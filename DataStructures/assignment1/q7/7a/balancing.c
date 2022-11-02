#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
	int size;
	int tos;
	int s[];
}sta;

int isempty()
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
	if(!isempty())
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
		//printf("Pushed element: %d\n",sta.s[sta.tos]);
	}
	else
		printf("Stack is full");
}
int pop()
{
	int x = -1;
	if(!isempty())
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
        if(!isempty())
        {
                x= sta.s[sta.tos];
        }
        else
                printf("Stack is Empty\n");
	return x;
}
int main()
{
	sta.size=20;
	sta.tos = -1;
	int i,len,flag;
	char ch,p,infix[20];
	printf("Enter elements: ");
	scanf("%s",infix);
	len = strlen(infix);
	for(i =0;i<len;i++)
	{
		ch = infix[i];
		switch(ch)
		{
			case '(':
			case '[':
			case '{':
				push(ch);
				break;
			case ')':
			case ']':
			case '}':
				{
					if(!isempty())
					{
						p = peek();
						if((ch==')'&& p=='(')||(ch==']'&& p=='[')||(ch=='}'&& p=='{'))
							p = pop();
					}
					else
						flag = 1;
				break;
				}
		}
	if(flag == 1)
		break;
	}
	if(i == len && isempty())
		printf("Expression is balanced.");
	else
		printf("Expression is unbalanced.");

	return 0;
}

