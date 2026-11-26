#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

struct Candy {
    long long x, y;
    bool operator<(const Candy& rhs) const {
        return x < rhs.x;
    }
};

long long n, m, minn = 0x3f3f3f3f3f3f3f3f;
Candy a[N];
long long b[N];

int main() {
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);

    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld%lld", &a[i].x, &a[i].y);
        minn = min(minn, a[i].x+a[i].y);
    }
    sort(a+1, a+1+n);
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        long long x = a[i].x;
        if (x*2 <= minn) {
            ++ans;
            m -= x;
        } else {
            break;
        }
    }
    ans += m/minn*2;
    m %= minn;
    for (int i = 1; i <= n; ++i) {
        long long x = a[i].x;
        long long y = a[i].y;
        if (x*2 <= minn) {
            b[i] = y;
        } else {
            b[i] = x;
        }
    }
    sort(b+1, b+1+n);
    if (b[1]<=m) {
        m -= b[1];
        ++ans;
    }
    for (int i = n; i >= 1; --i) {
        if (a[i].x*2 <= minn) {
            if (a[i].x+m >= minn) {
                ++ans;
                m = a[i].x+m-minn;
            }
        }
    }
    printf("%lld\n", ans);

    return 0;
}
