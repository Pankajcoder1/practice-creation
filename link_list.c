/*according to need you can change option or can add.*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
void push(int push_value);
void no_of_node();
void display();
void reverse();
void pop(int pop_value);
void swap_any_two();
void consecutive();
int value,push_value,pop_value,push_position,count=0,poo_position;

struct link_list
{
	int data;
	struct link_list* link;
}*head=NULL,*tail=NULL;
/*here s is used to put the address of next in prevoius one.*/

int main()
{
	printf("this is for different operation on linkedlist.\n");
	printf("\t1.for push\n\t2.for pop\n\t3.no of node\n\t4.display all node.\n");
	printf("\t5.to reverse\n\t6.swap any two node\n\t7.exit\n");
	while(value!=7)
	{
		scanf("%d",&value);
		switch(value)
		{
			case 1:
			{
				printf("enter the value that you want to enter.\n");
				scanf("%d",&push_value);
				push(push_value);
			} break;
			case 2:
			{
				if(count==0)
				{
					printf("list is empty.\n");
				}
				else
				{
					printf("enter value that you want to delete.\n");
					scanf("%d",&pop_value);
					pop(pop_value);
				}
			} break ;
			case 3: no_of_node();break;
			case 4: display(); break ;
			case 5: reverse(); break ;
			case 6: swap_any_two(); break;
			case 7: printf("exit successfully\n"); break ;
			default : printf("wrong input.\n");
		}
	}
	return 0;
}

void push(int push_value)
{
	struct link_list* temp=(struct link_list*)malloc(sizeof(struct link_list));
	if(head==NULL)
	{
		temp->data=push_value;
		temp->link=NULL;
		head=temp;
		tail=temp;
		count++;
		printf("pushing is done.\n");
	}
	else
	{
		printf("you may push between 1st to %dth position.\n",count+1);
		printf("after which node you want to push element.\npress -1 for last\n");
		scanf("%d",&push_position);
		push_position-=1;
		if(push_position<=count && push_position>=-1)
		{
			if(push_position==-1 || push_position==count)
			{
				temp->data=push_value;
				temp->link=NULL;
				tail->link=temp;
				tail=temp;
				count++;
			}
			else if(push_position==0)
			{
				temp->data=push_value;
				temp->link=head;
				head=temp;
				count++;
			}
			else
			{
				struct link_list* a=(struct link_list*)malloc(sizeof(struct link_list));
				struct link_list* b=(struct link_list*)malloc(sizeof(struct link_list));
				a=head;
				for(int i=0;i<push_position-1;i++)
				{
					a=a->link;
				}
				b=a->link;
				//a and b is used to reach that two conseccutive node.
				temp->data=push_value;
				a->link=temp;
				temp->link=b;
				count++;
			}
			printf("pushing is done.\n");
		}
		else
			printf("you enter invalid position\n");
	}
}

void no_of_node()
{
	printf("total no of node is: %d\n",count);
}

void display()
{
	struct link_list* temp=(struct link_list*)malloc(sizeof(struct link_list));
	temp=head;
	if(temp==NULL)
		printf("list is empty\n");
	else
	{
		printf("element in list is: ");
		while(temp!=NULL)
		{
			printf("%d  ",temp->data);
			temp=temp->link;
		}
	}
	printf("\n");
}

void pop(int pop_value)
{
	struct link_list* temp=(struct link_list*)malloc(sizeof(struct link_list));
	struct link_list* prev_of_temp=(struct link_list*)malloc(sizeof(struct link_list));
	temp=head;
	int c=0;
	if(temp->data==pop_value)
	{
		head=temp->link;
		count--;
		printf("poped successfully\n");
		free(temp);
		c++;
	}
	else
	{
		while(temp!=NULL && temp->data!=pop_value)
		{
			prev_of_temp=temp;
			temp=temp->link;
		}
		if(temp==NULL || temp->data!=pop_value)
		{
			printf("you entered wrong element to pop\n");
		}
		else
		{
			prev_of_temp->link=temp->link;
			count--;
			c++;
			free(temp);
			printf("poped successfully\n");
		}
	}
}

void reverse()
{
	struct link_list* current=(struct link_list* )malloc(sizeof(struct link_list));
	struct link_list* prev=(struct link_list* )malloc(sizeof(struct link_list));
	struct link_list* next=(struct link_list* )malloc(sizeof(struct link_list));
	current=head;
	prev=next=NULL;
	while(current!=NULL)
	{
		next=current->link;
		current->link=prev;
		prev=current;
		current=next;
	}
	head=prev;
	printf("after sorting ");
	display();
}

void swap_any_two()
{
	printf("press.\n\t1.for swap two conseccutive node.\n");
	int value1;
	scanf("%d",&value1);
	switch(value1)
	{
		case 1: consecutive(); break ;
		//add some more case
		default :printf("yout enter wrong choice.\n"); break ;
	}
}

void consecutive()
{
	if(count==1)
	{
		printf("swapping is not possible.\n");
	}
	else
	{
		printf("enter the node value that yout want to swap with next node\n");
		int x;
		scanf("%d",&x);
		printf("position is %d\n",x);
		struct link_list* p=(struct link_list*)malloc(sizeof(struct link_list));
		if(count==2 && x==1)
		{
			p=head;
			head=tail;
			tail=p;
			head->link=tail;
			tail->link=NULL;
		}
		else
		{
			struct link_list* q=(struct link_list*)malloc(sizeof(struct link_list));
			struct link_list* r=(struct link_list*)malloc(sizeof(struct link_list));
			q=head;
			r=NULL;
			if(x==1)
			{
				/* loop create infinte loop list. so this is required*/
				p=head;
				head=head->link;
				q=head->link;
				head->link=p;
				p->link=q;
			}
			else
			{
				for(int i=0;i<x-1;i++)
				{
					p=q;
					q=q->link;
				}
				r=q->link;
				//now we reach at that node.
				//now code for swapping.
				q->link=r->link;
				r->link=q;
				p->link=r;
			}
		}
		printf("after swapping \n");
	}	
	display();
}