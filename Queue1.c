#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void push(int stack[],int *top,int ele);
void pop(int stack[],int *top);
int isfull(int *top);
int isempty(int *top);



void traverse(int stack[],int *top);
void queueinsert(int queue[],int*front,int*rear,int ele);
void queuedelete(int queue[], int*front,int*rear);
void traversequeue(int queue[], int* front,int*rear);
void isfullq(int*front,int*rear);
void isemptyq(int*front,int*rear);




int queue[MAX];
int front=-1, rear=-1;
 void insertcq(void);
 void isemptycq();
 void isfullcq();
void traverse_Circular_queue();
int delete_element(void); 
void displaycq(void);


void main()
{
int stack[10],ele,g,top,k,e,l,queue[MAX],front,rear;
char c;
top=-1;
printf("\n Linear Data Structures\n");
printf("\nChoose:\na)Stack\nb)Queue\nc)Circular queue\n");
scanf("%c",&c);

switch(c)
{
case 'a':printf("\nStack\n");
   while(1)
   {
       printf("\n\nEnter the choice for operation:\n1)Traverse\n2)is full\n3)is empty\n4)push\n5)Pop\n6)Display Top\n0)ZERO to EXIT\n");
       scanf("%d",&e);

       switch(e)
       {
        case 1:printf("\nTraversing for you\n");
              g=isempty(&top);
              if(g==-1)
              {
                printf("\nThere is no element in stack\n");
                break;
              }
              else
                traverse(stack,&top);
              break;

        case 2:k=isfull(&top);
               if(k==1)
                 printf("\nThe stack is full\n");
               else
                 printf("\nArray is not full\n");
               break;

        case 3:l=isempty(&top);
		       if(l==(-1))
		         {
		         printf("\nThe stack is empty \n");
		         }
               else
                 printf("\nStack is not empty\n");
               break;

        case 4:printf("\nPush\n");
               k=isfull(&top);
               if(k==1)
		        {
		          printf("\nThe stack is full so you cannot perform operation\n");
                  break;
		        }
               else
    		     {
                  printf("\nEnter the Element to be pushed in the array stack\n");
                  scanf("%d",&ele);
                  push(stack,&top,ele);
		         }
                 traverse(stack,&top);
                  break;

        case 5:printf("POP");
               l=isempty(&top);
               if(l==(-1))
		       {
                  printf("\nThe stack is empty \n");
                  break;
               }
               else
                  pop(stack,&top);
                  traverse(stack,&top);
               break;

        case 6:printf("Top is %d",top);
               break;
        case 0:printf("\n\t\t\t\tThanks for your Time\n\n");
               exit(0);
        }
      }
      
      
      
 case 'b':printf("\nqueue\n");

             front=-1;
             rear=-1;
             
             while(1)
             {
              printf("\n\nEnter the choice for operation:\n1)Traverse\n2)Insert\n3)Delete\n4)is full\n5)Is Empty\n6)Display front and top  \n0)ZERO to Exit\n");
              scanf("%d",&e);

              switch(e)
                { 
                case 1:printf("Traverse\n");
                       traversequeue(queue,&front,&rear);
                       break;
                       
                case 2:printf("\n insert");
                       printf("\nEnter trhe element to insert in the queue\n");
                       scanf("%d",&ele);
                       queueinsert(queue,&front,&rear,ele);      
                       traversequeue(queue,&front,&rear);
                       break;
                  
                case 3:printf("\n Delete");
                       queuedelete(queue,&front,&rear);
                       traversequeue(queue,&front,&rear);
                       break;
                       
                case 4:isfullq(&front,&rear);           
                       break;
                       
                case 5:isemptyq(&front,&rear);
                       break;   
                       
                case 6:printf("The value of front is %d\nThe value of rear is %d",front,rear);
                       break;     
                       
                case 0:printf("\n\t\t\t\tThanks for your Time\n\n");
                       exit(0);            
              }
             }



       case 'cq':  
       {
              printf("\n\nEnter the choice for operation:\n1)Traverse\n2)Insert\n3)Delete\n4)is full\n5)Is Empty\n6)Display front and top  \n0)ZERO to Exit\n");     
               
                case 1:printf("Traverse\n");
                       traverse_Circular_queue(queue,&front,&rear);
                       break;
                       
                case 2:printf("\n insert");
                       printf("\nEnter trhe element to insert in the queue\n");
                       scanf("%d",&ele);
                       Circular_queueinsert(queue,&front,&rear,ele);      
                       traverse_Circular_queue(queue,&front,&rear);
                       break;
                  
                case 3:printf("\n Delete");
                       Circular_queuedelete(queue,&front,&rear);
                       traverse_Circular_queue(queue,&front,&rear);
                       break;
                       
                case 4:isfullCq(&front,&rear);           
                       break;
                       
                case 5:isemptyCq(&front,&rear);
                       break;   
                       
                case 6:printf("The value of front is %d\nThe value of rear is %d",front,rear);
                       break;  
       }            
  }


}



void push(int stack[],int*top,int ele)
{
 *top=*(top)+1;
 stack[*top]=ele;
 printf("\nTop is %d\n",(*top));
 printf("\nValue in stack at Top is %d\n",stack[*top]);
}

void pop(int stack[],int*top)
{
printf("\nDeleting the Element %d which is at the top\n",stack[*top]);
*top=(*top)-1;
}

int isfull(int *top)
{
if((*top)==(MAX-1))
  return(1);
else
  return(0);
}

int isempty(int*top)
{
if((*top)==-1)
  return(-1);
else
  return(0);
}


void traverse(int stack[],int*top)
{
int i;
  for(i=0;i<=(*top);i++)
   printf("%d\t",stack[i]);
}
 
 
void queueinsert(int queue[],int*front,int*rear,int ele)
{
if(*rear==(MAX-1))
  printf("\nQueue is full:OVERFLOW\n");
else if((*rear==-1)&&(*front==-1))
 {
  printf("\nQueue is empty");
  *rear=0;
  *front=0;
 }     
else
    *rear=*rear+1;

queue[*rear]=ele;
}  


void queuedelete(int queue[], int*front,int*rear)
{
 if((*front==-1)&&(*front>*rear))
  {
  printf("\nQueue is empty\n");
  }
 else
  {
  printf("\nDeleting  %d from front\n",queue[*front]);
  *front=*front+1; 
  }
} 


void traversequeue(int queue[], int* front,int*rear)
{
int i;
if((*front==-1)&&(*front>*rear))
  printf("\nThe queue is empty\n");
else  
 {
  for(i=*front;i<=*rear;i++)
  {
   printf("%d",queue[i]);
  }
 } 
}


void isfullq(int*front,int*rear)
{
if((*rear)=(MAX-1))  
  printf("\nQueue is full\n");
else
  printf("\nQueue is not full");
}


void isemptyq(int*front,int*rear)
{
if((*front==-1)&&(*front>*rear))
  printf("\nThe queue is empty\n");
else 
  printf("\nThe queue is not empty\n");
}   


void isemptycq()
{
    if(front ==-1 && rear ==-1)
{
printf("\n UNDERFLOW"); 

}
else
   {
    printf("CIRCULAR QUEUE is NOT EMPTY");
   }


}


void isfullcq()
{
    if(front==0 && rear==MAX-1)
    {
printf("\n OVERFLOW"); 
    }
     else
     {
         printf("Circular queue is not full");
     }
     
}

void insertcq()
{
int num;
printf("\n Enter the number to be inserted in the queue : "); scanf("%d", &num);
if(front==-1 && rear==-1)
 {
front=rear=0;
queue[rear]=num;
 }
else if(rear==MAX-1 && front!=0)
 {
rear=0;
queue[rear]=num;
 }
else
   {
rear++; 
queue[rear]=num; 
   }
}

  
  
  int delete_elementcq()
{
int val;

val = queue[front]; if(front==rear)
front=rear=-1;
 
else
  {
 
if(front==MAX-1)
front=0;
 
else
 
   {
front++;
   }
return val;
  }
}



void displaycq()
{
int i; 
printf("\n");
if (front ==-1 && rear==-1)
printf ("\n QUEUE IS EMPTY");
else
{
if(front<rear)
{
for(i=front;i<=rear;i++)
 printf("\t %d", queue[i]);
}
else
{
for(i=front;i<MAX;i++) 
printf("\t %d", queue[i]);
for(i=0;i<=rear;i++)
printf("\t %d", queue[i]);
}
}
}




void traverse_Circular_queue()
{
    
printf("\n------------------------------------------------------------TRAVERSE----------------------------------------");
int i; 
printf("\n");
if (front ==-1 && rear==-1)
printf ("\n QUEUE IS EMPTY");
else
{
        if(front<rear)
      {
        for(i=front;i<=rear;i++)
          printf("\t %d", queue[i]);
      }
else
{
for(i=front;i<MAX;i++)  {
              printf("\t %d", queue[i]);}
for(i=0;i<=rear;i++){
                  printf("\t %d", queue[i]);}
}
printf("\n------------------------------------------------------------TRAVERSE----------------------------------------");
}
}