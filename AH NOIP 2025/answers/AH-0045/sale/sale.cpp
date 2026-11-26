#include <bits/stdc++.h>
using namespace std;
#define int long long
#define len 5050
#define mod 998244353
int c, t;
int n, m, a[len], f[len], ans;
int jc[len];
struct rec{int x, id; double f;} gd[len];
bool cmp(const rec& a, const rec& b) {
    if(a.f!=b.f) return a.f>b.f;
    if(a.x!=b.x) return a.x>b.x;
    return a.id>b.id;
}
void dfs(int x) {
    if(x==n+1) {
        for(int i=1;i<=n;i++) gd[i].x=f[i], gd[i].id=i, gd[i].f=1.0*a[i]/gd[i].x;
        sort(gd+1, gd+n+1, cmp);
        double f2=0, t1=0, t2=0, tm=m;
        for(int i=1;i<=n;i++) {
            if(tm==1&&gd[i].x==2&&f2==0) f2=gd[i].f*2;
            if(tm>=gd[i].x) {
                tm-=gd[i].x;
                if(gd[i].x==1) {
                    if(f2==0) t1=gd[i].f;
                    else t2=gd[i].f;
                }
            }
        }
        if(f2) {
            int flag=0;
            if(t1==0);
            else if(t2!=0) {if(t1+t2<f2) ans--, flag=1;}
            else {if(t1<f2) ans--, flag=1;}
        }
        return;
    }
    f[x]=1, dfs(x+1), f[x]=2, dfs(x+1);
    return;
}
void solve1() { //1~5
    ans=(1<<n);
    if(m!=1) dfs(1);
    cout<<ans<<endl;
    return;
}
void solve2() {
    if(n<=5) {solve1();return;}
    sort(a+1,a+n+1), reverse(a+1, a+n+1);
    for(int i=2;i<=n;i++) if(2*a[i]>a[1]) ans++;
    for(int i=2;i<=n;i++) {
        if(a[i]*2<=a[1]) continue;
        for(int j=i+1;j<=n;j++)
            if(a[i]+a[j]<a[1]) ans+=jc[n-j], ans%=mod;
    }
    for(int i=3;i<n;i++) if(a[i]*2<=a[2]&&a[1]+a[i+1]<a[2]) ans+=jc[n-i-1], ans%=mod;
    ans%=mod;
    cout<<(jc[n]+mod-ans)%mod<<endl;
    return;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);
    cin>>c>>t;
    if(c<=5) {
        while(t--) {
            cin>>n>>m;
            for(int i=1;i<=n;i++) cin>>a[i];
            solve1();
        }
    }
    else if(c==7||c==8||c==9||c==14||c==15) {
        jc[0]=1;
        for(int i=1;i<len;i++) jc[i]=jc[i-1]*2%mod;
        while(t--) {
            cin>>n>>m;
            for(int i=1;i<=n;i++) cin>>a[i];
            solve2();
        }
    }
    else if(c==18) {
        jc[0]=1;
        for(int i=1;i<len;i++) jc[i]=jc[i-1]*2%mod;
        while(t--) {
            cin>>n>>m;
            for(int i=1;i<=n;i++) cin>>a[i];
            cout<<jc[n]<<endl;
        }
    }
    return 0;
}
