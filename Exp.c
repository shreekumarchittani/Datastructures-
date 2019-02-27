#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct node
{
  char data;
  struct node * right;
  struct node * left;
}node;
node * st[20],*temp,*root=NULL;
char postfix[20];
node * create_node()
{
  node * newnode = (node *)malloc(sizeof(node));
  return newnode;
}
node* create_tree(char postfix[])
{
  int i,k;
  char symbol;
  for(i=0;postfix[i]!='\0';i++)
  {
    temp = create_node(postfix[i]);
    temp->data = postfix[i];
    temp->right=temp->left=NULL;
    if(isalnum(postfix[i]))
    {
      st[k++]=postfix[i];
      printf("%c",st[k]);
    }
    else
    {
     printf("E1");
      temp->right=st[--k];
      temp->left=st[--k];
      st[k++]=temp;
    }
  }
  return(st[k--]);
}
float calc(node * root)
{
  switch(root->data)
  {
    case '+' : return(calc(root->left)+calc(root->right));
    case '-' : return(calc(root->left)-calc(root->right));
    case '*' : return(calc(root->left)*calc(root->right));
    case '/' : return(calc(root->left)/calc(root->right));
    default:
     return(root->data-48);
  }
}
void display(node * root,int level)
{
  int i;
  if(root==NULL)
   return;
  display(root->right,level+1);
  for(i=0;i<level;i++)
    printf(" ");
  printf("%c\n",root->data);
  display(root->left,level+1);
}
void main()
{
    int res;
  printf("Enter postfix expression");
  scanf("%s",postfix);
  root = create_tree(postfix);
  display(root,1);
  res = calc(root);
  printf("Result is %d",res);
}
