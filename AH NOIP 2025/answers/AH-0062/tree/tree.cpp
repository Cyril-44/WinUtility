#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 8e3+5, M = 998244353;
int T, n, m, dep[N], f[N][N], siz[N];
vector<int> g[N];
inline ll read(){
    ll s=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){s=(s<<3)+(s<<1)+(c^48);c=getchar();}
    return s*f;
}
void dfs_pretreat(int x, int fa){
    dep[x] = dep[fa]+1;
    siz[x] = 1;
    for(int i=0;i<g[x].size();i++){
        int t = g[x][i];
        if(t == fa)continue;
        dfs_pretreat(t, x);
        siz[x] += siz[t];
    }
    f[x][0] = siz[x];
}
void dfs(int x, int fa){
    for(int i=0;i<g[x].size();i++){
        int t = g[x][i];
        if(t == fa)continue;
        dfs(t, x);
    }
    int s = g[x].size();
//    for(int d=0;d<(1<<s);d++){
//        for(int i=0;i<s;i++){
//            if(d & (1<<i))
//        }
//    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    T = read();
    while(T--){
        n = read(), m = read();
        for(int i=2;i<=n;i++){
            int p = read();
            g[i].push_back(p);
            g[p].push_back(i);
        }
        dep[0] = -1;
        dfs_pretreat(1, 0);
        dfs(1, 0);

//        Reset();
    }
    return 0;
}

//这题真的有部分分吗
