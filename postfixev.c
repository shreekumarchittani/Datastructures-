#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define SIZE 40
int top=-1,stack[SIZE];
char postfix[SIZE];
void push(int ele)
{
  if(top=SIZE-1)
  {
    printf("Stack overflow\n");
  }
  else
  {
    stack[++top]=ele;
  }
}
int pop()
{
  if(top==-1)
  {
    printf("Stack underflow\n");
    return 0;
  }
  else
  {
    return(stack[top--]);
  }
}
int isValid()
{
  int digits=0,operators=0,valid=1;
  if(isdigit(postfix[0])&&postfix[1]=='\0')
   return valid;
  if(!(isdigit(postfix[0]))&&(isdigit(postfix[1])))
   return --valid;
  for(int i=0;postfix[i]!='\0';i++)
  {
    if(isdigit(postfix[i]))
     digits++;
    else if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='/')
      operators++;
    else
      return --valid;
  }
  if(digits-operators!=1)
   return --valid;
  else
   return valid;
}
void evaluate()
{
  int i,x1,x2,zerodiv=0;
  while(1)
  {
    printf("Enter a valid postfix expression\n");
    scanf("%s",postfix);
    if(isValid())
    {
      break;
    }
    else
    {
      printf("invalid postfix expression\n");
    }
  }
  for(i=0;postfix[i]!='\0';i++)
  {
    if(isdigit(postfix[i]))
    {
       push(postfix[i]-'0');
    }
    else if(postfix[i]=='+')
    {
      x2=pop();
      x1=pop();
      push(x1+x2);
    }
    else if(postfix[i]=='-')
    {
      x2=pop();
      x1=pop();
      push(x1-x2);
    }
    else if(postfix[i]=='*')
    {
      x2=pop();
      x1=pop();
      push(x1*x2);
    }
    else if(postfix[i]=='/')
    {
      x2=pop();
      x1=pop();
      if((x1==0)&&(x2==0))
      {
        zerodiv=1;
        break;
      }
      if(x2==0)
      {
        zerodiv=2;
        break;
      }
      else
      {
        push(x1/x2);
      }
    }}
    if(zerodiv==1)
    {
      printf("The result is : NaN\n");
    }
    else if(zerodiv==2)
    {
      printf("The result is : %c",236);
    }
    else
    {
      printf("The result is %d \n",pop());
    }

}
void main()
{
  evaluate();
}
