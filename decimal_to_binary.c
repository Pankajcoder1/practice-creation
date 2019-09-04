#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	//this is for 64 bit operating system.
	//c for check the first positon of 1 from right.
	//k for print the no when ever required.
	//  l used to check no is positive or negative.
	int i,count=0,a[64],k,value,c,value1,l;
	printf("press\n1.for positive no\n2.for negative no.\n3.to exit\n");
	scanf("%d",&value1);
	while(value1!=3)
	{	
		printf("enter the no: ");
		scanf("%d",&i);
		// k=i;
		if(i<0)
		{
			l=-i;
		}
		else
		{
			l=i;
		}
		while(l>0)
		{
			a[count]=l%2;
			l=l/2;
			count++;
		}
		switch(value1)
		{
			case 1:
				{
					printf("representation of positive no in all form is same.\n");
					printf("So representation of given no is :\n");
					for(int j=count-1;j>=0;j--)
					{
						printf("%d ",a[j]);
					}
					printf("\n");
				}
				count=0;
				break;

			case 2:
			{
				while(value!=3)
				{
					printf("press\n1.to change in binary\n2.to change in one's compliment\n3.exit\n");
					scanf("%d",&value);
					switch(value)
						{
							case 1:
							{
								printf("this is in binary form of no %d\n",k);
								//to change no into binary code.
							
								for(int j=count;j>=0;j--)
								{
									if (j==count)
									{
										 printf("1 ");
									}
									else
									{
										printf("%d ",a[j]);
									}
								}
								printf("\n");
								count=0;
							}
							break;
							case 2:
							{
								//no to change into one's compliment.
								printf("Its 1's compliment is :\n");
								for(int j=count;j>=0;j--)
								{
									if (j==count)
									{
										printf("1 ");
									}
									else
									{
										if(a[j]==0)
										{
											printf("1 ");
										}
										else
										{
											printf("0 ");
										}
									}
								}
								printf("\n");
							}
							break;
							// case 3:
							// {
							// 	// code for two's copliment.
							// }
							break;
							// case 4: break;
							default: printf("you entered some thing wrong.\n");
			
						}
		
				}
			}
			default :
				{
					printf("you entered some thing wrong.\n");
				}	
		}
		printf("press\n1.for positive no\n2.for negative no.\n3.to exit\n");
		scanf("%d",&value1);	
	}
	return 0;
}
