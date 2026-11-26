#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=8010;
int t,n,m,ans;
int num[N],fa[N],l[N];
vector<int> G[N];
int dfs(int u){
    if(!G[u].size()) return num[u]=1;
    int sum=0;
    for(int i=0;i<G[u].size();i++)
        sum+=dfs(G[u][i]);
    return num[u]=sum+1;
}
void dfs2(int u,int dep){
    l[u]=max(dep,l[u]);
    if(u==1) return;
    dfs2(fa[u],dep+1);
}
void solve(int u,int dep){
    if(!G[u].size()){
        ans++;
        return;
    }
    int maxn=0,sum=0,cnt;
    for(int i=0;i<G[u].size();i++){
        if(num[G[u][i]]>maxn||(num[G[u][i]]==maxn&&l[G[u][i]]>l[cnt])){
            maxn=num[G[u][i]];
            cnt=G[u][i];
        }
    }
    for(int i=0;i<G[u].size();i++){
        if(G[u][i]==cnt) continue;
        if(l[G[u][i]]>dep){
            solve(G[u][i],1);
            continue;
        }
        sum+=num[G[u][i]];
    }
    ans+=sum+num[cnt]+1;
    solve(cnt,dep+1);
}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=n;i++) num[i]=0,fa[i]=0,l[i]=0;
        cin>>n>>m;
        for(int i=2;i<=n;i++){
            int u;
            cin>>u;
            G[u].push_back(i);
            fa[i]=u;
        }
        num[1]=dfs(1);
        for(int i=1;i<=n;i++) if(!G[i].size()) dfs2(i,1);
        solve(1,1);
        cout<<ans<<"\n";
    }
    return 0;
}
//noip rp++
//duo gei wo yi dian fen ba,qiu qiu le
