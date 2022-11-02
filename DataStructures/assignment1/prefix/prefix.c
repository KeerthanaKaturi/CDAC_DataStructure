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
		case ')':
		case ']':
		case '}':
			return 1;
	}
}
int reverse(char prefix[20],int n,int size)
{
	char temp;
	temp = prefix[n];
	prefix[n] = prefix[size - n];
	prefix[size - n] = temp;
	if(n == size/2)
		return prefix;
	return reverse(prefix,++n,size);
}
int main()
{
	int i,j=0;
	char ch,p;
	char infix[20],prefix[20],reversed[20];
	gets(infix);
	int len = strlen(infix);
	for(i=len-1;i>=0;i--)
	{
		ch = infix[i];
		switch(ch)
		{
			case ')':
			case ']':
			case '}':
				push(ch);
				break;
			case '(':
			case '[':
			case '{':
				while(1)
				{
					p = pop();
					if(p==')'||p==']'||p=='}')
						break;
					prefix[j++]=p;
				}
				break;
			case '*':
			case '+':
			case '-':
			case '/':
				while(!IsEmpty() && pre(peek()) >= pre(ch))
					prefix[j++] = pop();
				push(ch);
				break;
			default:
				prefix[j++] =ch;
		}
	}
	while(!IsEmpty())
	{	prefix[j++]=pop();
//		prefix[j++]='\0';
        }
	prefix[j++] = '\0';
	len = strlen(prefix);
	reverse(prefix,0,len-1);
	
	printf("\n prefix expression =");
		puts(prefix);
	return 0;
}


