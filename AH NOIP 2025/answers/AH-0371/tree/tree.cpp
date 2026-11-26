#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m,ans,fa[10005],dep[10005],cnt[10005],num[10005];
int num_edge,head[10005];
vector<int> ve[805];
bool lf[10005];
struct node{
    int next,to;
}edge[10005];
inline void add_edge(int from,int to){
    edge[++num_edge].next=head[from];
    edge[num_edge].to=to;
    head[from]=num_edge;
}
void dfs(int u){
    dep[u]=dep[fa[u]]+1;
    ve[dep[u]].push_back(u);
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(v==fa[u]) continue;
        dfs(v);
    }
}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=2;i<=n;i++){
            cin>>fa[i];
            add_edge(i,fa[i]);
            add_edge(fa[i],i);
        }
        dfs(1);
        for(int i=m+1;i;i--){
            for(int j=0;j<ve[i].size();j++){
                int u=ve[i][j];
                memset(cnt,0,sizeof(cnt));
                while(u){
                    cnt[num[u]]++;
                    u=fa[u];
                }
                int maxx=0;
                for(int k=0;k<=n;k++){
                    if(cnt[k]>cnt[maxx]){
                        maxx=k;
                    }
                }
                ans+=cnt[maxx];
                u=ve[i][j];
                while(u){
                    if(num[u]==maxx) num[u]++;
                    u=fa[u];
                }
//                cout<<ve[i][j]<<' '<<maxx<<' '<<cnt[maxx]<<'\n';
            }
            ve[i].clear();
        }
        cout<<ans<<'\n';
        ans=0;
        num_edge=0;
        memset(head,0,sizeof(head));
        memset(num,0,sizeof(num));
    }
    return 0;
}
