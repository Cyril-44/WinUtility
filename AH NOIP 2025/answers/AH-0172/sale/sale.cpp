#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define local
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
#define pll pair<ll,ll>
const int N = 5005;
const ll Mod = 998244353;
void solve1(){
    int n,m;
    cin>>n>>m;
    vector<ll>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m == 2){
        ll ans = pows(2,n);
    }
}
int ans[N];
ll val[N];
bool cmp(pii a,pii b){
    if((double)a.fi / (double)ans[a.se] == (double)b.fi / (double)ans[b.se]){
        return a.fi > b.fi;
    }
    return (double)a.fi / (double)ans[a.se] > (double)b.fi / (double)ans[b.se];
}
ll cnt = 0;
void dfs(int x,int n,int m){
    if(x == n+1){
        vector<pii>a(n+1);
        for(int i=1;i<=n;i++){
            a[i] = {val[i],i};
        }
        sort(a.begin()+1,a.end(),cmp);
        vector<vector<ll> >dp(n+1,vector<ll>(m+1,0));
        for(int i=1;i<=n;i++){
            if(ans[i] == 2){
                dp[i][1] = dp[i-1][1];
            }else{
                dp[i][1] = max(dp[i-1][1],dp[i-1][0] + val[i]);
            }
            for(int j=2;j<=m;j++){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-ans[i]] + val[i]);
            }
        }
        ll Max = dp[n][m];
        ll ans2 = 0,el = m;
        for(int i=1;i<=n;i++){
            if(el >= ans[a[i].se]){
                el -= ans[a[i].se];
                ans2 += a[i].fi;
            }
        }
        //cout<<Max<<" "<<ans2<<endl;
        if(Max == ans2){
            cnt ++;
        }
        return ;
    }
    ans[x] = 1;
    dfs(x+1,n,m);
    ans[x] = 2;
    dfs(x+1,n,m);
}
void solve2(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    dfs(1,n,m);
    
    cout<<cnt<<endl;
    cnt = 0;
}
int main(){
    #ifdef local
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    fac[0] = 1;
    for(int i=1;i<=5005;i++){
        fac[i] = fac[i-1] * i;
        fac[i] %= Mod;
    }
    for(int i=1;i<=5005;i++){
        ifac[i] = pows(fac[i],Mod-2);
    }
    int c,T;
    cin>>c>>T;
    while(T--){
        solve2();
    }
    return 0*114514*0;
}