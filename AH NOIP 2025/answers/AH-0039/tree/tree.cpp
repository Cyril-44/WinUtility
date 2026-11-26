#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long

const int N = 8005;

int T, n, m;
int dp[N][10005], tmp[10005], sz[N];
vector<int> e[N];

void work1() {
    // printf()
    for (int i = n; i >= 1; i--) {
        memset(tmp, -0x3f, sizeof(tmp));
        memset(dp[i], -0x3f, sizeof(dp[i]));
        dp[i][0] = 0;
        for (int j : e[i]) {
            for (int u = (1 << n) - 1; u >= 0; u--) {
                if (dp[i][u] < 0) continue;
                for (int v = 0; v < (1 << n); v++) {
                    tmp[u | v] = max(tmp[u | v], dp[i][u] + dp[j][v]);
                }
            }
            memcpy(dp[i], tmp, sizeof(dp[i]));
        }
        for (int u = (1 << n) - 1; u >= 0; u--) {
            for (int k = 0; k < n; k++) {
                dp[i][u | (1 << k)] = max(dp[i][u | (1 << k)], dp[i][u]);
            }
        }
        for (int u = (1 << n) - 1; u >= 0; u--) {
            for (int k = 0; k <= n; k++) {
                if (!(u & (1 << k))) {
                    dp[i][u] += k;
                    break;
                }
            }
            // printf("!!: %d %d: %d\n", i, u, dp[i][u]);
        }
    }
    int ans = 0;
    for (int u = 0; u < (1 << n); u++) {
        ans = max(ans, dp[1][u]);
    }
    printf("%d\n", ans);
}

void work2() {
    if (m == 1) {
        printf("%d\n", n + 1);
        return;
    }
    int ans = 0;
    for (int i = n; i >= 2; i--) {
        sz[i] = 1;
        if (e[i].size()) ans++;
        for (int j : e[i]) {
            sz[i] += sz[j];
        }
    }
    int mx = 0;
    for (int v : e[1]) {
        mx = max(mx, sz[v]);
    }
    ans += mx + n;
    printf("%d\n", ans);
}

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            e[i].clear();
        }
        for (int i = 2; i <= n; i++) {
            int x;
            scanf("%d", &x);
            e[x].push_back(i);
        }
        if (m <= 2) work2();
        else work1();
    }
    return 0;
}