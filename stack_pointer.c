#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void push(int *);
void pop(int *);
void show(int *);
int top=-1,n,choice=0,*stack;
int main()
{
	printf("This is the implimentation of stack via array\n");
	printf("enter the size of array\n");
	scanf("%d",&n);
	stack=(int *)malloc(n*sizeof(int));
	printf("\tpress:\n");
	printf("\t1.push\n\t2.pop\n\t3.to display\n\t4.exit\n");
	scanf("%d",&choice);
	while(choice!=4)
	{
		
		switch(choice)
		{
			case 1:
			{
				push(stack);
				// printf("\n");
				show(stack);
				break;
			}
			case 2:
			{
				pop(stack);
				// printf("\n");
				show(stack);
				break;
			}
			case 3:
			{
				show(stack);
			}
			case 4:
			{
				break ;
			}
			default: 
			{
				printf("enter a valid choice.\nYou entered some thing wrong\n");
			}
		}
		scanf("%d",&choice);
	}
	free(stack);
	return 0;
}

void push(int* stack)
{
	int value;
	if(top==n-1)
	{
		printf("stack is full.\tcase of overflow\n");
	}
	else {
		printf("enter the element that you wnat to store: ");
		scanf("%d",&value);
		top=top+1;
		stack[top]=value;
	}
}

void pop(int* stack)
{
	if(top==-1)
	{
		printf("empty stack\n");
	}
	else
	{
		printf("%d is successfully poped out.\n",stack[top]);
		top=top-1;
	}
}
void show(int* stack)
{
	if(top==-1)
	{
		printf("stack is empty now.\n");
	}
	else
	{
		printf("your entered element till now is given below:\n");
		for(int i=0;i<top+1;i++)
		{
			printf("%d ",stack[i]);
		}
		printf("\n");
	}
	
}