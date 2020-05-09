#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct list
{
    struct list *next;
    int info;
}node;

node *rear=NULL,*front=NULL,*temp;
node *newnode;

node * create()
{
    
    newnode=(node *)malloc(sizeof( node));
    
    printf("data?");
    scanf("%d",&newnode->info);
    newnode->next=NULL;
    if(rear==NULL)
    {
         front=rear=newnode;
    }
    else
    {
       rear->next=newnode;
       rear=newnode;
    }
    rear->next=front;
}

void delete()
{
 temp=front;
   if(front==NULL)
   {
             printf("emprty");
   }   
   if(front==rear)
   {
       printf("only ele");
       front=rear=NULL;
   }
   else
   {
       front=front->next;
       rear->next=front;
   }
   
   temp->next=NULL;
   free(temp);
}


int main()
{
    int i=0;
    for(;i<=5;i++)
  create();
  delete();
}