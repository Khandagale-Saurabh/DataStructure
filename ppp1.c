#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct list
{
    int info;
    struct list * next;
};

typedef struct list node;

node * insert(node* start,int num,int pos)
{
    node * newnode,*temp;
    int i;
       newnode=(node*)malloc(sizeof(node));
       newnode->info=num;
       newnode->next=NULL;

    if(start==NULL||pos==1)
    {
          newnode->next=start;
          start=newnode;
          printf("--first--%d   ",num);
    }
    else
    {
          i=2;
          temp=start;
          while(temp->next!=NULL&&i<pos)
           {
               i++;
               temp=temp->next;
           }   
           newnode->next=temp->next;
           temp=newnode;
    }
    printf("%d",num);
return start;
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