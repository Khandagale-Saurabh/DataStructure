#include<stdio.h>
#include<conio.h>
#include<malloc.h>

typedef struct tree
{
    struct tree *left,*right;
    int info;
}node;

void inorder(node * start)
{
    while(start!=NULL)
    {
          inorder(start->left);
          printf("%d",start->info);
          inorder(start->left);
    }
}

node * create(node * start,int num)
{
    node *newnode;
    printf("11");
          if(start==NULL)
          {
            start=(node*)malloc(sizeof(node));
                  start->info=num;
             start->left=start->right=NULL;
           printf("1");
          }
          else
          {

              if(num<start->info)
              {
                  start->left=create(start->left,num);
              }
              else
              {
                  start->right=create(start->right,num);
              }
              
          }
           
           
          return(start);
          
}


void postorderTraversal( node *tree)
{
if(tree != NULL)
{
postorderTraversal(tree->left); postorderTraversal(tree->right); printf("%d\t", tree->info);
}
}
int main()
{
    node * start;
    int num=0;
 //   for (int i=0;i<=5;i++)
 {   printf("data?");
    scanf("%d",&num);
   }  start=create(start,num);
   
 
postorderTraversal(start);
}