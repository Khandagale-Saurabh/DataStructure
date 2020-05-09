

#include<stdio.h>
#include<stdlib.h>

int length(int a[])
{
	int count=0,i=0;	
    while(a[i]!=-99)
    {
    count++;
    i++;
    }	
	return count;
}


void delete(int a[],int n)
{
int index,x,i;
printf("enter the index");
scanf("%d",&index);
if(index>=n)
{
printf("Index out of range \n");
}
else if(a[index]==-99)
{
	printf("Index out of bound ");
}
else
{
x=a[index];
printf("The element deleted is: %d \n",x);
n=length(a);
i=index;
while(a[i]!=-99)
{
	a[i]=a[i+1];
	i++;
}
}
}

void insert(int a[],int n)
{
int x,i;
printf("enter the elements in the array");
for(i=0;i<n;i++)
{
scanf("%d",&x);
if(a[i]==-99)
{
a[i+1]=a[i];
}
a[i]=x;
}
printf("Insertion done properly\n");
}

void view(int a[])
{
int i=0;
while(a[i]!=-99)
{
printf("%d \t",a[i]);
i++;
}
}

void sort(int a[])
{
int i,j;
printf("Array before sorting is:");
view(a);
printf("sorted array is  ");
i=0;
while(a[i]!=-99)
{
  j=i+1;
  while(a[j]!=-99)
  {
   if(a[i]>a[j])
   {
    int temp=0;
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
   }
    j++;
  }
  i++;
}
view(a);
}

void copy(int a[],int b[])
{
	int i=0;
	do
	{
	 b[i]=a[i];
	 printf("%d",b[i]);
	 i++;
	}while(a[i]!=-99);
	printf("The copied array is:\n");

view(b);
}

void search(int a[])
{
int i,s,n;
printf("Enter the element to search: \n");
scanf("%d",&s);
n=length(a);
for(i=0;i<n;i++)
{
if(a[i]==s)
{
printf("\nThe element is present at position %d",i);
break;
}
}
if(i==n)
	printf("Element is not present ");
}



void binary_search(int a[],int l,int h,int e)
{
int mid;
mid=((l+h)/2);

if(l>h)
{
printf("element not found");
}
else
{
if(a[mid]==e)
{
printf("key found at %d : ",mid);
}
else if(a[mid]<e)
{
binary_search(a,mid+1,h,e);
}
else if(a[mid]>e)
{
binary_search(a,l,mid-1,e);
}
}
}

void isEmpty(int a[])
{
if(a[0]==-99)
{
printf("Array is empty");
}
else
{
printf("Array is not empty");
} 
}

void isFull(int n)
{
if(n==10)
{
printf("Array is full");
}
else
{
printf("Array is not full");
}

}

void merge(int a[])
{
int i,j,b[10]={0},c[20]={0},m,p,x,k,l;
b[0]=-99;
printf("\nEnter the size of the second array.......max length(10): \t");
scanf("%d",&m);
printf("\nEnter the elements for the second array:\n");
for(i=0;i<m;i++)
{
scanf("%d",&x);
if(b[i]==-99)
{
b[i+1]=b[i];
}
b[i]=x;
}
view(b);
k=0;
while(a[k]!=-99)
{
	c[k]=a[k];
	k++;
}
j=0;
while(b[j]!=-99)
{
	c[k]=b[j];
	k++;
	j++;	
}
c[k]=-99;
printf("Array after merging is: \n");
view(c);
l=length(c);
printf("The length of array is: %d",l);
}

void main()
{
int a[10],c,n,z,element,i,b[10],m;
a[0]=-99;
printf("Enter the length of an array......(max lenght=10)   ");
scanf("%d",&n);
m=n;
if(n>10)
printf("length of an array cannot be more than 10  ");
else
{
 do
 {
 printf("\n Enter 0 to exit \n      1 for insertion \n      2 for deletion \n      3 to traverse an array \n      4 to merge\n      5 to sort \n      6 to copy \n      7 to search an element using linear search  \n      8 to search an element using binary search  \n      9 to find the length \n      10 to check whether the array is empty or not \n      11 to check whether the array is full or not  ");
scanf(" %d",&c);
 switch(c)
 {
 case 1:
 insert(a,m);
 break;

 case 2:
 delete(a,n);
 break;

 case 3:
 view(a);
 break;

 case 0:exit(0);
 break;

 case 4:
 merge(a);
 break;

 case 5:
 sort(a);
 break;

 case 6:
 copy(a,b);
 break;

 case 7:
 search(a);
 break; 
 
 case 8:
 printf("Enter the number to search : ");
 scanf("%d",&element);
 sort(a);
 
 binary_search(a,0,length(a),element); 
 break;
 
 case 9:
 n=length(a);
 printf("The length of array is :");
 printf(" %d",n);
 break;

 case 10:
 isEmpty(a);
 break;
 
 case 11:
 isFull(n);
 break;
 
 default:
 printf("Wrong input");
}
}while(z!=0);
}
}














