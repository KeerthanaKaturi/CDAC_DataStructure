#include<stdio.h>
void enque(int);
int deque(void);
int underflow(void);
int overflow(void);
void display(void);
struct queue
{
	int size;
	int front,rear;
	int q[];
}que;
void main()
{
	que.size;
	que.front = -1;
	que.rear = -1;
	printf("\nEnter the size of array: ");
	scanf("%d",&que.size);
	que.q[que.size];
	for(int i=0;i<que.size;i++)
	{
		int j;
		printf("Enter the %d no. of array: ",i+1);
		scanf("%d",&j);
		enque(j);
	}
	for(int i=0;i<que.size;i++)
	{
		deque();
	}
		display();
}
int underflow(void)
{
	if(que.front == -1 && que.rear == -1)
		return 1;return 0;
}
int overflow(void)
{
	if((que.rear + 1)%que.size == que.front)
		return 1;
	return 0;
}
void enque(int ele)
{
	if(!overflow())
	{
		if(que.front == -1 && que.rear == -1)
			que.front++;
		que.rear = (que.rear+1)%que.size;
		que.q[que.rear]=ele;
	}
	else
		printf("\nqueue is full");
}
int deque()
{
	int x=-1;
	if(!underflow())
	{
		x = que.q[que.front];
		if(que.front == que.rear)
			que.front=que.rear=-1;
		else
			que.front=(que.front+1)%que.size;
	}
	else
		printf("\nthe queue is empty");
	printf("\nthe deque element is %d",x);
	return x;
}
void display(void)
{
	int i;
	if(!underflow())
	{
		for(i = que.front;i!=que.rear;i=(i+1)%que.size)
			printf("element is %d\n",que.q[i]);
	}
	else
		printf("\nthe queue is empty");
}

