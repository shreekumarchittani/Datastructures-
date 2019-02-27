#include<stdio.h>
#include<stdlib.h>
typedef struct newnode
{
  int d;
  struct node * next;
}node;
node * head=NULL,*temp=NULL,*cur=NULL,*newnode=NULL,*ptr=NULL;
node * create(int d)
{
  newnode = (node *)malloc(sizeof(node));
  newnode->d=d;
  newnode->next=NULL;
  return(newnode);
}
void insert(int d)
{
  temp = create(d);
  if(head==NULL)
  {
    head = temp;
  }
  else if(d<=head->d)
  {
    temp->next = head;
    head = temp;
  }
  else
  {
    cur = NULL;
    ptr = head;
    while(ptr!=NULL&&ptr->d<d)
    {
      cur = ptr;
      ptr = ptr->next;
    }
    cur->next = temp;
    temp->next = ptr;
  }
}
void main()
{
  int n,i;
  printf("Enter the numbers to LL\n");
  for(int i=0;i<6;i++)
  {
    scanf("%d",&n);
    insert(n);
  }
  ptr = head;
  printf("Sorted list is\n");
  while(ptr!=NULL)
  {
    printf("%d\t",ptr->d);
    ptr = ptr->next;
  }
}
