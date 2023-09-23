#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <wchar.h>
#include <stdlib.h>
#include <conio.h>
#define kd(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0)
#define s(slp) Sleep(slp)
#define ss(sys) system(sys)
const wchar_t hy_1[] = L"	\
	欢迎来到LYZ蒟蒻、LJ、HXDLB、CyrilZSY制作的ruozhi小游戏#	\
	本游戏仿照generals.io(将军旗)制作#	\
	安心游戏，禁止抄袭！";
HANDLE hop = GetStdHandle(STD_OUTPUT_HANDLE);
HWND conh = GetForegroundWindow();
// const str hy_2="1 FFA2 1v1(暂未开放)\n\n";
void FFA();
void _1v1();
void setc(int ForgC, int BackC)
{
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

inline void initpr(int n, int t)
{
	while (n--)
		printf("\n");
	while (t--)
		printf("	");
}
inline void init()
{
	HANDLE hand = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hand, &mode);
	mode &= ~ENABLE_QUICK_EDIT_MODE; //移除快速编辑模式
	mode &= ~ENABLE_INSERT_MODE;	 //移除插入模式
	mode &= ~ENABLE_MOUSE_INPUT;
	SetConsoleMode(hand, mode);
	ss("title game");
	ss("mode con cols=100 lines=30");
	_wsetlocale(LC_ALL, L"chs");
	for (int i = 0; hy_1[i]; i++)
	{
		if (hy_1[i] == '#')
		{
			s(1000);
			ss("cls");
			continue;
		}
		wprintf(L"%lc", hy_1[i]);
		s(50);
	}
	s(1000);
	system("cls");
}
inline void gotopos(short x, short y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(hop, pos);
}
void FFA(int mx)
{
	int renshu = 0;
	ss("cls");
	// system("mode con cols=100 lines=30");
	initpr(14, 5);
	wprintf(L"Game starting...");
	while (renshu <= mx)
	{
		gotopos(56, 14);
		printf("%d%%", renshu * 100 / mx);
		renshu++;
		s(100);
	}
	return;
}
void _1v1()
{
	return;
}
void start()
{
	ss("cls");
	initpr(12, 4);
	wprintf(L"鼠标点击数字选择模式：");
	initpr(1, 4);
	wprintf(L"1 FFA");
	initpr(1, 4);
	wprintf(L"2 1v1(暂不开放)");
	char ch = '\0';
	while (1)
	{
		if (kd(VK_LBUTTON))
		{
			POINT p;
			CONSOLE_FONT_INFO finf;
			GetCursorPos(&p);
			ScreenToClient(conh, &p);
			GetCurrentConsoleFont(hop, 0, &finf);
			int x = p.x / finf.dwFontSize.X,
				y = p.y / finf.dwFontSize.Y;
			if (x == 32 && y == 13)
			{
				FFA(10);
				break;
			}
			else if (x == 32 && y == 14)
			{
				_1v1();
				break;
			}
			else
			{
				MessageBeep(MB_ICONWARNING);
			}
			Sleep(100);
		}
		/* ch = getch();
		if (ch == '1')
		{
			FFA();
			break;
		}
		//	else if (ch == '2') { _1v1(); break; }
		else
		{
			MessageBeep(MB_ICONERROR);
		} */
	}
	/* while (1) {
		if (kd('1')) {
			FFA();
			break;
		}
		if (kd('2')) {
			_1v1();
			break;
		}
	} */
}
inline void end()
{
	ss("cls");
	initpr(13, 3);
	wprintf(L"游戏结束，感谢您的游玩！");
	initpr(1, 3);
	wprintf(L"按任意键退出...");
	ss("pause >nul 2>nul");
}
int main()
{
	init();
	start();
	end();
	return 0;
}

