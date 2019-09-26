//count ko pop ke baad decrement karna na bhule.
#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();
int choice,no,count=0;
struct stack
{
	int data;
	struct stack* link;
} *top,*s;

int main()
{
	printf("this is for stack\n");
	printf("Press.\n");
	printf("\t1.for push.\n\t2.pop\n\t3.display\n\t4.top element\n\t5.no of element\n\t6.exit\n");
	scanf("%d",&choice);
	while(choice!=6)
	{
		switch(choice)
		{
			case 1: push();
					display();
			break;
			case 2: pop();
					display();
			break;
			case 3:	display();
			break;
			case 4:
			{
				if(count==0)
				{
					printf("stack is empty\n");
				}
				else
					printf("top element is %d\n",top->data);
			}
			break;
			case 5: printf("%d\n",count);
			break;
			case 6:  exit(0);
			default :printf("you entered somathing wrong\n");
		}
		scanf("%d",&choice);
	}
	return 0;
}
void push()
{
	printf("enter the element to push in stack.\n");
	scanf("%d",&no);
	struct stack* temp=(struct stack* )malloc(sizeof(struct stack));
	if(temp==NULL)
	{
		printf("temp is not form here\n");
	}
	else
	{
		count++;
		if(top==NULL)
		{
			temp->data=no;
			temp->link=NULL;
			top=temp;
			s=temp;
		}
		else
		{
			temp->data=no;
			top->link=temp;
			top=temp;
		}
	}
}

void pop()
{
	if(count==0)
	{
		printf("stack is empty.you can't pop an element");
	}
	else if(count==1)
	{
		printf("%d is poped out\n",top->data);
		count=count-1;
		top=NULL;

	}
	else
	{
		struct stack* temp=(struct stack* )malloc(sizeof(struct stack));
		temp=top;
		struct stack* p=(struct stack* )malloc(sizeof(struct stack));
		p=s;
		printf("%d is poped out\n",top->data);
		for(int i=1;i<count-1;i++)
		{
			p=p->link;
		}
		top=p;
		top->link=NULL; //this is important.otherwise we get 0 at that empty place
		count=count-1;
		free(temp);
		//temp is used only to free your unusabe memory.	
	}
}
void display()
{
	struct stack* temp=(struct stack* )malloc(sizeof(struct stack));
	if(top==NULL)
	{
		printf("stack is empty\n");
	}
	else
	{
		temp=s;
		printf("Now element in stack is\n");
		while(temp!=NULL)
		{
			printf("%d  ",temp->data);
			temp=temp->link;
		}
	}
	printf("\n");
}