#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,MOD=998244353;
int c,t,n,m,ans,maxn;
int a[N];
int flag[N];
bool vis[N];
struct Node{
    double w;
    int a,id,x;
}f[N];
bool cmp(const Node &x,const Node &y){
    if(x.w!=y.w) return x.w>y.w;
    if(x.a!=y.a) return x.a>y.a;
    return x.id<y.id;
}
inline void searchmax(int i,int cost,int value){
    if(i>n){
        maxn=max(maxn,value);
        return;
    }
    if(vis[i]){
        searchmax(i+1,cost,value);
        return;
    }
    if(f[i].x+cost<=m) searchmax(i+1,f[i].x+cost,value+f[i].a);
    searchmax(i+1,cost,value);
    return;
}

inline bool check(){
    memset(vis,0,sizeof(vis));
    maxn=0;
    int cost=0;
    for(int i=1;i<=n;i++){
        f[i].w=a[i]*1.0/flag[i];
        f[i].a=a[i];f[i].id=i;f[i].x=flag[i];
    }
    sort(f+1,f+n+1,cmp);
    int p=1,value=0;
    for(int i=1;i<=n;i++){
        if(cost+f[i].x<=m){
            value+=f[i].a;
            cost+=f[i].x;
            vis[i]=true;
        }
    }
    searchmax(1,0,0);
    //cout<<maxn<<" "<<value<<" "<<endl;
   // for(int i=1;i<=n;i++) cout<<flag[i]<<" "<<f[i].id<<" "<<f[i].a<<" "<<f[i].x<<" "<<f[i].w<<" "<<vis[i]<<" "<<endl;
    //cout<<endl;
    if(value>=maxn) return true;
    return false;

}
inline void dfs(int cur){
    if(cur>n){
        if(check()) ans++;
        ans%=MOD;
        return;
    }
    flag[cur]=1;
    dfs(cur+1);
    flag[cur]=2;
    dfs(cur+1);
}
signed main(){
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        ans=0;
        scanf("%lld%lld",&n,&m);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        dfs(1);
        printf("%lld\n",ans);
    }

    return 0;
}
