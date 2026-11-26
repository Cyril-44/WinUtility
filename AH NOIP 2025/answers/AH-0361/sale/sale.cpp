#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long c,t,n,m,dp[10010],ans;
struct node{long long w,t,id;}nd[10010],ls[10010];
bool cmp(node x,node y){
    if(x.w*y.t!=y.w*x.t)return 1ll*y.w*x.t<1ll*x.w*y.t;
    else if(x.w!=y.w)return x.w>y.w;
    else return x.id<y.id;
}
void initget(){
    cin>>n>>m;
    for(long long i=1;i<=n;i++)cin>>nd[i].w,nd[i].id=i;

}
void dfs(long long t){
    if(t==n+1){
        long long cnt=0,cost=0;
        for(long long i=1;i<=n;i++)for(long long j=m;j>=nd[i].t;j--)dp[j]=max(dp[j],dp[j-nd[i].t]+nd[i].w);
        for(long long i=1;i<=n;i++)ls[i]=nd[i];
        sort(ls+1,ls+n+1,cmp);
        for(long long i=1;i<=n;i++){
            if(cost+ls[i].t<=m){
                cost+=ls[i].t;
                cnt+=ls[i].w;
            }
        }
        if(cnt==dp[m])++ans;
        if(cnt!=dp[m]){
            for(int i=1;i<=n;i++){
                cout<<ls[i].id<<' '<<ls[i].t<<' '<<ls[i].w<<'w';
            }
        }
        for(long long i=0;i<=m;i++)dp[i]=0;
        return;
    }
    nd[t].t=1;
    dfs(t+1);
    nd[t].t=2;
    dfs(t+1);
}
/*
*/
void solve(){
    for(int i=1;i<=n;i++)(ans*=2)%=mod;
    for(int i=1;i<=n;i++)nd[i].t=2;
        long long cnt=0,cost=0;
        for(long long i=1;i<=n;i++)for(long long j=m;j>=nd[i].t;j--)dp[j]=max(dp[j],dp[j-nd[i].t]+nd[i].w);
        for(long long i=1;i<=n;i++)ls[i]=nd[i];
        sort(ls+1,ls+n+1,cmp);
        for(long long i=1;i<=n;i++){
            //cout<<ls[i].id<<' '<<ls[i].t<<' '<<ls[i].w<<'w';
            if(cost+ls[i].t<=m){
                cost+=ls[i].t;
                cnt+=ls[i].w;
            }
        }
        if(cnt!=dp[m])(ans=(ans+mod-1)%mod);
        for(int i=0;i<=m;i++)dp[i]=0;
}
int main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        initget();
        if(n<=10){
            dfs(1);
            cout<<ans<<'\n';
        }
        else if(m==2*n-1){
            ans=1;
            solve();
            cout<<ans<<'\n';
        }
        else if(c==18){
            ans=1;
            for(int i=1;i<=n;i++)(ans*=2)%=mod;;
            cout<<ans<<'\n';
        }
    }
    return 0;
}
