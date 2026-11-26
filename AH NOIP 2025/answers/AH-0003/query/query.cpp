#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll Read() {
    ll x = 0; int sig = 1; char c = getchar();
    while(!isdigit(c)) { if(c == '-') sig = -1; c = getchar(); }
    while(isdigit(c)) x = (x << 3) + (x << 1) + (c & 15), c = getchar();
    return x * sig;
}
void Write(ull x) {
    if(x > 9) Write(x / 10);
    putchar((x % 10) ^ 48);
}
const int N = 50005;
const ll inf = 1e18;
int n, q, a[N], front, back, st[N];
ll ans[N], val[N];
void Solve(int k) {
    int i; ll cur = 0; front = 1, back = 0;
    for(i = 1; i <= k; i++) cur += a[i];
    for(i = 1; i <= n; i++) {
        if(i <= n - k + 1) {
            while(front <= back && val[back] < cur) back--;
            st[++back] = i, val[back] = cur, cur -= a[i], cur += a[i + k];
        }
        while(front <= back && st[front] <= i - k) front++;
        ans[i] = max(ans[i], val[front]);
    }
}
int main() {
    freopen("query.in", "r", stdin), freopen("query.out", "w", stdout);
    int i; n = Read();
    for(i = 1; i <= n; i++) a[i] = Read();
    int q = Read();
    while(q--) {
        int l = Read(), r = Read();
        for(i = 1; i <= n; i++) ans[i] = -inf;
        for(i = l; i <= r; i++) Solve(i);
        ull t = 0;
        for(i = 1; i <= n; i++) t ^= i * ans[i];
        Write(t), putchar('\n');
    }
}