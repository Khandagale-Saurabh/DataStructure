#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct tnode
{
    struct  tnode *left;
    struct tnode *right;
    int data;

};
typedef struct tnode node;
node *start,*newnode;

void main()
{
    start=NULL;
    int num;
    printf("enter number");
    scanf("%d",&num);
   *start= *create(start,num);
}

node * create(node *start,int num)
{
    
    newnode=(node*) malloc(sizeof(struct tnode));
    newnode->data=num;
    newnode->left=newnode->right=NULL;
    if(start==NULL)
     {
         printf("sorry");
         return newnode;
     }
     else
     {
         if(num>start->data)
         {
                start=create(start->left,num);
                printf("%d",num);
         }
         else
         {
             start=create(start->right,num);
               printf("%d",num);
         }
         
     }
     return(start);
}

void *preorder(node *start)
{
    preorder(start->left);
    preorder(start->right);
    preorder(start->data);

}
void *inorder(node *start)
{
    
    inorder(start->left);
     inorder(start->data);
    inorder(start->right);
}
void *postorder(node *start)
{
    
     postorder(start->data);
    postorder(start->left);
    postorder(start->right);
}


