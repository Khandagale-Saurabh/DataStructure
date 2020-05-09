#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * left;
    struct node * right;
    
};
typedef struct node node;
node * create(node * s,int num)
{
    node *newnode ;
    if(s==NULL)
    {
      newnode=(node*)malloc(sizeof(node));
      newnode->data=num;
      newnode->left=NULL;
      newnode->right=NULL;
       return newnode;
    }
    
    
        if(num< s->data)
        {
           s->left=create(s->left,num);
        }
        else
        {
            s->right=create(s->right,num);
        }
        return(s);
    
    
}

void inorder(node *t)
{
  if(t!=NULL)
  {
    inorder(t->left);
    printf("  %d",t->data);
    inorder(t->right);
  }
}
int main()
{
    node *s=NULL;
    int num;
    for (int i=0;i<=5;i++){
    printf("enter num");
    scanf("%d",&num);
  
     s=create(s,num);
    }
     inorder(s);

}