#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =1e5+5;
int n;
ll m;
ll p[N][2];
ll s[N];
struct res{ll v; int idx;};
res max1(){
    ll m = p[0][0];int idx = 0;
    for (int i = 1; i < n; i++){
        if (p[i][0] < m){
            m = p[i][0]; idx = i;
        }
    }
    return {m, idx};
}
res max2(){
    ll m = s[0];int idx = 0;
    for (int i = 1; i < n; i++){
        if (s[i] < m){
            m = s[i]; idx = i;
        }
    }
    return {m, idx};
}
int main(){
    freopen("candy.in", "r", stdin);
    freopen("candy.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> p[i][0] >> p[i][1];
        s[i] = p[i][0] + p[i][1];
    }
    ll cnt = 0;
    while(1){
        res a = max1(), b = max2();
        // if (m < a.v) break;
        // if (m >= b.v && b.v < s[a.idx]){
        //     cnt += m / b.v * 2;
        //     m %= b.v;
        // } else {
        //     swap(p[a.idx][0], p[a.idx][1]);
        //     cnt++;
        //     m -= a.v;
        // }
        // printf("%lld %lld %d %d\n", a.v, b.v, a.idx, b.idx);
        if (m < a.v) break;
        if (a.v * 2 < b.v || m < b.v){
            swap(p[a.idx][0], p[a.idx][1]);
            cnt++;
            m -= a.v;
        } else {
            cnt += m / b.v * 2;
            m %= b.v;
        }
    }
    cout << cnt << '\n';
    //  cerr << m << '\n';
    return 0;
}