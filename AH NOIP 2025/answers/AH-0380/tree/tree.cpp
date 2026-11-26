#include<bits/stdc++.h>
using namespace std;
vector<int> g[8010];
int n,m,zs[8010],ans=0;
int zzs(int i){
    for(int j=0;j<g[i].size();j++){
        zs[i]+=zzs(g[i][j]);
    }
    zs[i]++;
    return zs[i];
}
int dfs(int i){
    int cnt=0;
    for(int j=0;j<g[i].size();j++){
        if(zs[g[i][j]]==1){
            cnt++;
        }
    }
    if(cnt==g[i].size()){
        ans+=g[i].size()+2;
        return g[i].size();
    }
    int mx=0;
    for(int j=0;j<g[i].size();j++){
        if(zs[g[i][j]]>1){
            int t=dfs(g[i][j]);
            mx=max(mx,t);
        }
    }
    ans+=mx+cnt+2;
    return mx+cnt+1;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        memset(zs,0,sizeof(zs));
        ans=0;
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        for(int i=2;i<=n;i++){
            int x;
            cin>>x;
            g[x].push_back(i);
        }
        zzs(1);
        /*for(int i=1;i<=n;i++){
            cout<<zs[i]<<" ";
        }
        cout<<endl;*/
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
