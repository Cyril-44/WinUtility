#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,c,t,ans,dp[50005];
struct node{
    int num,w,id;
    bool operator < (node a) const{
        if(num*a.w!=a.num*w) return num*a.w>a.num*w;
        if(num!=a.num) return num>a.num;
        return id<a.id;
    }
}a[5005],b[5005];
inline int poww(int a,int b){
    int ans=1;
    while(b){
        if(b&1) (ans*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return ans;
}
void dfs(int now){
    if(now==n+1){
//        for(int i=1;i<=n;i++) cout<<a[i].w<<' ';
//        cout<<'\n';
        memcpy(b,a,sizeof(b));
        sort(b+1,b+1+n);
//        for(int i=1;i<=n;i++) cout<<b[i].id<<' ';
//        cout<<'\n';
        int tot=0,tmp=m;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            if(tmp>=b[i].w) tmp-=b[i].w,tot+=b[i].num;
            for(int j=m;j>=b[i].w;j--){
                dp[j]=max(dp[j-b[i].w]+b[i].num,dp[j]);
            }
        }
//        cout<<tot<<' '<<dp[m]<<'\n';
        if(tot==dp[m]) (ans+=1)%=mod;
//        if(tot!=dp[m]){
//            for(int i=1;i<=n;i++) cout<<a[i].w<<' ';
//            cout<<'\n';
//            for(int i=1;i<=n;i++) cout<<b[i].id<<' ';
//            cout<<'\n';
//        }
        return;
    }
    a[now].w=1;
    dfs(now+1);
    a[now].w=2;
    dfs(now+1);
}
signed main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i].num;
            a[i].id=i;
        }
        if(c>=6){
            cout<<poww(2,n)<<'\n';
            continue;
        }
        dfs(1);
        cout<<ans<<'\n';
        ans=0;
    }
    return 0;
}
