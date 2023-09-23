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
	printf("游戏正在加载中，请稍后...\n");
	for (i=1;i<=20;i++)
	{
		printf("▇");
		_sleep(50);
	}
	printf("▇\n");
	printf("欢迎来到计算王国！接下来我们会给你出十道100以内的加法运算题，准备好了吗？（准备好了按1，没有准备好按0退出）");
	scanf("%d",&c);
	while (c==1)
	{
		s = 0;
		printf("正在出题中");
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
			printf("第%d题：%d+%d=",i,x,y);
			scanf("%d",&z);
			if (z==(x+y))
			{
				printf("恭喜你，答对了！加十分！\n");
				s += 10;
			}
			else
			{
				printf("你答错啦！请重新输入答案：");
				scanf("%d",&z);
				if (z==(x+y))
				{
					printf("恭喜你，答对了！加五分！\n");
					s += 5;
				}
				else
				{
					printf("你又答错啦！不得分！正确答案是：%d\n",x+y);
				}
			}
		}
		if (s==100)
		{
			printf("★★★★★ 非常棒！再接再厉！");
		}
		else
		{
			if (s>=85)
			{
				printf("★★★★ 挺棒的！继续加油！");
			}
			else
			{
				if (s>=70)
				{
					printf("★★★ 还不错，继续努力！");
				}
				else
				{
					if (s>=60)
					{
						printf("★★ 加油，相信你能赶上来！");
					}
					else
					{
						printf("★ 有点差哟，要加油了！");
					}
				}
			}
		}
		printf("还想再挑战一局吗？（继续按1，退出按0）");
		scanf("%d",&c);
	}
	printf("下次再见！正在退出游戏，请稍后...\n");
	for (i=1;i<=20;i++)
	{
		printf("▇");
		_sleep(50);
	}
	printf("▇\n");
	return 0;
}

