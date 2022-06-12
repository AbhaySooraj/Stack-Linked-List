#include<stdio.h>
#include<stdlib.h>
#define n 5

int top=-1;

struct node
	{
		int data;
		struct node *next;
	};
	
struct node *head=NULL,*pos=NULL,*tail=NULL;

void push(int val)
{	if(top>=4)
	{
		printf("\nOverflow\n");
	}
	
	else
	{
		if(head==NULL)
		{
			head=(struct node *) malloc(sizeof(struct node));
			head->data=val;
			head->next=NULL;
			pos=head;
			tail=head;
			top=0;
		}
		else
		{
			struct node *temp;
			temp=(struct node *)malloc(sizeof(struct node ));
			temp->data=val;
			temp->next=head;
			head=temp;
			pos=head;
			top++;
		}
	}
}
	
void pop()
{	if(head==NULL)
	{
		printf("\nUnderflow");
		top=-1;
	}
	else
	{
		struct node *del=head;
		head=head->next;
		del->next=NULL;
		free(del);
		top--;
	}
}			

void display()
{
	printf("\nThe elements are :\n");
	pos=head;
	while(pos!=NULL)
	{
		printf("%d\n",pos->data);
		pos=pos->next;
	}
}	

void stacktop()
{
	printf("\n Stacktop at %d",top);
}

void main()
{
	
	
	
	int option,entry;
	while(1)
	{
		printf("\n\n\n STACK \n 1: PUSH \n 2: POP \n 3: DISPLAY \n 4: STACK TOP \n 5: EXIT \n\n ENTER CHOICE :");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
			{
				printf(" ENTER DATA :");
				scanf("%d",&entry);
				push(entry);
				break;
			}
			
			case 2:
			{
				pop();
				break;
			}
			
			case 3:
			{
				display();
				break;
			}
			
			case 4:
			{
				stacktop();
				break;
			}
			
			case 5:
			{
				printf("Exiting\n");
				exit(0);
			}
			
			default:
			{
				printf(" WRONG OPTION \n");
			}
		}
	}
}
