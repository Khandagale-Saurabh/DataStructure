#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct list 
{
 struct list *next;
 int info;
}typedef   node;

node * beg1(node * start)
{
    node *newnode,*ptr;
    int num;

    newnode =(node*)malloc (sizeof(node));
    scanf("%d",&num);
    newnode->info=num;
      
    ptr=start;

    while(ptr->next!=start)
    {
         ptr=ptr->next;
    }
    ptr->next=newnode->next;
    newnode->next=start->next;
     start=newnode;
}
void display( node* start)
{
    node *temp;
      temp=start;
    while(temp!=NULL)
    {
          printf("%d",temp->info);
          temp=temp->next;
    }

}
int main()
{
    node * start;
    int num=0;
    printf("NUM?");
    scanf("%d",&num);
    start=beg1(start);

}