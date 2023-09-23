#include <windows.h>
#include <thread>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define kd(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0)
HANDLE hop;
HWND conh;
FILETIME m_preidleTime;
FILETIME m_prekernelTime;
FILETIME m_preuserTime;

__int64 CompareFileTime2(FILETIME time1, FILETIME time2)
{
	__int64 a = (__int64)(time1.dwHighDateTime) << 32 | (__int64)(time1.dwLowDateTime);
	__int64 b = (__int64)(time2.dwHighDateTime) << 32 | (__int64)(time2.dwLowDateTime);

	return b - a;
}

void GetCpuUseage()
{
	GetSystemTimes(&m_preidleTime, &m_prekernelTime, &m_preuserTime);
	Sleep(1000);
}

double getCpuUsagePersent()
{
	FILETIME idleTime;
	FILETIME kernelTime;
	FILETIME userTime;
	GetSystemTimes(&idleTime, &kernelTime, &userTime);

	int idle = CompareFileTime2(m_preidleTime, idleTime);
	int kernel = CompareFileTime2(m_prekernelTime, kernelTime);
	int user = CompareFileTime2(m_preuserTime, userTime);

	if (kernel + user == 0)
		return 0.0;
	//（总的时间-空闲时间）/总的时间=占用cpu的时间就是使用率
	double cpu = abs((kernel + user - idle) * 100.0 / (kernel + user));

	m_preidleTime = idleTime;
	m_prekernelTime = kernelTime;
	m_preuserTime = userTime;
	return cpu;
}
void gotopos(short x, short y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(hop, pos);
}
void cpuPressureTest(void)
{
	int a = rand(), x = rand(), b = rand();
	while (!(kd('q') || kd('Q')))
	{
		a = ~(a * x + b & a * x + b | a * x + b);
	}
}
void cpuUsage(void)
{
	while (1)
	{
		gotopos(11, 0);
		wprintf(L"%.1lf%%", getCpuUsagePersent());
		Sleep(1000);
	}
}
int main()
{
	/*int i, n;
	n = 0x7fff;
	DWORD s, e, t1, t2;
	s = GetTickCount();
	for (i = 0; i < n; i++)
		printf("word\n");
	e = GetTickCount();
	t1 = e - s;
	s = GetTickCount();
	for (i = 0; i < n; i++)
		puts("word");
	e = GetTickCount();
	t2 = e - s;
	printf("printf: %d\nputs: %d\n", t1, t2);
	system("pause");*/
	srand(time(NULL));
	setlocale(LC_ALL, "chs");
	_wsetlocale(LC_ALL, L"chs");
	hop = GetStdHandle(STD_OUTPUT_HANDLE);
	conh = GetForegroundWindow();
	_putws(L"按任意键开始烤CPU(单核)，按q退出...");
	system("pause >nul 2>nul");
	pthread_t testthid, KAOJIJI[10];
	pthread_create(&testthid, NULL, (void *(*)(void *))cpuUsage, NULL);
	system("cls");
	wprintf(L"CPU使用率: ");
	int i;
	for (i = 0; i < 10; i++)
		pthread_create(KAOJIJI + i, NULL, (void *(*)(void *))cpuPressureTest, NULL);
	_putws(L"\n烤机结束,5秒后退出...");
	Sleep(4000);

	return 0;
}
