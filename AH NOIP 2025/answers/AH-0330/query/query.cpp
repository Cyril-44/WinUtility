#include <bits/stdc++.h>
#define int long long
using namespace std;
int read() {
    int x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}
void write(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + '0');
    else write(x / 10), putchar(x % 10 + '0');
}
void write(int x, char c) { write(x); putchar(c); }

unsigned long long all;
signed main() {
    freopen("query.in", "r", stdin);
    freopen("query.out", "w", stdout);

    return 0;
}
