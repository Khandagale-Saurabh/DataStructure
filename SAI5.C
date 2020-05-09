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

 // struct node* del(struct node*,int num); 
struct node* create(struct node*,int );
 void post(struct node*);
 void pre(struct node*);
 void inorder(struct node*);
  //int height(struct node*,int);
 // node *find(struct node*,int);

int main()
{
    struct node * ptr,*s;
    int num,c,i,f;
    //printf("choice 1/2");
    //scanf("%d",c);
    
   { 
    
    for ( i=0;i<5;i++)
    {
    printf("plz enter numbers ");
    scanf("%d",&num);
     tree=create(tree,num);
     printf("POST ORDER");
     post(tree);
    printf("\n --------\n");
    printf("\n PREORDER");
     pre(tree);
     printf("\n inorder\n");
     inorder(tree);
    /* printf("\n height----------------------------\n");
       printf("%d",height(tree,num));
     
     */
    
    
    }
   }
    

      
}

struct node* create(struct node *s,int num)
{
    
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
         //  printf("%d",s->data);
    }
    if(num>s->data)
    {
           s->right=create(s->right,num);
           // printf("%d",s->data);
    }
      return (s);
}
void post(struct node *s)
{
    if(s!=NULL)
    {
         post(s->left);
         post(s->right);
        // post(s->data);
         printf(" %d ",s->data);
    }
}
void pre(struct node *s)
{
    if(s!=NULL)
    {
         printf(" %d ",s->data);
         post(s->left);
         post(s->right);
        // post(s->data);
        
    }
}

void inorder(struct node *s)
{
        post(s->left);
         printf(" %d ",s->data);
         post(s->right);

}


