#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <ctime>
using namespace std; 
int main(void)
{
	srand((int)time(0));
	int c = 0;
	int i ;
	int x,y,z,s = 0;
	printf("Loading game");
	for (i=1;i<=20;i++)
	{
		printf(".");
		_sleep(50);
	}
	printf(".\n");
	printf("Welcome to Math Kingdom! You are going to do ten calculation problems. Are you ready? (If you are ready, press 1. If not, press 0 to exit)");
	scanf("%d",&c);
	while (c==1)
	{
		s = 0;
		printf("Seting calculation problems");
		for (i=1;i<=10;i++)
		{
			printf(".");
			_sleep(20);
		}
		printf(".\n");
		for (i=1;i<=10;i++)
		{
			x = (rand() % (100))+ 1;
			y = (rand() % (100))+ 1;
			while ((x+y)>100)
			{
				x = (rand() % (100))+ 1;
				y = (rand() % (100))+ 1;
			}
			printf("Calculation problem %d : %d+%d=",i,x,y);
			scanf("%d",&z);
			if (z==(x+y))
			{
				printf("Congratulations! +10! \n");
				s += 10;
			}
			else
			{
				printf("I'm sorry, you are wrong, Please type it again:");
				scanf("%d",&z);
				if (z==(x+y))
				{
					printf("Well down! +5! \n");
					s += 5;
				}
				else
				{
					printf("You are wrong again! The correct answer is %d\n",x+y);
				}
			}
		}
		if (s==100)
		{
			printf("A Excellent!\n");
		}
		else
		{
			if (s>=85)
			{
				printf("B Very good!\n");
			}
			else
			{
				if (s>=70)
				{
					printf("C Good!\n");
				}
				else
				{
					if (s>=60)
					{
						printf("D OK!\n");
					}
					else
					{
						printf("F Bad!\n");
					}
				}
			}
		}
		printf("Try again? (Press 1 to try again, press 0 to exit. )");
		scanf("%d",&c);
	}
	printf("See you! Exiting");
	for (i=1;i<=20;i++)
	{
		printf(".");
		_sleep(50);
	}
	printf(".\n");
	return 0;
}
