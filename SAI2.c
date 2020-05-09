#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void ascending(int * a,int n);
void descending(int * a,int n);
void random_array(int * a,int n);
void almost_sorted(int *a,int n);
void display(int * a,int n);
void copy(int * a,int * b,int n);
void create(int * a,int n);
void selection_sort(int * a,int n);
void shell_sort(int * a, int n1);
void insertion_sort(int * a,int n);
void counting_sort(int * a,int n,int r);
void sorting(int * a,int * b,int n);

void main()
{
	int *arr,*b,n;
	printf("Enter the size of an array: ");
	scanf("%d",&n);
	arr=(int *)calloc(n,sizeof(int));
	create(arr,n);
	copy(arr,b,n);
    sorting(arr,b,n);
}

void ascending(int * a,int n)
{
 int i;
 for(i=0;i<n;i++)
 {
    a[i]=i+1;
 }
}

void descending(int * a,int n)
{
 int i;
 for(i=0;i<n;i++)
 {
    a[i]=n-i;
 }
}

void random_array(int * a,int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    a[i]=rand()/100;
  }
}
void almost_sorted(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(i%2==0)
			a[i]=rand()%10;
		else
			a[i]=i+1;
	}	
}

void display(int * a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d \t",a[i]);
	}
}

void copy(int * a,int * b,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		b[i]=a[i];
	}
}

void create(int * a,int n)
{
    int c,d,i;
   
	printf("\n Enter 1 for creation of array in ascending order \n      2 for Descending order \n      3 for creation of a random array \n      4 for almost sorted array ");
	scanf("%d",&c);
	switch(c)
	{
	    case 1:
		ascending(a,n);
		break;

	    case 2:
		descending(a,n);
		break;

	    case 3:
		random_array(a,n);
		break;
       
        case 4:
		almost_sorted(a,n);
		break;
				
	    case 0:
		exit(0);
		break;
		
	    default:

		printf("Wrong input");
       }
		for(i=0;i<n;i++)
	{
	  printf("%d \t",a[i]);
	}
}

void selection_sort(int * a,int n)
{
int i,j;
printf("sorted array is  ");
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(a[i]>a[j])
{
int temp;
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}

}

void shell_sort(int * a, int n1)
{
int i,j,key,h[3]={5,3,1},n2,k;
n2=3;
printf("\n The gap size considered is: ");
printf("\n");
for(i=0;i<n2;i++)
{
	printf("%d \t",h[i]);
}
for(j=0;j<n2;j++)
{
  for(i=h[j];i<n1;i++)
  {
    key=a[i];
    k=i;
    while(k>=h[j] && a[k-(h[j])]>key)
    {
     a[k]=a[k-(h[j])];
     k=k-h[j];
    }
    a[k]=key;
  }
  
}

}

void insertion_sort(int * a,int n)
{
int i,j,k;
  for(k=1;k<n;k++)
  {
   i=a[k];
   j=k-1;
   while((i<a[j])&&(j>=0))
   {
   a[j+1]=a[j];
   j--;
   }
   a[j+1]=i;
   }
   
}

void counting_sort(int * a,int n,int r)
{
	int output[n],count[r];
	int i;
	for(i=0;i<=r;i++)
	{
		count[i]=0;
	}
	for(i=0;i<n;i++)
	{
		count[a[i]]++;
	}
	for(i=1;i<=r;i++)
	{
		count[i]=count[i]+count[i-1];
	}
	for(i=n;i>=1;i--)
	{
		output[count[a[i-1]-1]]=a[i-1];
		count[a[i]]--;
	}
		for(i=0;i<n;i++)
	{
		a[i]=output[i];
	}

}

void sorting(int * a,int * b,int n)
{
 int c,range,i;
 clock_t t1,t2;
 double total;
 range=0;
	for(i=0;i<n;i++)
	{
		if(range<a[i])
		{
			range=a[i];
		}
	}
     do
    {
	printf("\n Enter 1 for selection sort \n      2 for insertion sort \n      3 for shell sort \n      4 for counting sort \n      5 to exit  ");
	scanf("%d",&c);

	switch(c)
	{
	case 1:
	copy(a,b,n);
	t1=clock();
	selection_sort(b,n);
	t2=clock();
	total=(double)(t1-t2)/CLOCKS_PER_SEC;
	
	printf("\n Array before sorting: ");
	display(a,n);
	
	printf("\n Array after sorting: ");
	display(b,n);
	
	printf("\n The time required is: %f",total);
	break;
	
	case 2:
	copy(a,b,n);
	t1=clock();
	insertion_sort(b,n);
	t2=clock();
	total=(double)(t1-t2)/CLOCKS_PER_SEC;
	
	printf("\n Array before sorting: ");
	display(a,n);
	
	printf("\n Array after sorting: ");
	display(b,n);
	
	printf("\n The time required is: %f",total);
	break;
	
	case 3:
	copy(a,b,n);
	t1=clock();
	shell_sort(b,n);
	t2=clock();
	total=(double)(t1-t2)/CLOCKS_PER_SEC;
	
	printf("\n Array before sorting: ");
	display(a,n);
	
	printf("\n Array after sorting: ");
	display(b,n);
	
	printf("\n The time required is: %f",total);
	break;
	
	case 4:
	copy(a,b,n);
	printf("\n The range of counting sort is %d \n:",range);
	t1=clock();
	counting_sort(b,n,range);
	t2=clock();
	total=(double)(t1-t2)/CLOCKS_PER_SEC;

	printf("\n Array before sorting: ");
	display(a,n);

	printf("\n Array after sorting: ");
	display(b,n);

	printf("\n The time required is: %f",total);
	break;

	case 5:
	exit(0);
	break;

	default:
	printf("Wrong input");

	}

	}while(c!=5);
}

