#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <numeric>
#include <queue>
constexpr int N = 3005;
int a[N];
long long s[N], f[N], g[N][N];
int main() {
    freopen("query.in", "r", stdin);
    freopen("query.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        s[i] = s[i-1] + a[i];
    for (int len = 1; len <= n; len++) {
        for (int i = len; i <= n; i++)
            f[i] = s[i] - s[i - len];
        std::priority_queue<std::pair<long long, int>> pq;
        int ptr = len;
        for (int i = 1; i <= n; i++) {
            // fprintf(stderr, "%d\n", ptr);
            while (ptr < i + len && ptr <= n) pq.emplace(f[ptr], ptr), ++ptr;
            while (!pq.empty() && pq.top().second < i) pq.pop();
            // if (pq.empty()) fprintf(stderr,"!!!!%d\n", i);
            g[i][len] = pq.top().first;
            // fprintf(stderr, "%lld %d\n", pq.top().first, pq.top().second);
        }
    }
    int q;
    scanf("%d", &q);
    for (int l, r; q--; ) {
        scanf("%d%d", &l, &r);
        unsigned long long res = 0;
        for (int i = 1; i <= n; i++) {
            long long ans = -(1ll << 62);
            for (int j = l; j <= r; j++)
                ans = std::max(ans, g[i][j]);
            res ^= (unsigned long long)ans * i;
        }
        printf("%llu\n", res);
    }
    return 0;
}