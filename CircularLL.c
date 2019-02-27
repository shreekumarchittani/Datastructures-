#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node * next;
}node;
node * head = NULL,* tail = NULL;
node * temp = NULL,* ptr = NULL,*cur = NULL,*sptr = NULL;
node * create(int data)
{
  temp = (node *)malloc(sizeof(int));
  temp->data = data;
  temp->next = NULL;
  return temp;
}
node * search(int data)
{
  ptr = head;
  while(ptr!=NULL)
  {
    if(ptr->data==data)
     {
       return ptr;
       break;
     }
    else
      {
        ptr = ptr->next;
      }
  }
  if(ptr==NULL)
   return NULL;
}
node * insertBegin(int data)
{
  if(head==NULL)
  {
    head = create(data);
    tail = head;
    return head;
  }
  else
  {
    node * newnode = create(data);
    newnode->next = head;
    head = newnode;
    tail->next = head;
    return head;
  }
}
node * insertEnd(int data)
{
  node * newnode = create(data);
  newnode->next = head;
  tail->next = newnode;
  tail = newnode;
  return head;
}
node *insertAfter(int data,node * sptr)
{
  if(sptr==tail)
  {
    head = insertEnd(data);
    return head;
  }
  else
  {
   node * newnode = create(data);
   newnode->next = sptr->next;
   sptr->next = newnode;
   return head;
 }
}
node * deleteBegin()
{
  ptr = head;
  head = head->next;
  tail->next = head;
  free(ptr);
  return head;
}
node * deleteEnd()
{
  ptr = head;
  while(ptr->next!=NULL)
  {
    ptr = ptr->next;
  }
  cur = tail;
  tail = ptr;
  free(cur);
  return head;
}
node * delete(node * sptr)
{
  while(ptr->next!=sptr)
  {
    ptr = ptr->next;
  }
  ptr->next = sptr->next;
  free(sptr);
  return head;
}
void display(node * head)
{
  ptr = head;
  while(ptr!=NULL)
  {
    printf("%d\n",ptr->data);
  }
}
void main()
{
  int ch,d;
    printf("1.insert at begin\n");
    printf("2.insert at end\n");
    printf("3.insert after given node\n");
    printf("4.delete begin\n");
    printf("5.delete end");
    printf("6.display\n");
    printf("7.exit\n");
    printf("Enter choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
       printf("Enter data\n");
       scanf("%d",&d);
       head = insertBegin(d);
       break;
      case 2:
       printf("Enter data\n");
       scanf("%d",&d);
       head = insertEnd(d);
       break;
    }

}
