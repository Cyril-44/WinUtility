#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,m;
const int N=5005,P=998244353;
int a[N];
int qpow(int base,int exp){
    int ret=1;
    while(exp){
        if(exp&1) ret=ret*base%P;
        base=base*base%P;
        exp>>=1;
    }
    return ret;
}
int w[N];
int ans,maxx;
struct node{ int v,vo,id;} b[N];
bool cmpv(node x,node y){
    if(x.v!=y.v) return x.v>y.v;
    if(x.vo!=y.vo) return x.vo>y.vo;
    return x.id<y.id;
}
int dp[N<<1];
void dfs(int x,int v){
    w[x]=v;
    if(x==n){
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;i++) {
            if(w[i]==2) b[i].v=a[i];
            else b[i].v=a[i]*2;
            b[i].vo=a[i];
            b[i].id=i;
        }
        sort(b+1,b+n+1,cmpv);
    //    for(int i=1;i<=n;i++) cout<<w[b[i].id]<<' '; cout<<'\n';
      //  for(int i=1;i<=n;i++) cout<<b[i].vo<<' '; cout<<'\n';
        for(int i=1;i<=n;i++)
          for(int j=m;j>=w[b[i].id];j--){
            dp[j]=max(dp[j],dp[j-w[b[i].id]]+b[i].vo);
          }
        int sum=dp[m];
      //  cout<<sum<<' ';

        int tmp=0,r=m;
        for(int i=1;i<=n;i++)
            if(r>=w[b[i].id]) tmp+=b[i].vo,r-=w[b[i].id];
        //cout<<tmp<<'\n';
        if(tmp==sum) ans++;

        return ;
    }
    dfs(x+1,1);
    dfs(x+1,2);
}
void init(){
    memset(a,0,sizeof a);
    memset(w,0,sizeof w);
    ans=0; maxx=-1;
}
void solve(){
    init();
    cin>>n>>m;
    bool A=true;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++) A&=(a[i]==a[i-1]);
    if(A) cout<<qpow(2,n)<<'\n';
    else{
        dfs(0,1);
        cout<<ans<<'\n';
    }
}
signed main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    cin>>c>>T;
    while(T--) solve();
}
