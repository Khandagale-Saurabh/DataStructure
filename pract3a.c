#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void create(int * a,int n);
void ascending(int * a,int n);
void descending(int * a,int n);
void random_array(int * a,int n);
void almost_sorted(int * a,int n);
void display(int * a,int n);
void copy(int * a,int * b,int n);
void sorting(int * a,int * b,int n);
void merge_sort(int * a,int p,int h);
void merge(int * a,int p,int q,int h);
void quick_sort(int * a,int p,int r);
int partition(int *a,int p,int r);

void main()
{
  int *a,*b,n;
	printf("\n Enter the size of an array: ");
	scanf("%d",&n);
	a=(int *)calloc(n,sizeof(int));
	create(a,n);
	copy(a,b,n);
    sorting(a,b,n);

}

void create(int * a,int n)
{
    int c,i;
   
	printf("\n Enter 1 for creation of array in ascending order \n       2 for Descending order \n       3 for creation of a random array \n       4 for almost sorted array \n      5 to exit ");
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

	    case 5:
		exit(0);
		break;
	    default:

		printf("Wrong input");
       }
	   printf("\n");
		for(i=0;i<n;i++)
	{
	  printf("%d \t",a[i]);
	}
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
			a[i]=i+n;
		else
			a[i]=i+1;
	}	
}

void display(int * a,int n)
{
	int i;
	printf("\n");
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

void merge_sort(int * a,int p,int r)
{
    int q;
	if(p<r)
	{
		q=((p+r)/2);
		
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge(a,p,q,r);
	}
}

void merge(int * a,int p,int q,int h)
{
	int i,j,k;
	int n1=q-p+1;
	int n2=h-q;
	int l[n1],r[n2];
	
	for(i=0;i<n1;i++)
	{
		l[i]=a[p+i];
		
	}

    for(j=0;j<n2;j++)
	{
        r[j]=a[q+1+j];
        
	}

    i=0;
    j=0;
    k=p;
    while(i < n1 && j < n2)
    {
        if(l[i]>=r[j])
        {
            a[k] = r[j];
            j++;
        }
        else
        {
            a[k] = l[i];
            i++;
        }
        k++;
        
    }
	while(i!=n1)
    {
        a[k] = l[i];
        i++;
        k++;
    }
    while(j!=n2)
    {
        a[k] = r[j];
        k++;
        j++;
    }
}

void quick_sort(int * a,int p,int r)
{ 
    int q;
	if(p<r)
	{
		q=partition(a,p,r);
		//printf("q= %d  ",q);
		quick_sort(a,p,q-1);
		quick_sort(a,q+1,r);
		
	}
}

int partition(int *a,int p,int r)
{
  int x=a[r];
  int i=p-1;
  int j,t;
 
  for(j=p;j<r;j++)
  {
	  if(a[j]<=x)
	  {
		  i++;
		  t=a[i];
		  a[i]=a[j];
		  a[j]=t;
	  }
  }	
    t=a[i+1];
	a[i+1]=a[r];
	a[r]=t;
	
	return i+1;
}

void sorting(int * a,int * b,int n)
{
  int c;
 clock_t t1,t2;
 double total;

 do
   {
	printf("\n Enter 0 for exit \n       1 for Merge Sort \n       2 for Quick sort  ");
	scanf("%d",&c);

	switch(c)
	{	
	case 0:
	exit(0);
	break;
	
	case 1:
	copy(a,b,n);
	t1=clock();
	merge_sort(b,0,n-1);
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
	quick_sort(b,0,n-1);
	t2=clock();
	total=(double)(t1-t2)/CLOCKS_PER_SEC;
	
	printf("\n Array before sorting: ");
	display(a,n);
	
	printf("\n Array after sorting: ");
	display(b,n);
	
	printf("\n The time required is: %f",total);
	break;
	
	
	default:
	printf("\n Wrong input");
	
	}
	
   }while(c!=0);
}




