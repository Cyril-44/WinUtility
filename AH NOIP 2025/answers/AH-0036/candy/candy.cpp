#include <bits/stdc++.h>

#define N 1000010
#define int long long

using namespace std;

int n, m;
int minn = 10000000000;
int ans = -1;
int xx[N];
int sum[N];

struct node {
    int xi, yi;
}a[N];

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

// inline bool cmp1(node x, node y) {
    // return x.sum < y.sum;
// }

signed main() {

    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);

    n = read();
    m = read();

    for(int i = 1; i <= n; ++i) {
        a[i].xi = read();
        xx[i] = a[i].xi;
        a[i].yi = read();
        minn = min(minn, a[i].xi + a[i].yi);
    }

    // writeln(minn);

    // writeln(lst);
    sum[0] = 0;
    sort(xx + 1, xx + n + 1);
    for(int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + xx[i];
    }
    for(int i = 0; i <= n; ++i) {
        if(m >= sum[i])
            ans = max(ans, i + 2LL * ((int)(m - sum[i]) / minn));
    }

    writeln(ans);

    return 0;
}
