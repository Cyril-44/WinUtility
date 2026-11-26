#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll Read() {
    ll x = 0; int sig = 1; char c = getchar();
    while(!isdigit(c)) { if(c == '-') sig = -1; c = getchar(); }
    while(isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
    return x * sig;
}
void Write(ll x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) Write(x / 10);
    putchar((x % 10) ^ 48);
}
const int N = 100005;
const ll inf = 1e18;
int n;
ll m, x[N], y[N];
int main() {
    freopen("candy.in", "r", stdin), freopen("candy.out", "w", stdout);
    int i; ll smin = inf, ans = 0, res = ans, cnt = 0; n = Read(), m = Read();
    for(i = 1; i <= n; i++) {
        x[i] = Read(), y[i] = Read();
        smin = min(smin, x[i] + y[i]);
    }
    cnt = ans = m / smin, ans *= 2, m %= smin, res = ans, sort(x + 1, x + n + 1);
    for(i = 1; i <= n; i++) {
        ll t = m >= x[i] ? 0 : (x[i] - m + smin - 1) / smin;
        if(cnt < t) break;
        cnt -= t, res -= t * 2, res++, m += t * smin - x[i], ans = max(ans, res);
    }
    Write(ans);
}