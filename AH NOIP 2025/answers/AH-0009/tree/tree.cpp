#include <bits/stdc++.h>
#define ll long long
#define up(i,a,b) for (int i=(a);i<=(b);i++)
#define down(i,a,b) for (int i=(a);i>=(b);i--)
using namespace std;
const int N=8e3+5,M=805;
const ll inf=1e15;
int n,m;

vector<int> g[N];

namespace solve1{
    int num[10],val[10];ll ans;
    set<int> dfss(int u){
        set<int> s;s.insert(num[u]);
        for (int v:g[u]){
            set<int> ss=dfss(v);
            for (int x:ss) s.insert(x);
        }
        int x=0;
        while (s.count(x)) x++;
        val[u]=x;
        return s;
    }
    void dfs(int pos){
        if (pos==n+1){
            dfss(1);
            ll res=0;
            up(i,1,n) res+=val[i];
            ans=max(ans,res);
            return;
        }
        up(i,0,m+1){
            num[pos]=i;
            dfs(pos+1);
        }
    }
    void solve(){
        dfs(1);
        cout<<ans<<'\n';
    }
}


namespace solve2{
    int ans,max1;
    int dep[N],siz[N],num[N];
    void dfs(int u,int fa){
        dep[u]=dep[fa]+1,siz[u]=1;
        for (int v:g[u]){
            dfs(v,u);
            siz[u]+=siz[v];
        }
        if (dep[u]==2){
            num[u]=siz[u]-1;
            if (siz[u]>1) ans++;
        }
    }
    void solve(){
        max1=ans=0;
        dfs(1,0);
        up(u,1,n) if (dep[u]==2){
            ans+=num[u]+1;
            max1=max(max1,num[u]+1);
        }
        ans+=max1+1;
        cout<<ans<<'\n';
    }
}

void solve(){
    cin>>n>>m;m++;
    up(i,1,n) g[i].clear();
    up(i,2,n){
        int p;cin>>p;
        g[p].emplace_back(i);
    }
    if (n<=7){
        solve1::solve();
        return;
    }
    else if (m<=3){
        solve2::solve();
        return;
    }
    else solve1::solve();
}

int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while (t--) solve();
    return 0;
}
