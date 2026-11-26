#include <bits/stdc++.h>
using namespace std;

const int N = 50005;

long long n, q, a[N], s[N];
unsigned long long ans;

int main() {
    freopen("query.in", "r", stdin);
    freopen("query.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        s[i] = s[i-1] + a[i];
    }
    scanf("%lld", &q);
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        for (int i = 1; i <= n; ++i) {
            long long maxn = -0x7fffffff;
            for (int len = l; len <= r; ++len) {
                for (int j = max(i-len+1, 1); j <= i && (j+len-1)<=n; ++j) {
                    maxn = max(maxn, s[j+len-1]-s[j-1]);
                }
            }
            ans ^= i*maxn;
        }
        printf("%llu\n", ans);
        ans = 0;
    }

    return 0;
}
