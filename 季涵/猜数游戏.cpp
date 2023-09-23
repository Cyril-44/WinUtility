#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <windows.h>
#define N 2
#define M 3
using namespace std;
bool mord[M + 1];
int maxc[M + 1], c[M + 1] = {0}, np, point[10];
char name[10][20];
void color(int a) //颜色函数
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}
void gotoxy(int x, int y) //位置函数
{
    COORD pos;
    pos.X = 2 * x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int play();
int set_g(int set1);
int main()
{
    map<int, string> ma;
    char chti[10] = {" ·>"};
    ma[1] = "单人竞猜";
    ma[2] = "多人竞猜";
    ma[N + 1] = "返回";
    int ch = 1;
    system("color f0");
    while (1)
    {
        for (int i = 1; i <= N + 1; i++)
        {
            if (i == ch)
            {
                color(192);
                printf("%s", chti);
            }
            else
            {
                color(240);
                for (int i = 1; i <= strlen(chti); i++)
                    printf(" ");
            }
            cout << ma[i];
            for (int j = 80 - ma[i].size() - strlen(chti); j > 0; j--)
                cout << " ";
            color(240);
        }
        char x;
        x = getch();
        if (x == 'w' && ch > 1)
            ch--;
        if (x == 's' && ch < N + 1)
            ch++;
        if (x == 13)
        {
            if (ch == N + 1)
                return 0;
            switch (ch)
            {
            case 1:
                np = 1;
                break;
            case 2:
                system("cls");
                printf("请输入玩家数：\n");
                cin >> np;
                break;
            }
            set_g(ch);
        }
        system("cls");
    }
    return 0;
}
int set_g(int set1)
{
    system("cls");
    bool setmord[N + 1][M + 1] = {{1, 0, 0, 0}, //空行
                                  {1, 1, 1, 0},
                                  {1, 1, 1, 1}};
    map<int, string> ma;
    char chti[10] = {" ·>"};
    ma[1] = "难度";
    maxc[1] = 4;
    ma[2] = "噩梦";
    maxc[2] = 3;
    ma[3] = "自动跳过";
    maxc[3] = 5;
    ma[M + 1] = "下一步";
    ma[M + 2] = "返回";
    int ch = 1;
    system("color f0");
    for (int i = 1; i <= M; i++)
        mord[i] = setmord[set1][i];
    while (1)
    {
        for (int i = 1; i <= M + 2; i++)
        {
            if (i <= M && !mord[i])
                continue;
            if (i == ch)
            {
                color(192);
                printf("%s", chti);
            }
            else
            {
                color(240);
                for (int i = 1; i <= strlen(chti); i++)
                    printf(" ");
            }
            cout << ma[i];
            for (int j = 80 - ma[i].size() - strlen(chti); j > 0; j--)
                cout << " ";
            if (i <= M)
            {
                gotoxy(20, i - 1);
                int co = i == ch ? 192 : 240;
                for (int j = 0; j <= maxc[i]; j++)
                {
                    if (j != c[i])
                        co += 8;
                    color(co);
                    printf("%d", j);
                    if (j != c[i])
                        co -= 8;
                    color(co);
                    printf(" ");
                }
                gotoxy(0, i);
            }
            color(240);
        }
        char x;
        x = getch();
        if (x == 'w' && ch > 1)
        {
            ch--;
            while (!mord[ch] && ch <= M)
                ch--;
        }
        if (x == 's' && ch < M + 2)
        {
            ch++;
            while (!mord[ch] && ch <= M)
                ch++;
        }
        if (ch <= M)
        {
            if (x == 'd' && c[ch] < maxc[ch])
                c[ch]++;
            if (x == 'a' && c[ch] >= 1)
                c[ch]--;
        }
        if (x == 13)
        {
            if (ch == M + 2)
                return 0;
            if (ch == M + 1)
                break;
        }
        system("cls");
    }
    system("cls");
    bool flag = 0;
    for (int i = 1; i <= np; i++)
    {
        if (flag || set1 == 1)
            printf("请输入玩家%d名字：\n", i);
        gets(name[i]);
        point[i] = 0;
        if (!flag && set1 != 1)
        {
            i--;
            flag = 1;
        }
    }
    Sleep(500);
    play();
    return 0;
}
int play()
{
    system("cls");
    srand(time(NULL));
    int fw1, fw2 = 1, ans;
    if (c[1] == 0)
        fw1 = 5000;
    else
        fw1 = 10000 * c[1];
    ans = rand() % fw1 + 1;
    printf("数据范围1~%d\n", fw1);
    system("pause");
    system("cls");
    int findit = 0, l = 0, lnum, ld, lz, em;
    bool around = 0;
    while (!findit)
    {
        printf("提示： ");
        if (c[2] == 0)
            printf("未开启\n");
        else
            printf("%5d ~ %5d \n", fw2, fw1);
        printf("噩梦： ");
        if (em == 1)
            printf("数变大了\n");
        if (em == -1)
            printf("数变小了\n");
        else
            printf("未发生\n");
        printf("\n上一回合：\n");
        if (around)
        {
            cout << "玩家" << l << " " << name[l] << endl;
            if (ld != 2)
                printf("%d\n", lnum);
            if (ld == 1)
                printf("大了 ");
            if (ld == -1)
                printf("小了 ");
            if (ld == 0)
                printf("出错\n");
            if (ld == 2)
                printf("被跳过\n");
            else
                switch (lz)
                {
                case 1:
                    color(252);
                    point[l] += 7;
                    printf("近在眼前\n");
                    break;
                case 2:
                    color(253);
                    point[l] += 5;
                    printf("百步之遥\n");
                    break;
                case 3:
                    color(249);
                    point[l] += 3;
                    printf("仰望莫及\n");
                    break;
                case 4:
                    color(240);
                    point[l] += 1;
                    printf("远在天边\n");
                    break;
                }
            color(240);
        }
        else
        {
            printf("无\n\n");
            around = 1;
        }
        Sleep(500);
        l = l % np + 1;
        printf("\n当前回合：\n");
        cout << "玩家" << l << " " << name[l];
        ld = rand() % 10 < c[3] ? 2 : 0;
        if (ld == 2)
        {
            printf("\n回合被跳过\n");
            Sleep(2000);
            system("cls");
            continue;
        }
        printf(" 请猜数：\n");
        char readn[20];
        gets(readn);
        lnum = 0;
        for (int i = 0; i < strlen(readn) && readn[i] <= '9' && readn[i] >= '0'; i++)
            lnum = lnum * 10 + readn[i] - '0';
        if (lnum <= 0 || lnum >= 40000)
        {
            ld = 0;
            lz = 0;
        }
        else
        {
            if (lnum > ans)
            {
                ld = 1;
                if (lnum < fw1)
                    fw1 = lnum;
            }
            if (lnum < ans)
            {
                ld = -1;
                if (lnum > fw2)
                    fw2 = lnum;
            }
            if (lnum == ans)
                findit = 1;
            lz = abs(lnum - ans);
            if (lz <= 10)
                lz = 1;
            else if (lz <= 100)
                lz = 2;
            else if (lz <= 1000)
                lz = 3;
            else
                lz = 4;
        }
        if (findit)
            printf("正确\n");
        else
        {
            if (ld == 1)
                printf("大了 ");
            if (ld == -1)
                printf("小了 ");
            if (ld == 0)
                printf("出错\n");
            switch (lz)
            {
            case 1:
                color(252);
                printf("近在眼前\n");
                break;
            case 2:
                color(253);
                printf("百步之遥\n");
                break;
            case 3:
                color(249);
                printf("仰望莫及\n");
                break;
            case 4:
                color(240);
                printf("远在天边\n");
                break;
            }
            color(240);
        }
        em = 0;
        if (lz <= 3 && c[2])
        {
            em = rand() % 2 == 0 ? -1 : 1;
            int em1;
            em1 = rand() % (2 * c[2]);
            if (em1 * em > 40000 || em1 * em <= 0)
                em = em * -1;
            ans = ans + em * em1;
            if (em == 1)
                fw1 += 2 * c[2];
            else
                fw2 -= 2 * c[2];
        }
        Sleep(1000);
        system("cls");
    }
    point[l] += 20;
    printf("玩家%d %s 猜对了\n", l, name[l]);
    system("pause");
    system("cls");
    int poi = 0;
    for (int i = 1; i <= np; i++)
        poi += point[i];
    poi = poi / 100 + 1;
    for (int i = 1; i <= np; i++)
    {
        point[i] = point[i] / poi;
        printf("玩家%d %s 得分 ", i, name[i]);
        if (point[i] >= 50)
            color(254);
        else if (point[i] >= 30)
            color(249);
        else if (point[i] >= 20)
            color(250);
        else
            color(248);
        printf("%d\n", point[i]);
        color(240);
        Sleep(500);
    }
    system("pause");
    system("cls");
    return 0;
}
