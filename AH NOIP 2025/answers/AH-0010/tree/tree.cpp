#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pii pair<int,int>
#define fi first
#define se second
template <typename T>
inline void in (T &x) {
    char c; int f=1;
    do {c=getchar(); (c=='-')&&(f=-1);} while(c>'9' || c<'0');
    for(x=0;c>='0' && c<='9';c=getchar()) x=(x*10)+(c^48);
    x*=f;
}

const int N=8005,oo=0x3f3f3f3f;
int n,m;
vector<int> e[N];
int fa[N];
int f[400][400][400];
int tp[400][400];

int mx1[N][N],mx2[N][N];

inline void chkmx (int &x,int y){(x<y)&&(x=y);}
int sz[N];
inline void dfs(int u) {
    if (e[u].empty()) {sz[u]=1,f[u][0][1]=0,f[u][1][0]=1; return ;}
    f[u][0][1]=0,f[u][1][0]=0;
    sz[u]=1; 
    for (int v:e[u]) {
        dfs(v);
        for (int i=0;i<=sz[u]+sz[v];++i) for (int j=0;j<=sz[u]+sz[v];++j) tp[i][j]=-oo;
        for (int z1=0;z1<=sz[u];++z1) {
            mx1[0][z1]=f[u][0][z1];
            for (int i=1;i<=sz[u];++i) mx1[i][z1]=max(mx1[i-1][z1],f[u][i][z1]);
        }
        for (int z2=0;z2<=sz[v];++z2) {
            mx2[0][z2]=f[v][0][z2];
            for (int i=1;i<=sz[v];++i) mx2[i][z2]=max(mx2[i-1][z2],f[v][i][z2]);
        }
        for (int z1=0;z1<=sz[u];++z1) 
            for (int z2=0;z2<=sz[v];++z2) {
                for (int j=0;j<=sz[v];++j) {
                    for (int tmp=0;tmp<=z1+z2;++tmp) {
                        chkmx(tp[j+tmp][z1+z2-tmp],mx1[min(j,sz[u])][z1]+f[v][j][z2]);
                    }
                }
                for (int i=0;i<=sz[u];++i) {
                    for (int tmp=0;tmp<=z1+z2;++tmp) {
                        chkmx(tp[i+tmp][z1+z2-tmp],f[u][i][z1]+mx2[min(sz[v],i)][z2]);
                    }
                }
            }
        for (int i=0;i<=sz[u]+sz[v];++i) for (int j=0;j<=sz[u]+sz[v];++j) f[u][i][j]=tp[i][j];
        sz[u]+=sz[v];
    }
    for (int i=0;i<=sz[u];++i) {
        for (int j=0;j<=sz[u];++j) if (f[u][i][j]>=0) f[u][i][j]+=i;
    }
}

inline void init () {
    in (n),in (m);
    for (int i=1;i<=n;++i) e[i].clear();
    for (int i=2;i<=n;++i) in (fa[i]),e[fa[i]].push_back(i);
}

inline void work () {
    memset (f,-0x3f,sizeof (f));
    dfs(1);
    int ans=0;
    for (int i=0;i<=n;++i)
        for (int j=0;j<=n;++j) chkmx (ans,f[1][i][j]);
    printf ("%d\n",ans);
}


int main() {
    freopen ("tree.in","r",stdin);
    freopen ("tree.out","w",stdout);
    int tes; in(tes); while (tes--) {
        init();
        work();
    }
    return 0;
}