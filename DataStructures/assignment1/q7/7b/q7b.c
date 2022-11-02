#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
	int size;
	int tos;
	int s[];
}sta;

int ctoi(char a)
{
	return (int)a-48;
}

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
void push(int element)
{
	if(!IsFull())
	{
		sta.tos++;
		sta.s[sta.tos] = element;
	}
	else
		printf("Stack is full\n");
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
int main()
{
	char ch;
	char postfix[40];
	int a,b,c,i;
	printf("Enter the expression: \n");
	scanf("%s",&postfix);
	int len = strlen(postfix);
	for(i=0;i<len;i++)
	{
		ch = postfix[i];
		switch(ch)
		{
			case '+':
				a=pop();
				b=pop();
				push(b+a);
				break;
			case '-':
				a=pop();
                                b=pop();
                                push(b-a);
                                break;
			case '*':
                                a=pop();
                                b=pop();
                                push(b*a);
                                break;
			case '/':
                                a=pop();
                                b=pop();
                                push(b/a);
                                break;
			default:
				c = ctoi(ch);
				push(c);
		}
	}
	printf("Result = %d",sta.s[1]);
	return 0;
	
}


