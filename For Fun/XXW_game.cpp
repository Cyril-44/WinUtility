#include <stdio.h>
#include <wchar.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#define kd(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0)
struct Mjplayer
{
	wchar_t name[21];
	int attack;
	int defense;
	int health;
	long int max_health;
	int mjplace;
} mjplayer = {L"弗罗多", 50, 40, 100, 100, 1};
struct Mjenemy
{
	wchar_t name[20];
	int attack;	 //攻击
	int defense; //防御
	int health;
} mjjl = {L"戒灵", 500, 300, 2300},
  mjhalf_orcs = {L"半兽人", 25, 15, 100},
  mjstrong_orcs = {L"强兽人", 50, 20, 150},
  mjshaman = {L"白袍巫师萨鲁姆", 200, 250, 1000},
  mjsuolon = {L"索隆", 1000, 500, 5000},
  mjpirate = {L"海盗", 55, 25, 170},
  mjelephant = {L"猛犸象", 90, 50, 300};
struct Mjplace
{
	int share;
	int oldforest;
	int puli;
	int riwendaier;
	int moriya;
	int fagonforest;
	int ruohan;
	int gondo;
	int moduo;
	int duoerji;
	int blackforest;
	int longlake;
	int lonelymou;
} place = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
inline void setc(int ForgC, int BackC)
{
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}
void mjditu()
{
	system("cls");
	setc(0x3, 0);
	wprintf(L" ---------------------------------------------------------------- \n");
	wprintf(L" |                                    ~              ___^13     | \n");
	wprintf(L" |                              ^      ~            /           | \n");
	wprintf(L" |                               ^     ~       _____12          | \n");
	wprintf(L" |                               ^      ~     11   ~~           | \n");
	wprintf(L" |                                ^      ~    |    ~            | \n");
	wprintf(L" |                                 ^     ~    |   ~             | \n");
	wprintf(L" |                                  ^ ~~~~    10  ~           | \n");
	wprintf(L" |  1___2 ______3________      ___4 ^5___~___/     ~            | \n");
	wprintf(L" |                       |____/     ^ |   ~       ~             | \n");
	wprintf(L" |                                  ^ |    ~~~~ ~               | \n");
	wprintf(L" |                                  ^ |     ~                   | \n");
	wprintf(L" |                                  ^ |     ~                   | \n");
	wprintf(L" |                                  ^ |_6  ~                    | \n");
	wprintf(L" |                                       |~                     | \n");
	wprintf(L" |                                       ~_7                    | \n");
	wprintf(L" |                                       ~ |                    | \n");
	wprintf(L" |                                     ~   |                    | \n");
	wprintf(L" |                                  ~      |_8_________^9^      | \n");
	wprintf(L" ---------------------------------------------------------------- \n");
	setc(0x2, 0);
	wprintf(L"------------------------------分界线-------------------------------\n");
	wprintf(L"    主要地点：\n1. 夏尔(你家)   2. 老林   3. 布里   4. 瑞文戴尔   5. 摩瑞亚矿坑 \n");
	wprintf(L"6. 法贡森林   7. 洛汗王国   8. 刚铎王国   9. 魔多(终点)  10. 多尔吉尔多\n\n");
	setc(0x5, 0);
	wprintf(L"------------------------------分界线-------------------------------\n");
	wprintf(L"    体验地点：\n11. 幽暗密林   12. 长湖镇   13. 孤山  \n\n");
	setc(0x6, 0);
	wprintf(L"------------------------------分界线-------------------------------\n");
	wprintf(L"注意\n '/' '_' '|' 为可行走的路 '^' 为山 '~'为水 \n\n");
	setc(0x9, 0);
	wprintf(L"------------------------------分界线-------------------------------\n");
	wprintf(L"    您现在在：%d号地点。\n\n 输入1结束。", mjplayer.mjplace);
	setc(0x7, 0);
	int mjws;
	scanf("%d", &mjws);
	system("cls");
}
HANDLE hop = GetStdHandle(STD_OUTPUT_HANDLE);
HWND conh = GetForegroundWindow();
inline void printOneByOne(const wchar_t s[])
{
	for (int i = 0; s[i]; i++)
	{
		if (s[i] == '\n')
		{
			Sleep(1000);
			system("cls");
			continue;
		}
		wprintf(L"%lc", s[i]);
		Sleep(50);
	}
}
inline void setFont(int size)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = size; //设置字体大小
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;	   //字体粗细 FW_BOLD
	wcscpy(cfi.FaceName, L"黑体"); //设置字体，必须是控制台已有的
	SetCurrentConsoleFontEx(hop, 0, &cfi);
	//获得当前字体
	// HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	// CONSOLE_FONT_INFO consoleCurrentFont;
	// GetCurrentConsoleFont(handle, FALSE, &consoleCurrentFont);
}
inline void initpr(int n, int t)
{
	while (n--)
		printf("\n");
	while (t--)
		printf("\t");
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
	INPUT inp[2] = {0};
	inp[0].type = INPUT_KEYBOARD;
	inp[0].ki.wVk = VK_F11;
	inp[1].type = INPUT_KEYBOARD;
	inp[1].ki.wVk = VK_F11;
	inp[1].ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, inp, sizeof inp[0]);
	SendInput(1, inp + 1, sizeof inp[0]);
	setFont(24);
	_wsetlocale(LC_ALL, L"chs");
	setlocale(LC_ALL, "chs");
	system("title Central Plains Interesting Trip");
	wcscpy;
	const wchar_t info[] = L"	\
		欢迎来到中土奇旅。\n	\
		本游戏位于第三纪元的中土世界。\n	\
		黑暗魔王索隆利用魔戒让中土世界陷入了黑暗。\n	\
		你是魔戒持有者，请你前往末日火山摧毁魔戒。\n";
	printOneByOne(info);
	Sleep(1000);
	system("cls");
}
inline void gotopos(short x, short y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(hop, pos);
}
inline void end()
{
	system("cls");
	initpr(13, 3);
	wprintf(L"游戏结束，感谢您的游玩！");
	initpr(1, 3);
	wprintf(L"按任意键退出...");
	system("pause >nul 2>nul");
}
inline void load(int mx)
{
	system("cls");
	setc(0x3, 0);
	wprintf(L"loading...\n");
	setc(0x4, 0);
	wprintf(L"[");
	for (int i = 0; i < mx; i++)
		wprintf(L" ");
	wprintf(L"]");
	setc(0x2, 0);
	for (int j = 1; j <= mx; j++)
	{
		gotopos(j, 1);
		wprintf(L"-");
		gotopos(mx + 2, 1);
		wprintf(L"%d%%", j * 100 / mx);
		Sleep(250);
	}
	setc(0xb, 0);
	wprintf(L"\nDone.");
	Sleep(1000);
	system("cls");
}
int main()
{
	setc(0x3, 0);
	init();
	Sleep(500);
	setc(0x2, 0);
	wprintf(L"介绍： \n");
	Sleep(500);
	setc(0x4, 0);
	wprintf(L"建议阅读：");
	setc(0x5, 0);
	Sleep(50);
	wprintf(L"The Lord of The Rings-----魔戒 \n");
	Sleep(500);
	setc(0x9, 0);
	setc(0x7, 0);
	wprintf(L"点击开始游戏");
	while (!kd(VK_LBUTTON))
		;
	load(25);
	setc(0x7, 0);
	end();
	return 0;
}