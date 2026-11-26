#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;
int ysz, T;

namespace c1{
    const int N = 15;
    struct node{
        ll w, val, id;
    }t[N], t1[N], t2[N];
    int n, m;
    ll a[N], s1[N];
    bool cmp(ll a, ll b){
        return a > b;
    }
    bool cmp1(node a, node b){
        if(a.val * b.w == b.val * a.w) return a.val > b.val;
        return a.val * b.w > b.val * a.w;
    }
    bool cmp2(node a, node b){
        return a.val > b.val;
    }
    ll calc1(){
        ll res = 0, tmp = m;
        sort(t + 1, t + n + 1, cmp1);
        /*for(int i = 1; i <= n; i++)
            cout << t[i].val << ' ' << t[i].w << '\n';*/
        for(int i = 1; i <= n; i++){
            if(tmp >= t[i].w) tmp -= t[i].w, res += t[i].val;
            if(tmp <= 0) break;
        }
        return res;
     }
     ll calc2(){
         int tot1 = 0, tot2 = 0;
         for(int i = 1; i <= n; i++){
             if(t[i].w == 1) t1[++tot1] = t[i];
             else t2[++tot2] = t[i];
         }
         sort(t1 + 1, t1 + tot1 + 1, cmp2);
         sort(t2 + 1, t2 + tot2 + 1, cmp2);
         for(int i = 1; i <= tot1; i++) s1[i] = s1[i - 1] + t1[i].val;
         ll sum = 0, res = s1[min(m, tot1)];
         /*if(tot1 == 1 && tot2 == 2){
             for(int i = 1; i <= tot1; i++){
                 cout << t1[i].w << ' ' << t1[i].val << '\n';
             }
             cout << '\n';
             for(int i = 1; i <= tot2; i++){
                 cout << t2[i].w << ' ' << t2[i].val << '\n';
             }
             cout << '\n';
             for(int i = 1; i <= tot1; i++) cout << s1[i] << ' ';
             cout << '\n';
         }*/
         for(int i = 1; i <= tot2; i++){
             sum += t2[i].val;
             if(i * 2 > m) break;
             if(m - i * 2 <= tot1) res = max(res, sum + s1[m - i * 2]);
             else res = max(res, sum + s1[tot1]);
         }
         return res;
     }
    void work(){
        while(T--){
            cin >> n >> m;
            for(int i = 1; i <= n; i++) cin >> a[i];
            int U = (1 << n) - 1, ans = 0;
            int tot;
            for(int S = 0; S <= U; S++){
                tot = 0;
                for(int j = 1; j <= n; j++){
                    if((S >> (j - 1)) & 1){
                        t[++tot] = (node){1, a[j], j};
                    }
                    else{
                        t[++tot] = (node){2, a[j], j};
                    }
                }
                /*assert(tot == n);
                for(int i = 1; i <= n; i++)
                    cout << t[i].w << ' ';
                cout << '\n';*/
                ll r2 = calc2(), r1 = calc1();
                if(r2 == r1) ans++;
                //cout << r1 << ' ' << r2 << '\n';
            }
            cout << ans << '\n';
        }
    }
}
namespace c2{
    const int N = 5e3 + 5;
    int n, m, a[N];
    ll qpow(ll a, ll b){
        ll res = 1;
        while(b){
            if(b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }
    void work(){
        while(T--){
            cin >> n >> m;
            for(int i = 1; i <= n; i++) cin >> a[i];
            cout << qpow(2, n) << '\n';
        }
    }
}

int main(){

    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);
    ios :: sync_with_stdio(false);
    cin >> ysz >> T;
    if(ysz <= 5) c1 :: work();
    else c2 :: work();

    return 0;
}
