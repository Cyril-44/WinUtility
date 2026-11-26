#include <stdio.h>
#include <algorithm>
#include <limits>
constexpr int N = 100005;
struct Node {
    int od, ev;
    inline bool operator<(const Node &rhs) const {
        return od < rhs.od;
    }
} a[N];
int main() {
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    int n;
    long long m;
    scanf("%d%lld", &n, &m);
    int mn2 = std::numeric_limits<int>::max();
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i].od, &a[i].ev);
        mn2 = std::min(mn2, a[i].od + a[i].ev);
    }
    std::sort(a+1, a+1 + n);
    long long cnt = m / mn2;
    long long ans = cnt * 2, now = ans, cost = cnt * mn2;
    for (int i = 1; i <= n; i++) {
        if (a[i].od > mn2) break;
        if (cost + a[i].od > m) cost -= mn2, now -= 2;
        cost += a[i].od;
        now++;
        ans = std::max(ans, now);
    }
    printf("%lld\n", ans);
    return 0;
}