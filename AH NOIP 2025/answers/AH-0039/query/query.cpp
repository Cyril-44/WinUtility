#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

#define ll long long
#define ull unsigned long long

const int N = 50005;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int a[N], n, que[N], t, h;
ll s[N], ans[N], tmp[N];

void work1() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l == r) {
            for (int i = 1; i <= n; i++) tmp[i] = -INF, ans[i] = -INF;
            for (int i = 1; i + r - 1 <= n; i++) {
                tmp[i] = s[i + r - 1] - s[i - 1];
            }
            t = -1; h = 0;
            for (int i = 1; i <= n; i++) {
                while (h <= t && i - que[h] >= r) h++;
                while (h <= t && tmp[que[t]] <= tmp[i]) t--;
                que[++t] = i;
                ans[i] = tmp[que[h]];
            }
            ull x = 0;
            for (int i = 1; i <= n; i++) {
                ull now = ans[i];
                x ^= now * i;
            }
            printf("%llu\n", x);
            continue;
        }
        for (int i = 1; i <= n; i++) ans[i] = -INF;
        for (int i = 1; i <= n; i++) {
            ll mx = -INF;
            for (int j = max(1, i - r + 1); j <= i; j++) {
                if (i - j + 1 >= l) {
                    mx = max(mx, s[i] - s[j - 1]);
                }
                ans[j] = max(ans[j], mx);
            }
        }
        ull x = 0;
        for (int i = 1; i <= n; i++) {
            ull now = ans[i];
            x ^= now * i;
        }
        printf("%llu\n", x);
    }
}

int main() {
    freopen("query.in", "r", stdin);
    freopen("query.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s[i] = a[i] + s[i - 1];
    }
    work1();
    return 0;
}