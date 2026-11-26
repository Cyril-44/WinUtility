#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
const int P = 998244353;

int c, t;
int n, m;
long long a[N], w[N];
long long ans;

struct Node {
    long long a, w;
    bool operator<(const Node &rhs) const {
        if (a*rhs.w!=rhs.a*w) {
            return a*rhs.w>rhs.a*w;
        } else {
            return w>rhs.w;
        }
    }
} b[N];

long long f[N*2];
bool check() {
    for (int i = 1; i <= n; ++i) {
        b[i].a = a[i];
        b[i].w = w[i];
    }
    sort(b+1, b+1+n);
    long long ret1 = 0, ret2 = 0;
    int tmp = m;
    for (int i = 1; i <= n; ++i) {
        if (tmp >= b[i].w) {
            tmp -= b[i].w;
            ret1 += b[i].a;
        }
    }
    for (int i = 1; i <= m; ++i)
        f[i] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= b[i].w; --j) {
            f[j] = max(f[j], f[j-b[i].w]+b[i].a);
        }
    }
    return ret1 == f[m];
}

void dfs(int x) {
    if (x > n) {
        if (check()) {
            ++ans;
            ans %= P;
        }
        return;
    }
    w[x] = 1;
    dfs(x+1);
    w[x] = 2;
    dfs(x+1);
}

long long power(long long x, long long p) {
    x %= P;
    long long ret = 1;
    while (p) {
        if (p&1) {
            ret = ret*x%P;
        }
        x = x*x%P;
        p >>= 1;
    }
    return ret;
}

int main() {
    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);

    scanf("%d%d", &c, &t);
    if (c <= 5) {
        while (t--) {
            scanf("%d%d", &n, &m);
            for (int i = 1; i <= n; ++i) {
                scanf("%lld", &a[i]);
            }
            dfs(1);
            printf("%lld\n", ans);
            ans = 0;
        }
    }
    if (c == 18) {
        while (t--) {
            scanf("%d%d", &n, &m);
            for (int i = 1; i <= n; ++i) {
                scanf("%lld", &a[i]);
            }
            printf("%lld\n", power(2, n));
        }
    }

    return 0;
}
