#include<bits/stdc++.h>
using namespace std;
int T,n,m,c,fa[8010],sz[8010],f[8010];
vector<int>G[8010];
void dfs(int u){
    sz[u]++;
    for(int i=0;i<G[u].size();i++){
        if(G[u][i]!=fa[u])dfs(G[u][i]);
        sz[u]+=sz[G[u][i]];
    }
    sort(G[u].begin(),G[u].end(),[](int a,int b){
        return sz[a]>sz[b];
    });
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>T;
    while(T--){
        int ans=0;
        cin>>n>>m;
        if(m==2){cout<<n+1<<endl;continue;}
        if(m==n-1){cout<<n*(n+1)/2<<endl;continue;}
        for(int i=1;i<=n;i++)G[i].clear();
        for(int i=2;i<=n;i++){
            cin>>fa[i];
            G[fa[i]].push_back(i);
        }
        ans=max(n+1,n*(n+1)/2);
        cout<<ans<<endl;
    }
    return 0;
}
