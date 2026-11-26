#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3+5, M = 998244353;
int c, T, n, m;
ll f[N*2];
struct Candy{
    ll x, w, id;
    bool operator <(const Candy &tmp){
        if(x * tmp.w != tmp.x * w)return x * tmp.w > tmp.x * w;
        if(x != tmp.x)return x > tmp.x;
        return id < tmp.id;
    }
}a[N];
inline ll read(){
    ll s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=(s<<3)+(s<<1)+(c^48);c=getchar();}
    return s*f;
}
ll Pow(ll x, int t){
    ll ans = 1;
    while(t){
        if(t&1)ans = ans * x % M;
        t >>= 1;
        x = x * x % M;
    }
    return ans;
}
bool cmp(Candy a, Candy b){
    return a.id < b.id;
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    c = read(), T = read();
    while(T--){
        n = read(), m = read();
        for(int i=1;i<=n;i++)a[i].x = read(), a[i].id = i;
        if(c == 18){
            cout << Pow(2, n) << endl;
            continue;
        }
        if(0 <= c && c <= 5){
            ll cnt = 0;
            for(int d=0;d<(1<<n);d++){
                for(int i=1;i<=n;i++){
                    if(d&(1<<(i-1))){
                        a[i].w = 1;
                    }else{
                        a[i].w = 2;
                    }
                }
                int tmp = m;
                ll sum = 0, maxn = 0;
                sort(a+1, a+n+1);
                for(int i=1;i<=n;i++){
//                    cout << "# " << a[i].x << ' ' <<a[i].w << ' ' << a[i].x *1.0 / a[i].w << endl;
                    if(tmp >= a[i].w){
                        tmp -= a[i].w;
                        sum += a[i].x;
                    }
                }
                for(int i=1;i<=n;i++){
                    for(int j=m-a[i].w;j>=0;j--){
                        if(j==0 || f[j]){
                            f[j+a[i].w] = max(f[j+a[i].w], f[j]+a[i].x);
                            maxn = max(maxn, f[j+a[i].w]);
                        }
                    }
                }
                if(sum == maxn)cnt++;
//                cout << d << ' ' << sum << ' ' << maxn << endl;
                memset(f, 0, sizeof f);
                sort(a+1, a+n+1, cmp);
            }
            cout << cnt << endl;
            continue;
        }
    }
    return 0;
}
// 10:50 24pts
