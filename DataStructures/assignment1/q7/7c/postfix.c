#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
int pre(char ch)
{
	switch(ch)
	{
		case '*':
		case '/':
			return 3;
		case '+':
		case '-':
			return 2;
		case '(':
		case '[':
		case '{':
			return 1;
	}
}
int main()
{
	int i,j=0;
	char ch,p;
	char infix[20],postfix[20];
	gets(infix);
	int len = strlen(infix);
	for(i=0;i<len;i++)
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
				while(1)
				{
					p = pop();
					if(p=='('||p=='['||p=='{')
						break;
					postfix[j++]=p;
				}
				break;
			case '*':
			case '+':
			case '-':
			case '/':
				while(!IsEmpty() && pre(peek()) >= pre(ch))
					postfix[j++] = pop();
				push(ch);
				break;
			default:
				postfix[j++] =ch;
		}
	}
	while(!IsEmpty())
	{	postfix[j++]=pop();
        }
	postfix[j++] = '\0';
	printf("\n @=");
		puts(postfix);
	return 0;
}


