#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

#define ll long long

const int N = 10005;
const int mod = 998244353;

ll fac[N], inv[N];
int a[N], pw[N], n, m;

ll C(int a, int b) {
    if (a < b || a < 0 || b < 0) return 0;
    return fac[a] * inv[b] % mod * inv[a - b] % mod;
}

void work() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n, [](int x, int y) {
        return x > y;
    });
    ll ans = 0;
    // for (int i = 1; i <= n; i++) {
        // printf("%d ", a[i]);
    // }
    // printf("\n");
    a[n + 1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1, k = n; j <= n; j++) {
            if (a[j] * 2 <= a[i]) break;
            int c1 = i - 1, c2 = j - i - 1;
            while (k >= j && a[j] + a[k] < a[i]) k--;
            if (k < j) break;
            if (k == n && a[i] == a[j]) continue;
            (ans += pw[n - k] * C(c1 + c2, m - 2 - c1)) %= mod;
            // printf("%d %d (%d) %lld %d %d %d\n", i, j, k, c[c1 + c2][m - 2 - c1], c1, c2, m - 2 - c1);
        }
    }
    printf("%lld\n", (pw[n] - ans + mod) % mod);
}

int main() {
    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);
    fac[0] = inv[0] = fac[1] = inv[1] = 1;
    for (int i = 2; i < N; i++) fac[i] = fac[i - 1] * i % mod;
    for (int i = 2; i < N; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    for (int i = 2; i < N; i++) inv[i] = inv[i] * inv[i - 1] % mod;
    pw[0] = 1;
    for (int i = 1; i < N; i++) pw[i] = pw[i - 1] * 2 % mod;
    int c, T;
    scanf("%d%d", &c, &T);
    while (T--) {
        work();
    }
    return 0;
}