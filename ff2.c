#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct node 
{
    struct node *left;
    struct node *right;
    int data;
};
typedef struct node node;
node * insert(node * s,int n)
{
    node *newnode;
    if(s==NULL)
    {
        newnode=(node*)malloc(sizeof(node));
        newnode->data=n;
        newnode->left=NULL;
        newnode->right=NULL;
        return newnode;
    }

    if(n<s->data)
    {  
        s->left=insert(s->left,n);

    }
    else
    {
        s->right=insert(s->right,n);
    }
    return (s);
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
node *large(node* s)
{
    if(s==NULL||s->right==NULL)
    {
         return s;
    }
    else
    {
        return large(s->right);
    }
    
}
/*
node * delete(node * s,int n)
{
     if(s==NULL)
      {
          return NULL;
      }
      
          if( n< s->data)
          {
             s->left=delete(s->left,n);
          }
          else if(n>s->data)
          
          {
              s->right=delete(s->right,n);
          }
          else
          {
              if(s->left==NULL)
              {
                  node *temp=s->right;
                  free(s);
                  return temp;
              }
              else if(s->right==NULL)
              {
                  node *temp=s->left;
                  free(s);
                  return temp;
              }
              
          
          
          node *temp=large(s->left);
          s->data=temp->data;
          s->left=delete(s->right,temp->data);
      }
      return s;
      
}

*/

struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
}
 node* deleteNode( node* s, int n) 
{ 
    // base case 
    if (s == NULL) return s; 
  
    // If the n to be deleted is smaller than the s's n, 
    // then it lies in left subtree 
    if (n < s->data) 
        s->left = deleteNode(s->left, n); 
  
    // If the n to be deleted is greater than the s's n, 
    // then it lies in right subtree 
    else if (n > s->data) 
        s->right = deleteNode(s->right, n); 
  
    // if n is same as s's n, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (s->left == NULL) 
        { 
             node *temp = s->right; 
            free(s); 
            return temp; 
        } 
        else if (s->right == NULL) 
        { 
             node *temp = s->left; 
            free(s); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
         node* temp = minValueNode(s->right); 
  
        // Copy the inorder successor's content to this node 
        s->data = temp->data; 
  
        // Delete the inorder successor 
        s->right = deleteNode(s->right, temp->data); 
    } 
    return s; 
} 
  

int main()
{
    node *s=NULL;
    int num;
    for (int i=0;i<=5;i++){
    printf("enter num");
    scanf("%d",&num);
  
     s=insert(s,num);
    }
     inorder(s);
     s=large(s);
     printf("\n large %d",s->data);

    printf("\n enter num to delete");
    scanf("%d",&num);
    s=deleteNode(s,num);
     inorder(s);
  

}
