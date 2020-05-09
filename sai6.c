#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
struct node
{
   int data;
   struct node *left;
     struct node *right;
};
struct node *tree;
//typedef struct node tree;
struct node *insert(struct node*,int);



 void post(struct node*);
 void pre(struct node*);
 void inorder(struct node*);

int main()
{
    int num,choi;
   struct node *ptr;
     int another=1;
  
 
 
      while(1)
      {
 
  printf("enter choice");
   scanf("%d",&choi);
  switch(choi)
  {
    
      case 1:
             printf("num");
             scanf("%d",&num);
            ptr= insert(tree,num);
             break;


        case 2:
              exit(1);  

         case 3:
            printf("\n--------preorder----------\n");
               pre(tree);
         /* printf("\n--------postorder----------\n");
            post(tree);
        printf("\n--------INorder----------\n");
        inorder(tree);  */

              
                 
                    
  } 
       
  }







}

 struct node  *insert(struct node *tree,int val)
{
    struct node* newnode;
     
          
    if(tree==NULL)
    {
         newnode=(struct node*)malloc(sizeof(struct node));
         
          newnode->data=val;
          newnode->left=newnode->right=NULL;
    }

    if(val<tree->data)
     {
            insert(tree->left,val);

     }
     else
     {
         insert(tree->right,val);
     }
     
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