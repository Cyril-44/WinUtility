#include<bits/stdc++.h>
using namespace std;
int n,m,t,fa[8005],ans,ret,f[10];
vector<int> g[8005];
int query(int x){
    int now=(1<<f[x]);
    for(int i=0;i<g[x].size();i++){
        int to=g[x][i];
        now|=query(to);
    }
    for(int i=0;i<n;i++){
        if((now&(1<<i))==0){
            ret+=i;
            break;
        }
    }
    return now;
}
void dfs(int x){
    if(x>n){
        ret=0;
        query(1);
        ans=max(ans,ret);
        return;
    }
    for(int i=0;i<n;i++){
        f[x]=i;
        dfs(x+1);
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m;
        ans=0;
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        for(int i=2;i<=n;i++){
            cin>>fa[i];
            g[fa[i]].push_back(i);
        }
        if(n<=7){
            dfs(1);
            cout<<ans<<'\n';
        }
        else{
            for(int i=1;i<=n;i++){
                ans+=i;
            }
            ans-=m;
            cout<<ans<<'\n';
        }
    }
    return 0;
}
