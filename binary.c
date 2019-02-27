#include<stdio.h>
void main()
{
  int a[20],start,end,key,n;
  printf("Enter the size of array\n");
  scanf("%d",&n);
  start=0;
  end=n;
  printf("Enter elements of array in sorted way\n");
  for(int i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("Enter the key to be searched\n");
  scanf("%d",&key);
  binarySearch(a,start,end,key);
}
void binarySearch(int a[],int start,int end,int key)
{
  int mid;
  mid=(start+end)/2;
  if(a[mid]==key)
   printf("key is at %d",mid+1);
  else if(a[mid]>key)
    binarySearch(a,start,mid-1,key);
  else if(a[mid]<key)
    binarySearch(a,mid+1,end,key);
  else
   printf("Key not found\n");
}
