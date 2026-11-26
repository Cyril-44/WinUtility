#include<bits/stdc++.h>
using namespace std;
int t,n,m,fa[100],d[100],ans=0,vis[100][100],cnt,dep[100];vector<int>vc[100];
void calc(int now){
    for(auto y:vc[now]){
        if(y==fa[now])continue;
        calc(y);
        for(int i=0;i<=n;i++)vis[now][i]|=vis[y][i];
    }
    vis[now][d[now]]=true;
    for(int i=0;i<=n+1;i++)if(!vis[now][i]){cnt+=i;return;}
}
void clvis(){for(int i=1;i<=n;i++)for(int j=0;j<=n;j++)vis[i][j]=false;}
void dfs(int now){
    if(now==n+1){cnt=0,calc(1),ans=max(ans,cnt);clvis();}
    else {for(int i=0;i<=n;i++)d[now]=i,dfs(now+1);}
}
void solve(){
    cin>>n>>m;ans=0;
    for(int i=2;i<=n;i++)cin>>fa[i],vc[fa[i]].push_back(i);
    dfs(1);
    cout<<ans<<'\n';
    for(int i=1;i<=n;i++)vc[i].clear();
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>t;
    while(t--)solve();
    return 0;
}
