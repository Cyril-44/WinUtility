#include <cmath>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

const double pi = 3.1415926536; // C++竟然没有自带的pi，而cmath的三角函数都是用弧度做测量单位的，太坑人了

int playerx = 0, playery = 29, playerhealth = 100;
int arena[30][30];
int gametime;
bool playeralive;
int playerrevivetimer = 0;
int score1, score2;

int playerweapon = 1;

int load()
{
    cout << "Loading...";
    return 0;
}

int loading = load();

int playerdir1[16] = {-1, 270, 0, 315, 90, -1, 45, 0, 180, 225, -1, 270, 135, 180, 90, -1};

class bullet
{ // 还是class方便
  public:
    bool active;
    double x, y, speed, dir; // 0 <= dir <= 720
    int shooter;
    int atk;
    int damage;
    bullet(double a, double b, double c, double d, int z, int atk)
    {
        x = a;
        y = b;
        speed = c;
        dir = d;
        shooter = z;
        damage = atk;
        active = true;
    }
    void update()
    {
        // return;
        if (!active)
            return;
        x += sin(dir / 180. * pi) * speed; // 三角函数没白学（
        y -= cos(dir / 180. * pi) * speed;
        if (x >= 29.5 || x < -0.5 || y >= 29.5 || y < -0.5)
            active = false;
    }
    pair<int, int> getxy()
    {
        pair<int, int> answer;
        int x1 = x, y1 = y;
        answer.first = x1;
        answer.second = y1;
        if (x - x1 >= 0.5)
            answer.first++;
        if (y - y1 >= 0.5)
            answer.second++;
        return answer;
    }
};

vector<bullet> bullets;

void gotoxy(int x, int y)
{
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    HANDLE hConsoleOut;
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
    csbiInfo.dwCursorPosition.X = x;
    csbiInfo.dwCursorPosition.Y = y;
    SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

class weapon
{
  public:
    vector<int> dirs;
    double speed;
    int damage;
    int reload;
    int reloadtimer;
    weapon(int a, double b, vector<int> c, int d)
    {
        dirs = c;
        speed = b;
        damage = a;
        reload = d;
        reloadtimer = 0;
    }
    void shoot(int dir, int x, int y, int shooter)
    {
        if (playerdir1[dir] < 0)
            return;
        if (reloadtimer)
            return;
        for (int n = 0; n < dirs.size(); n++)
        {
            bullet b(x, y, speed / 4., dirs[n] + playerdir1[dir], shooter, damage);
            bullets.push_back(b);
        }
        reloadtimer = reload;
    }
};

vector<weapon> weapons;

class robot
{
  public:
    bool alive;
    bool mode;
    int health;
    int id;
    int x, y;
    int dir;
    int revivetimer;
    weapon w = weapons[1];
    robot(int a)
    {
        id = a;
        if (id < 5)
        {
            x = 0;
            y = 29;
        }
        else
        {
            x = 29;
            y = 0;
        }
        health = 100;
        dir = 0;
        alive = true;
        mode = false;
        w = weapons[rand() % 2];
        revivetimer = 0;
    }
    void move()
    {
        if (revivetimer == 0 && !alive)
        {
            alive = true;
            health = 100;
            if (id < 5)
            {
                x = 0;
                y = 29;
            }
            else
            {
                x = 29;
                y = 0;
            }
            mode = false;
        }
        if (health < 0 && alive)
        {
            revivetimer = 30;
            alive = false;
            if (id < 5)
                score2++;
            else
                score1++;
        }
        if (!alive)
        {
            revivetimer--;
            return;
        }
        // if (rand() % 3) return;
        int a = 0, b = 0;
        if (id < 5 xor mode)
        {
            if (rand() % 2 && x < 29)
                a = 4;
            if (rand() % 2 && y)
                b = 2;
            if (a + b)
            {
                dir = a + b;
                if (a)
                    x++;
                if (b)
                    y--;
            }
        }
        if (id >= 5 xor mode)
        {
            if (rand() % 2 && x)
                a = 1;
            if (rand() % 2 && y < 29)
                b = 8;
            if (a + b)
            {
                dir = a + b;
                if (a)
                    x--;
                if (b)
                    y++;
            }
        }
        w.shoot(dir, x, y, id);
        if (x + y == 29 && min(x, y) == 0)
            mode = !mode;
    }
};

int fight()
{
    bullets.clear(); // 否则会TLE
    gametime = 0;
    int lastdir = 0;
    vector<robot> robots;
    for (int id = 2; id < 9; id++)
    {
        robot r(id);
        robots.push_back(r);
    }
    score1 = 0;
    score2 = 0;
    while (true)
    {
        string output;
        int playerdir = 0;
        bool pdc = false;
        if (!playeralive && playerrevivetimer == 0)
        {
            playerhealth = 100;
            playerx = 0;
            playery = 29;
            playeralive = true;
        }
        if (playerhealth <= 0 && playeralive)
        {
            playeralive = false;
            playerrevivetimer = 30;
            score2++;
        }
        if (!playeralive)
            playerrevivetimer--;
        if (playerhealth > 0)
        {
            if (GetAsyncKeyState('A') & 0x8000 && playerx)
            {
                playerx--;
                playerdir++;
                pdc = true;
            }
            if (GetAsyncKeyState('W') & 0x8000 && playery)
            {
                playery--;
                playerdir += 2;
                pdc = true;
            }
            if (GetAsyncKeyState('D') & 0x8000 && playerx < 29)
            {
                playerx++;
                playerdir += 4;
                pdc = true;
            }
            if (GetAsyncKeyState('S') & 0x8000 && playery < 29)
            {
                playery++;
                playerdir += 8;
                pdc = true;
            }
            if (pdc)
                lastdir = playerdir;
            else
                playerdir = lastdir;
            if (GetAsyncKeyState(32) & 0x8000)
                weapons[playerweapon].shoot(playerdir, playerx, playery, 1);
        }
        if (weapons[playerweapon].reloadtimer)
            weapons[playerweapon].reloadtimer--;
        for (int id = 0; id < 7; id++)
            robots[id].w.reloadtimer = max(robots[id].w.reloadtimer - 1, 0);
        for (int m = 0; m < 4; m++)
            for (int n = 0; n < bullets.size(); n++)
            {
                if (!bullets[n].active)
                    continue;
                bullets[n].update();
                pair<int, int> xy = bullets[n].getxy();
                if (playerx == xy.first && playery == xy.second && bullets[n].shooter > 4 && playerhealth > 0)
                {
                    playerhealth -= bullets[n].damage;
                    bullets[n].active = false;
                }
                for (int id = 0; id < 3; id++)
                    if (robots[id].x == xy.first && robots[id].y == xy.second && bullets[n].shooter > 4 &&
                        robots[id].alive)
                    {
                        robots[id].health -= bullets[n].damage;
                        bullets[n].active = false;
                    }
                for (int id = 3; id < 7; id++)
                    if (robots[id].x == xy.first && robots[id].y == xy.second && bullets[n].shooter < 5 &&
                        robots[id].alive)
                    {
                        robots[id].health -= bullets[n].damage;
                        bullets[n].active = false;
                    }
            }
        for (int p = 0; p < 30; p++)
            for (int q = 0; q < 30; q++)
                arena[p][q] = 0;
        for (int n = 0; n < bullets.size(); n++)
        {
            if (!bullets[n].active)
                continue;
            pair<int, int> xy = bullets[n].getxy();
            arena[xy.second][xy.first] = -1;
        }
        for (int id = 2; id < 9; id++)
        {
            robots[id - 2].move();
            if (robots[id - 2].alive)
                arena[robots[id - 2].y][robots[id - 2].x] = id;
        }
        if (playerhealth > 0)
            arena[playery][playerx] = 1;
        for (int p = playery - 4; p <= playery + 4; p++)
        {
            for (int q = playerx - 4; q <= playerx + 4; q++)
            {
                if (p >= 0 && q >= 0 && p < 30 && q < 30)
                {
                    if (arena[p][q] == -1)
                        output += "o ";
                    else if (arena[p][q] == 1)
                        output += "你";
                    else if (arena[p][q] < 5 && arena[p][q])
                        output += "友";
                    else if (arena[p][q])
                        output += "敌";
                    else
                        output += "..";
                }
                else
                    output += "  ";
            }
            output += "\n";
        }
        gotoxy(0, 0);
        cout << "现在对线已经过去了" << gametime / 600 << "分，" << gametime % 600 / 10 << "秒"
             << "          " << endl;
        cout << output;
        cout << "剩余rp：" << playerhealth << "  " << endl;
        cout << "我方分数：" << score1 << endl;
        cout << "xxs方分数：" << score2 << endl;
        Sleep(100 - clock() % 100);
        gametime++;
    }
    return false;
}

int main()
{
    srand(time(0));
    vector<int> a;
    a.push_back(0);
    vector<int> b;
    for (int n = -20; n <= 20; n += 10)
        b.push_back(n);
    weapons.push_back({7, 2, a, 1});
    weapons.push_back({5, 1.5, b, 5});
    system("cls");
    cout << "欢迎来到出言不逊！\n\n请选择你的化身：\n1或其他：oier\n2：喷子\n";
    char k = getch();
    if (k != 50)
        playerweapon = 0;
    cout << "对线马上开始！";
    system("pause");
    system("cls");
    int win = fight();
    system("cls");
    cout << "对线结果是：" << win << endl;
    cout << "对线总共耗时" << gametime / 600 << "分，" << gametime % 600 / 10 << "秒";
    return 0;
}
