#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  struct node * prev;
  char s;
  struct node * next;
}node;
node * head=NULL,* tail=NULL,*ptr1=NULL,*ptr2=NULL;
node * create(char s)
{
  node * temp = (node *)malloc(sizeof(node));
  temp->prev = NULL;
  temp->next = NULL;
  temp->s = s;
  return temp;
}
void insert(char c)
{{
  if(head==NULL)
  {
    head=create(c);
    tail=head;
  }
  else
  {
    node * newnode = create(c);
    newnode ->prev = tail;
    tail->next = newnode;
    tail = newnode;
  }
}
int checkPalin()
{
  ptr1 = head;
  ptr2 = tail;
  int flag = 0;
  while(ptr1!=ptr2)
  {
    if(ptr1->s!=ptr2->s)
    {
      flag = 1;
      return flag;
      break;
    }
    else
    {
      ptr1=ptr1->next;
      ptr2 = ptr2->prev;
    }
  }
  return flag;
}
void main()
{
  char s[20];
  int i;
  printf("Enter the string\n");
  scanf("%s",s);
  for(i=0;s[i]!=NULL;i++)
  {
    insert(s[i]);
  }
  int k = checkPalin();
  if(k==1)
   printf("not pallindrome\n");
  else
    printf("Pallindrome\n");
}
