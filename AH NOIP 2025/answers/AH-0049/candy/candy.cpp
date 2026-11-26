#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 5;
struct node{
    ll a, b;
}a[N];
int n;
ll m;

bool cmp1(node p, node q){
    return p.a + p.b < q.a + q.b;
}
bool cmp2(node p, node q){
    return p.a < q.a;
}

int main(){

    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    ios :: sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i].a >> a[i].b;
    sort(a + 1, a + n + 1, cmp1);
    ll mins = a[1].a + a[1].b;
    sort(a + 1, a + n + 1, cmp2);
    ll ans = m / mins * 2, sum = 0;
    for(int i = 1; i <= n; i++){
        sum += a[i].a;
        if(sum > m) break;
        ans = max(ans, (m - sum) / mins * 2 + i);
    }
    cout << ans << '\n';

    return 0;
}
