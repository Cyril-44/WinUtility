#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

const int N = 5e3 + 10,mod = 998244353;

int n,m,fa[N],sz[N],val[N],t[15][15],ans = 0,mx = 0;

vector <int> G[N];

void dfs1(int u){
    t[u][val[u]] = 1;
    for(int v : G[u]){
            dfs1(v);
        for(int i = 0;i < n;i ++) t[u][i] |= t[v][i];
    }
    for(int i = 0;i <= n;i ++){
        if(!t[u][i]){ans += i;return;}
    }
}


void dfs(int step){
    if(step > n){
            ans = 0;memset(t,0,sizeof(t));
        dfs1(1);
        mx = max(mx,ans);
       return;
    }
    for(int i = 0;i < n;i ++){
        val[step] = i;dfs(step + 1);

    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);

    int T;
    cin >> T;
    while(T --){
            memset(fa,0,sizeof(fa));
    memset(sz,0,sizeof(sz));
    memset(t,0,sizeof(t));
         cin >> n >> m;
         for(int i = 1;i <= n;i ++) G[i].clear();
        for(int i = 2;i <= n;i ++){
            cin >> fa[i];
            G[fa[i]].push_back(i);
         }
         if(n <= 7){
            mx = 0;dfs(1);cout << mx << '\n';continue;
         }
         for(int i = 2;i <= n;i ++) sz[i] = G[i].size() + 1;
         sz[1] = 1;
         int mx = 0;
         for(int j : G[1]) sz[1] += sz[j],mx = max(mx,sz[j]);
         int ans = 0;
         for(int j :G[1]) ans += (sz[j] == 1 ? 1 : sz[j] +1);
         cout << ans + mx +1 << '\n';
    }


    return 0;
}
