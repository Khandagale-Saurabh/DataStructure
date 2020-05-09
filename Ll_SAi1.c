#include<stdio.h>

#include<stdlib.h>

struct list
{
 int info;
 struct list *next;
};
typedef struct list node;
node *create();
void display(node*);
int len(node*);
node *sort(node*);
node  *start,*newnode,*prev,*temp;

int main()
{

int choi;
node *start;
int r;
while(1){

printf("\n plz enter chooise \n 1:- create()   \n 2:-display() \n 3:- length() \n 4:-Sort() \n 5:- EXIT() ");
scanf("%d",&choi);
switch(choi)
{
node *start;
  case 1:
 
          
         start=create();
break;
case 2: 
          display(start);
   break;

case 3:
         r= len(start);
          printf("Length of Linked lis is:- %d",r);
         
          break;
case 4:
              
          start=sort(start);
          
          printf("main---------");
          display(start);
          break;
case 5:
 exit( 0 );
}
}
}
node *create()
 {


int num;
start=NULL;
int another = 1;
while(another == 1)
  {
printf("enter number");
scanf("%d",&num);
newnode =(node *) malloc(sizeof(node));

newnode->info=num;
newnode->next=NULL;
   if(start==NULL)
    {
  start=newnode;
prev=start;
    }                 
     
else
   {
     prev->next=newnode;     
     prev=newnode;
    }
   printf("Do you wise to contionue[1/0]");
     //fflush(stdin);
scanf("%d",&another);
  }

return start;

 }

int len(node *s)
{ 
int len1=0;
node *temp=s;
   while(temp!=NULL)
   { 
    
    // printf("Length is :- %d",len1);
         len1++; 
        temp=temp->next;
   }
   return(int) len1;
}


void display(node *s)
{
   node *temp=s;
   while(temp!=NULL)
   {
      printf("\nlist-: %d",temp->info);
      temp=temp->next;
   }
   
}


node *sort(node *start)
{
 
         node *temp;
          int i=temp->info;
          int j=i+1;
          int g;
          for (i=0;i->data<)
          {

          }
       
         
         return start;
}