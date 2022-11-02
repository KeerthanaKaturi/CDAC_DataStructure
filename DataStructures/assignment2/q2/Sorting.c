#include<stdio.h>
#include<stdlib.h>

int a[30];
int n;

int Swap(int *a, int*b)
{
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}//swap

int Bubble_sort(int a[30], int n)
{
  int i;
  int j;
  int flag=0;
  for(i=0;i<=n-1;i++)
    {
       for(j=0;j<=n-2-i;j++)
       {
          if(a[j] > a[j+1])
                  Swap(&a[j],&a[j+1]);
          flag=1;
       }
   if(flag==0)
       break;
    }
         
}//bubble sort

int Insertion_sort(int a[30], int n)
{
  int i;
  int j;
  int temp;
  for(i=1;i<=n-1;i++)
     {
        j=i-1;
	temp=a[i];
	while(j>=0 && a[j]>temp)
	    {
	      a[j+1] = a[j];
	      j--;
	    }
	a[j+1]=temp;
     }
 
}//insertion sort	

int Selection_Sort(int a[30], int n)
{
 int i;
 int j;
 int loc;
 for(i=0;i<n;i++)
     {
        loc=i;
	for(j=i+1;j<n;j++)
           {
	       if(a[j] < a[loc])
		       loc=j;
	   }
	if(loc!=i)
		Swap(&a[i],&a[loc]);
     }
 
}//selection sort	

int Quick_Sort(int low, int high)
{
  int i;
  int j;
  int pivot;
  pivot = a[low];
  i=low+1;
  j=high;
  if(low<high)
     {
         while(1)
	   {
	     while(a[j]>pivot)
		     j--;
	     while(i<=high && a[i]<pivot)
		     i++;
	     if(i<j)
		  Swap(&a[i],&a[j]);
             else
	         break;
	   }//while
        Swap(&a[low],&a[j]);
        Quick_Sort(low,j-1);
	Quick_Sort(j+1,high);
     }
}//quick sort

 void Merge(int low, int mid, int high)
	{
		int i, j, k = 0, index = low;
		i = low, j = mid+1;
		int *l3;
		l3 = (int *)malloc(sizeof(high-low+1));

		while(i <= mid && j <= high)
		{
			if(a[i] < a[j])
				l3[index++] = a[i++];
			else
				l3[index++] = a[j++];
		}
		while(i <= mid)
			l3[index++] = a[i++];
		while(j <= high)
			l3[index++] = a[j++];
		for(k = low; k<index;k++)
			a[k] = l3[k];
		free(l3);
	}//merge

void M_sort(int low, int high)
        {
                if(low < high)
                {
                        int mid = (low + high)/2;
                        M_sort(low,mid);
                        M_sort(mid+1,high);
                        Merge(low, mid, high);
                }
        }//merge sort


int Heapify(int i, int size)
{
  int temp;
  int c;
  for (temp= a[i]; 2*i+1<size; i=c)
    {
     	  c=2*i+1;
     if(2*i+2<size && a[2*i+2]>a[i])
   	   c++;
     if(a[c]>temp)
 	  a[i]=a[c];
     else
	break;
    }
 a[i]=temp;
}//heapify

int Heap_Sort(int a[30],int n)
{
  int i;
  for(i=n/2 -1;i>=0;i--)
	  Heapify(i,n);
  for(i=n-1;i>=1;i--)
     {
         Swap(&a[0],&a[i]);
	 Heapify(0,i);
     }
  
 }//Heap sort	

int main()
{
  int i;
  int n;
  int ch;
  while(1)
   {	  
    /* printf("\n Enter the size of array: ");
     scanf("%d",&n);
     printf("\n Enter %d element of array:  ",n);
     for(i=0;i<=n-1;i++)
       { 
          scanf("%d",&a[i]);
       }*/
     printf("\n 1.Bubble Sort \n 2.Insertion Sort \n 3.Selection Sort \n 4.Quick Sort \n 5.Merge Sort \n 6.Heap Sort \n 7.Quit");
     printf("\n Enter your choice: ");
     scanf("%d",&ch);
     switch(ch)
     {
        case 1://bubble
              printf("\n Enter the size of array: ");
              scanf("%d",&n);
              printf("\n Enter %d element of array:  ",n);
     	      for(i=0;i<=n-1;i++)
       		{
          	  scanf("%d",&a[i]);
       		}
	      Bubble_sort(a,n);	
              printf("\n Your Array after Bubble Sort: ");
              for(i=0;i<n;i++)
   		 {
       		    printf(" %d",a[i]);
    		 }
	      printf("\n");
	      break;	
	case 2://insertion
	      printf("\n Enter the size of array: ");
              scanf("%d",&n);
              printf("\n Enter %d element of array:  ",n);
              for(i=0;i<=n-1;i++)
                {
                  scanf("%d",&a[i]);
                }
              Insertion_sort(a,n);
	      printf("\n Your Array after Insertion Sort: ");
              for(i=0;i<n;i++)
                 {
                    printf(" %d",a[i]);
                 }
              printf("\n");
	      break;	
	case 3://selection
	      printf("\n Enter the size of array: ");
              scanf("%d",&n);
              printf("\n Enter %d element of array:  ",n);
              for(i=0;i<=n-1;i++)
                {
                  scanf("%d",&a[i]);
                }
	      Selection_Sort(a,n);
	      printf("\n Your Array after Selection Sort: ");
              for(i=0;i<n;i++)
                 {
                    printf(" %d",a[i]);
                 }
              printf("\n");
	      break;	
	case 4://quick
	       printf("\n Enter the size of array: ");
              scanf("%d",&n);
              printf("\n Enter %d element of array:  ",n);
              for(i=0;i<=n-1;i++)
                {
                  scanf("%d",&a[i]);
                }
              Quick_Sort(0,n-1);
	      printf("\n Your Array after Quick Sort: ");
              for(i=0;i<n;i++)
                 {
                    printf(" %d",a[i]);
                 }
              printf("\n");
	      break;	
	case 5://merge
	       printf("\n Enter the size of array: ");
              scanf("%d",&n);
              printf("\n Enter %d element of array:  ",n);
              for(i=0;i<=n-1;i++)
                {
                  scanf("%d",&a[i]);
                }

	      M_sort(0,n-1);
	      printf("\n Your Array after Merge Sort: ");
              for(i=0;i<n;i++)
                 {
                    printf(" %d",a[i]);
                 }
              printf("\n");
	      break;	
	case 6://heap
	       printf("\n Enter the size of array: ");
              scanf("%d",&n);
              printf("\n Enter %d element of array:  ",n);
              for(i=0;i<=n-1;i++)
                {
                  scanf("%d",&a[i]);
                }

	      Heap_Sort(a,n);
	      printf("\n Your Array after Heap Sort: ");
	      for(i=0;i<n;i++)
                 {
                    printf(" %d",a[i]);
                 }
              printf("\n");
	      break;	
	case 7://exit
	      exit(0);
      	      break;	      
	default:
	    printf("\n INVALID CHOICE!!!");
            break;	    
     }//switch     

   }//while     

 return 0; 
}//main	

