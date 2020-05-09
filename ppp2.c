#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct list
{
    struct list *next;
    int info;
};
typedef struct list node;

node *insert(node *start,int num,int pos)
{
     node *newnode,*temp;
     int i=0;
     newnode=(node*)malloc(sizeof(node));
     newnode->info=num;
     newnode->next=NULL;
      if(start==NULL||pos==1)
      {
            newnode->next=start;
            start=newnode;
      }
      else
      {
          i=2;
          temp=start;
          while(temp->next!=NULL&&i<=pos)
          {
              i++;
              temp=temp->next;
          }
          newnode->next=temp->next;
          temp->next=newnode;

      }
     return start;
}


node delete(node **start,int num)
{
    node *temp,*prev;
    
    if(start==NULL)
    {
         printf("empty");
        // exit( 0 );
    }
    else
    {
    temp=*start;

     while(temp!=NULL && temp->info!=num)
     {
        prev=temp;
        temp=temp->next;
        if(temp==NULL)
        {
           printf("temp is emprty");
        }
        if (temp==*start)
        {
           *start=*start->next;

        }
        else
        {
        prev->next=temp->next;
        }
        free(temp);
     }
          
    }
}

int main()
{
    node* start;
    int num=0,pos=0;
    for(int i=0;i<5;i++){
    printf("enter number and pos");
      scanf("%d",&num);
      scanf("%d",&pos);
      
    start=insert(start,num,pos);}
}