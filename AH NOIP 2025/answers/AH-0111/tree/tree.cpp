#include <bits/stdc++.h>
using namespace std;

int t, n, m;
vector<int> G[25];
int v[25], maxn = -1;
int lg2[10000];

int f[25], ret;
void fun(int x) {
    for (auto y : G[x]) {
		fun(y);
        f[x] &= f[y];
    }
    f[x] &= ~(1<<v[x]);
    ret += lg2[f[x]&(-f[x])];
}

void dfs(int x) {
    if (x > n) {
        for (int i = 1; i <= n; ++i) {
            f[i] = 0x7fffffff;
        }
        fun(1);
        if (ret > maxn) {
            maxn = ret;
        }
        ret = 0;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 3; ++j) {
            v[i] = j;
            dfs(x+1);
        }
    }
}

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    for (int i = 1; i <= 13; ++i) {
        int now = 1;
        for (int j = 1; j <= i; ++j) {
            now *= 2;
        }
        lg2[now] = i;
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 2; i <= n; ++i) {
            int x;
            scanf("%d", &x);
            G[x].push_back(i);
        }
        dfs(1);
        printf("%d\n", maxn);
        maxn = -1;
    }

    return 0;
}
