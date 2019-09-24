#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void push();
void pop();
void display();
int array[1000];
int top=-1,no;
void main()
{
	int choice;
	printf("this is for stack\n");
	printf("Press.\n");
	printf("\t1.for push.\n\t2.pop\n\t3.display\n\t4.exit\n");
	scanf("%d",&choice);
	while(choice!=4)
	{
		switch(choice)
		{
			case 1:push();
			printf("Now element in stack is\n");
			display();
			break;
			case 2:pop();
			printf("Now element in stack is\n");
			display();
			break;
			case 3:display();
			break;
			case 4: exit(0);
			default :printf("you entered somathing wrong\n");
		}
		scanf("%d",&choice);
	}
}

void push()
{
	printf("enter the element to push in stack.\n");
	scanf("%d",&no);
	top+=1;
	array[top]=no;
	printf("Your element is successfully pushed\n");
}
void pop()
{
	printf("%d is successfully poped out.\n",array[top]);
	top=top-1;
}
void display()
{
	for(int i=0;i<=top;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}