
#include<stdio.h>
#include<stdlib.h>

#define MAX 5
#define MAXQ 5
#define MAXCQ 5 

int init_stk(int stk[]);
int push(int stk[],int *top,int ele);
int pop(int stk[],int *top);
int is_empty_stk(int stk[],int*top);
void topval_stk(int stk[],int *top);
int display_stk(int stk[],int *top);
void init_queue(int Q[],int *front,int*rear);
int insert_queue(int Q[],int *front,int *rear,int ele);
int delete_queue(int Q[],int *front,int *rear);
void frontval_queue(int Q[],int *front);
void rearval_queue(int Q[],int *rear);
int display_queue(int Q[],int front,int rear);
void init_circular_queue(int CQ[],int *cfront,int *crear);
int insert_circular_queue(int CQ[],int *cfront,int *crear,int ele);
int delete_circular_queue(int CQ[],int *cfront,int *crear);
void frontval_circular_queue(int CQ[],int *cfront );
void rearval_circular_queue(int CQ[],int *crear);
int display_circular_queue(int CQ[],int cfront,int crear);

int main()
{
	int top,stk[MAX],ele,op,s,front,rear,Q[MAXQ],s1,s2,cfront,crear,CQ[MAXCQ];
	char ch='y',ch1='y',ch2='y',ch3='y';
	top=init_stk(stk);
	init_queue(Q,&front,&rear);
	init_circular_queue(CQ,&cfront,&crear);
	do
	{
		printf("\n\t\tLINEAR LISTS");
		printf("\n1. Stack\n2. Queue\n3. Circular Queue");
		scanf("%d",&op);
		switch(op)
		{
			case 1:	
				do
				{	
				printf("\n1. Push\n2. Pop\n3. Is Empty\n4. Top value\n5. Display");
				
				scanf("%d",&s);
				switch(s)
				{
					case 1:
						printf("\nEnter the element to push=>");
						scanf("%d",&ele);
						top=push(stk,&top,ele);
						break;
					case 2:
						top=pop(stk,&top);
						break;
					case 3:
						if(is_empty_stk(stk,&top))
						printf("\nStack is empty");
						else
						printf("\nStack is not empty");
						break;
					case 4:
						topval_stk(stk,&top);
						break;
					case 5:
						display_stk(stk,&top);
						break;
					default: 
						printf("\nSelect appropriate option");
						
				}
				printf("\nWant to continue?(y/n)=>");
				scanf("%s",&ch1);
				}while(ch1=='y' || ch1=='Y');
			break;
			
			case 2:
				do
				{
				printf("\n1. Insert\n2. Delete\n3. Front Value\n4. Rear Value\n5. Display");
				
				scanf("%d",&s1);
				switch(s1)
				{
					case 1:
						printf("\nEnter the value to insert=>");
						scanf("%d",&ele);
						insert_queue(Q,&front,&rear,ele);
						//printf("\nFront=%d\tRear=%d",front,rear);
						break;
					case 2:
						delete_queue(Q,&front,&rear);
						printf("\nFront=%d\tRear=%d",front,rear);
						break;
					case 3:
						frontval_queue(Q,&front);
						break;
					case 4:
						rearval_queue(Q,&rear);
						break;
					case 5:
						display_queue(Q,front,rear);
						break;
					default:
						printf("\nSelect appropriate option");
				}
				printf("\ndo you wise to continue?(y/n)=>");
				scanf("%s",&ch2);
				}while(ch2=='y' || ch2=='Y');
			break;
			case 3:
				do
				{
				printf("\n1. Insert\n2. Delete\n3. Front Value\n4. Rear Value\n5. Display");
		
				scanf("%d",&s2);
				switch(s2)
				{
					case 1:
						printf("\nEnter the element to insert=>");
						scanf("%d",&ele);
						insert_circular_queue(CQ,&cfront,&crear,ele);
					//	printf("\nFront=%d\tRear=%d",cfront,crear);
						break;
					case 2:
						delete_circular_queue(CQ,&cfront,&crear);
						printf("\nFront=%d\tRear=%d",cfront,crear);
						break;
					case 3:
						frontval_circular_queue(CQ,&cfront);
						break;
					case 4:
						rearval_circular_queue(CQ,&crear);
						break;
					case 5:
						display_circular_queue(CQ,cfront,crear);
						break;
					default:
						printf("\nSelect appropriate optino");
						
				}
				printf("\nDO you wise to continue?(y/n)=>");
				scanf("%s",&ch3);
				}while(ch3=='y' || ch3=='Y');
				break;
			default:
				printf("\nSelect appropriate option");		
		}
		printf("\nWant to continue?(y/n)=>");
		scanf("%s",&ch);
	}while(ch=='y' || ch=='Y' || ch1=='n' || ch2=='n' || ch3=='N');
return 0;	
}

//User Defined Functions Definations

int init_stk(int *stk)
{
	return -1;
}

int push(int *stk,int *top,int ele)
{
	if(*top==MAX-1)
	{
		printf("\nStack Overflow");
		return 0;
	}
	else
	{
		*top+=1;
		stk[*top]=ele;
		printf("%d is inserted",stk[*top]);
		return *top;
	}
}


int pop(int *stk,int *top)
{
	int ele;
	if(*top==-1)
	{
		printf("\nStack Underflow");
		return 0;
	}
	else
	{
		ele=stk[*top];
		*top-=1;
		printf("\n%d is deleted",ele);
		return *top;
	}
}


int is_empty_stk(int *stk,int *top)
{
	if(*top==-1)
		return 1;
	else
		return 0;
	
}


void topval_stk(int *stk,int *top)
{
	printf("\nTop value of the stack is %d",stk[*top]);
}


int display_stk(int *stk,int *top)
{	
	printf("\n----------------------------------------------------");
	if(*top==-1)
	{
		printf("\nStack is empty");
		return 0;
	}
	int i;
	for(i=0;i<=*top;i++)
		printf("\nstack[%d]=%d",i,stk[i]);
}


void init_queue(int *Q,int *front,int *rear)
{
	*front=*rear=-1;
}


int insert_queue(int *Q,int *front,int *rear,int ele)
{
	if(*rear>=MAXQ-1)
	{
		printf("\nQueue Overflow");
		return 0;
	}
	
	if(*front==-1)
		*front=0;
	*rear=*rear+1;
	Q[*rear]=ele;
	printf("\nElement inserted=%d",Q[*rear]);
	return 1;
}


int delete_queue(int *Q,int *front,int*rear)
{
	int ele;
	if(*front==-1 || *front>*rear)
	{
		printf("\nQueue Underflow");
		return 0;
	}
	
	ele=Q[*front];
	*front=*front+1;
	printf("\n%d is deleted",ele);
	return 1;
}


void frontval_queue(int *Q,int *front)
{
	printf("Front Value=%d",Q[*front]);
}


void rearval_queue(int *Q,int *rear)
{
	printf("Rear value=%d",Q[*rear]);
	
}


int display_queue(int *Q,int front,int rear)
{
	int i;
	if(front==-1)
	{
		printf("\nQueue is empty");
		return 0;
	}
	else
	{
		for (i = front; i <= rear; i++)
  		 printf("%d\n", Q[i]);
   	}
}


void init_circular_queue(int *CQ,int *cfront,int *crear)
{
	*cfront=*crear=-1;
}


int insert_circular_queue(int *CQ,int *cfront,int *crear,int ele)
{
	if(*cfront==0 && *crear==MAXCQ-1 || *cfront==*crear+1)
	{
		printf("\nQueue Overflow");
		return 0;
	}
	 if(*cfront==-1)
		*crear=*cfront=0;
	else if(*crear==MAX-1)
		*crear=0;
	else
		*crear=*crear+1;
	CQ[*crear]=ele;
    printf("INSERTED");
	//printf("\n%d is inserted",CQ[*crear]);
	return 1;
}


int delete_circular_queue(int CQ[],int *cfront,int *crear)
{
	int ele;
	if(*cfront==-1)
	{
	printf("\nQueue Underflow");
	return 0;
	}
	
	ele=CQ[*cfront];
	printf("\n%d is deleted",ele);
	
	if(*cfront==*crear)
	 	*cfront=*crear=-1;
	else if(*cfront==MAXCQ-1)
	 	*cfront=0;
	else
		 *cfront+=1;
	return 1;
}


void frontval_circular_queue(int *CQ,int *cfront)
{
	printf("Front Value=%d",CQ[*cfront]);
}


void rearval_circular_queue(int *CQ,int *crear)
{
	printf("Rear value=%d",CQ[*crear]);
}


int display_circular_queue(int *CQ,int cfront,int crear)
{	
	if(cfront == -1)
	{
		printf("Queue is empty\n");
		return 0;	
	}
	printf("Queue elements :\n");
	if( cfront <= crear )
	{	
		while(cfront <= crear)
		{
			printf("%d ",CQ[cfront]);
			cfront++;
		}
	}
	else
	{
		while(cfront <= MAXCQ-1)
		{	
			printf("%d ",CQ[cfront]);
			cfront++;
		}
		cfront = 0;
		while(cfront <= crear)
		{	printf("%d ",CQ[cfront]);
			cfront++;
		}
	}
	printf("\n");
}


