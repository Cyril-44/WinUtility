#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

#define ll long long

const int N = 100005;

struct Node {
    int a, b;
}p[N];

bool cmp(Node x, Node y) {
    return x.a < y.a;
}

int main() {
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    int n; ll m;
    scanf("%d%lld", &n, &m);
    int mn = 2000000000;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &p[i].a, &p[i].b);
        mn = min(mn, p[i].a + p[i].b);
    }
    sort(p + 1, p + 1 + n, cmp);
    ll sum = 0, ans = m / mn * 2;
    for (int i = 1; i <= n; i++) {
        sum += p[i].a;
        ans = max(ans, (m - sum) / mn * 2 + i);
    }
    printf("%lld\n", ans);
    return 0;
}