#include <stdio.h>
int sum(int s[20][20],int row,int col)
{
	int sum =0;	
       	for(int i=0;i<row;i++)
        {
                for(int j=0;j<col;j++)
                {
                        if(i>j)
                                sum = sum + s[i][j];
                }
        }
return sum;
}

int main()
{
	int a[20][20];
	int r,c;
	printf("Enter rows,columns: ");
	scanf("%d,%d",&r,&c);
	printf("\nEnter elements of array");
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			scanf("%d",&a[i][j]);
	}
	printf("\n Matrix:\n");
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			printf("%d",a[i][j]);
		printf("\n");
	}
	int s = sum(a,r,c);
	printf("Sum of elements of lower triangular matrix = %d\n",s);
	return 0;
}

