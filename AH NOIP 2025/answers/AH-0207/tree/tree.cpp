#include<bits/stdc++.h>
using namespace std;
long long t,n,m,x,tot,a[9010],ans,f[9010];
vector<long long> g[9010];
void dfs(long long now){
    if(now>n){
        return;
    }
    if(a[now]>n){
        a[now]=tot;
        tot++;
    }
    long long len=g[now].size();
    for(int i=0;i<len;i++){
        dfs(g[now][i]);
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        ans=0;
        scanf("%lld%lld",&n,&m);
        for(int i=2;i<=n;i++){
            scanf("%lld",&x);
            g[x].push_back(i);
        }
        tot=0;
        memset(a,0x3f,sizeof(a));
        dfs(1);
        // for(int i=1;i<=n;i++){
        //     printf("%lld ",a[i]);
        // }
        for(int i=1;i<=n;i++){
            memset(f,0,sizeof(f));
            long long len=g[i].size();
            for(int j=0;j<len;j++){
                long long y=g[i][j];
                f[a[y]]++;
            }
            for(int j=1;j<=n+1;j++){
                if(f[j]==0){
                    ans+=j;
                    break;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
