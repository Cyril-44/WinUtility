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
	printf("��Ϸ���ڼ����У����Ժ�...\n");
	for (i=1;i<=20;i++)
	{
		printf("�~");
		_sleep(50);
	}
	printf("�~\n");
	printf("��ӭ�����������������������ǻ�����ʮ��100���ڵļӷ������⣬׼�������𣿣�׼�����˰�1��û��׼���ð�0�˳���");
	scanf("%d",&c);
	while (c==1)
	{
		s = 0;
		printf("���ڳ�����");
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
			printf("��%d�⣺%d+%d=",i,x,y);
			scanf("%d",&z);
			if (z==(x+y))
			{
				printf("��ϲ�㣬����ˣ���ʮ�֣�\n");
				s += 10;
			}
			else
			{
				printf("������������������𰸣�");
				scanf("%d",&z);
				if (z==(x+y))
				{
					printf("��ϲ�㣬����ˣ�����֣�\n");
					s += 5;
				}
				else
				{
					printf("���ִ���������÷֣���ȷ���ǣ�%d\n",x+y);
				}
			}
		}
		if (s==100)
		{
			printf("������ �ǳ������ٽ�������");
		}
		else
		{
			if (s>=85)
			{
				printf("����� ͦ���ģ��������ͣ�");
			}
			else
			{
				if (s>=70)
				{
					printf("���� ����������Ŭ����");
				}
				else
				{
					if (s>=60)
					{
						printf("��� ���ͣ��������ܸ�������");
					}
					else
					{
						printf("�� �е��Ӵ��Ҫ�����ˣ�");
					}
				}
			}
		}
		printf("��������սһ���𣿣�������1���˳���0��");
		scanf("%d",&c);
	}
	printf("�´��ټ��������˳���Ϸ�����Ժ�...\n");
	for (i=1;i<=20;i++)
	{
		printf("�~");
		_sleep(50);
	}
	printf("�~\n");
	return 0;
}

