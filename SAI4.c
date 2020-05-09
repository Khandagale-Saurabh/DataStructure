#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
struct  node
{
    struct node *left;
    struct node *right;
    int data;
};
struct node *tree;

struct node* create(struct node*,int num);

struct node* create(struct node *s,int num)
{
    num=19;
    struct node *newnode;
    if(s==NULL)
    {
           newnode=(struct node*)malloc(sizeof(struct node));
           newnode->data=num;
           newnode->left=newnode->right=NULL;
           return newnode;
    }
    if(num<s->data)
    {
           s->left=create(s->left,num);
    }
    if(num>s->data)
    {
           s->right=create(s->right,num);
    }
      return (s);
}