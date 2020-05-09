#include<stdio.h>
#include<conio.h>
#include<malloc.h>

typedef struct tree
{
    struct tree *left,*right;
    int info;
}node;

node * insert(node *s,int val)
{

    node * newnode;
    if(s==NULL)
    {
       newnode=(node*)malloc(sizeof(node));
       newnode->info=val;
       newnode->left=newnode->right=NULL;
       return newnode;
    }
    if(val<s->info)
    {
      s->left=insert(s->left,val);

    }
    else
    {
        s->right=insert(s->right,val);
    }
    return s;

}

int main()
{
    
}