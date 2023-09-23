#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <time.h>
typedef std::pair<int, int> pii;
typedef std::vector<int> Vec;
#define F first
#define S second
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
#undef max
#undef min
string i2s(int x)
{
    string op = "";
    int y = 0;
    while (x)
        y = y * 10 + x % 10, x /= 10;
    if (y == 0)
        return "0";
    while (y)
        op += y % 10 + '0', y /= 10;
    return op;
}
// string st(Vec v)
// {
//	string op="";
//	if (x<10) op+=(char)(x+'0');
//	else op+=(char)(x/10+'0'),op+=(char)(x%10+'0');
//
//	if (f==0) op+="+";
//	else op+="-";
//
//	if (y<10) op+=(char)(y+'0');
//	else op+=(char)(y/10+'0'),op+=(char)(y%10+'0');
//
//	op+="=";
//
//	return op;
//}
string st(Vec v)
{
    string op = "";
    //	printf("%d",v.size());
    if (v.size() == 3)
    {
        op += i2s(v[0]), op += (char)v[1], op += i2s(v[2]);
    }
    else if (v.size() == 5)
    {
        op += v[0], op += (char)v[1], op += "(", op += i2s(v[2]), op += (char)v[3], op += i2s(v[4]), op += ")";
    }
    op += "=";
    return op;
}
pii jia()
{
    int a = rand() % 80, b = rand() % (100 - a) + 1;
    return make_pair(a, b);
}
pii jian()
{
    int a = rand() % 101, b = rand() % max(1, a);
    return make_pair(a, b);
}
pii cheng()
{
    int a = rand() % 10, b = rand() % 10;
    return make_pair(a, b);
    //	return make_pair(max(1,a),max(1,b));
}
int main()
{
    freopen("t1.rtf", "w", stdout);
    srand(time(NULL));
    int n = 10;
    while (n--)
    {
        for (int i = 1; i <= 25; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                int tmp = rand() % 20, b;
                pii a;
                string op;
                if (tmp <= 2)
                {
                    a = jia();
                    op = st(Vec{a.F, '+', a.S});
                }
                else if (tmp <= 5)
                {
                    a = jian();
                    op = st(Vec{a.F, '-', a.S});
                }
                else if (tmp <= 8)
                {
                    a = cheng();
                    op = st(Vec{a.F, '*', a.S});
                }
                else if (tmp <= 14)
                {
                    // A-(B+C)
                    a = jian();
                    b = rand() % max(1, (a.F - a.S));
                    op = st(Vec{a.F, '-', a.S, '+', b});
                }
                else if (tmp <= 19)
                {
                    // A-(B-C)
                    a = jian();
                    b = rand() % max(1, (100 - (a.F - a.S)));
                    op = st(Vec{a.F, '-', a.S, '-', b});
                }
                printf("%-15s", op.c_str());
            }
            putchar('\n');
        }
    }
    return 0;
}
