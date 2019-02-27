#include<stdio.h>
void main()
{
  int m,n,g;
  printf("Enter two numbers\n");
  scanf("%d%d",&m,&n);
  g=GCD(m,n);
  printf("GCD is %d",g);
}
int GCD(int m,int n)
{
  if(n==0)
   return m;
  else
    GCD(n,m%n);
}
