#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;

};
struct node *ptr=NULL,*temp=NULL,*head=NULL;

void insertbeg()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the Data\n");
	scanf("%d",&temp->data);
	temp->link=NULL;

	if(head==NULL)
	{
		head=temp;
	}
	else
	{

		temp->link=head;
		head=temp;
	}
}
void insertend()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the Data\n");
	scanf("%d",&temp->data);
	temp->link=NULL;

	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		ptr=head;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}

		ptr->link=temp;
	}
}

void insertlocation()
{
	int count=0,pos,i;

	ptr=head;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
	}
	printf("The Count is:%d\n",count);

	printf("Enter The Position\n");
	scanf("%d",&pos);
	if(pos==1)
		insertbeg();
	else if(pos>count+1)
		insertend();
	else if(pos>1&&pos<count)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter the Data\n");
		scanf("%d",&temp->data);
		temp->link=NULL;

			ptr=head;
			for(i=1;i<pos-1;i++)
			{
				ptr=ptr->link;
			}
			temp->link=ptr->link;
			ptr->link=temp;
		}
		else{
			printf("Invalid Data\n");
		}
	}

void display()
{
	if(head==NULL)

		printf("List is Empty \n");

	else
	{
		ptr=head;
		while(ptr!=NULL)
		{
			printf("%d--",ptr->data );
			ptr=ptr->link;

		}
	}
}
void deletebeg()
{
	if(head==NULL)
		printf("List Is Empty");
	else
	{
		ptr=head;
		printf("%d",head->data);
	head=ptr->link;
		printf("%d",head->data);
	free(ptr);
	printf("%d",head->data);
}
}
void deleteend()
{
	if(head==NULL)
		printf("List is empty\n");
	else
		ptr=head;
		while(ptr->link!=NULL)
		{
			temp=ptr;
			ptr=ptr->link;

		}
		temp->link=NULL;
		free(ptr);

}
void deletelocation()
{
	int count=0,pos,i;

	ptr=head;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->link;

	}
	printf("Count :%d",count);
	printf("Enter the position\n");
	scanf("%d",&pos);
	if(pos==1)
		deletebeg();
	else if(pos==count)
		deleteend();
	else if(pos>1&&pos<count)
	{
		ptr=head;
		for(i=1;i<pos;i++)
		{
			ptr=temp;
			ptr=ptr->link;
		}
		ptr->link=temp->link;
		free(ptr);

	}
}
void main()
{
	int ch;
  while(1)
  {
  	printf("\n1.InsertBeg\n2.InsertEnd\n3.InsertLocation\n4.Display\n5.DeleteBeg\n6.DeleteEnd\n7.DeleteLocation\n8.Exit\n");
  	scanf("%d",&ch);
  	switch(ch)
  	{
  		case 1:insertbeg();break;
  		case 2:insertend();break;
  		case 3:insertlocation();break;
  		case 4:display();
  		case 5:deletebeg();break;
  		case 6:deleteend();break;
  		case 7:deletelocation();break;
  		case 8:exit(0);

  	}
  }
}
