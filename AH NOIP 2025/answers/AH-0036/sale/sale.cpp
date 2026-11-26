#include <bits/stdc++.h>


using namespace std;

int c, T;
int n, m;
int a[100010];
struct node {
    int vl, ind;
} xx[100010];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();

    while(ch < '0' || ch > '9') {
        if(ch = '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9) {
        write(x / 10);
    }
    putchar(x % 10 + '0');
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

inline bool cmp(node x, node y) {
    return x.vl == y.vl ? x.vl * x.ind > y.vl * y.ind : x.vl > y.vl;
}

inline void cal() {

}

inline bool cmp(int x, int y) {
    return x > y;
}

inline void solve1() {
    n = read();
    m = read();
    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    sort(a + 1, a + 1 + n, cmp);

    for(int i = 1; i <= n; ++i) {

    }
}

int main() {

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    c = read();
    T = read();

    if(c <= 6) {
        while(T--) {
            solve1();
        }
    }

    while(T--) {
        solve();
    }

    return 0;
}
