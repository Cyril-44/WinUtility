#include<bits/stdc++.h>
// #define int unsigned int
// #define max(x,y) ((x)>(y)?(x):(y))
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define pb push_back
using namespace std;
const int N=1e5+5;
int n,m;
int c ,t;
int a[5050];
vector<int>G[11451];
int sz[11451];
void dfs(int u,int fa) {
    sz[u]=1;
    for(int i=0;i<G[u].size();i++) {
        int v=G[u][i];
        if(v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
int f[20][20][20];
int g[20][20][20];
int fl[202];
void dp(int u,int fa) {
    if(fl[u]) return ; 
    if(sz[u]==1) {
        rep(l,0,n) {
            rep(r,l,n) {

                if(l==r&&r==0) f[u][0][0]=1;
                else if(r-l+1<=1) f[u][l][r]=0;
            }
        }
        return ;
    } 
    for(int i=0;i<G[u].size();i++) {
        int v=G[u][i];
        if(v==fa) continue;
        dp(v,u);
        memset(g,-0x3f,sizeof(g));
        rep(len,1,n) {

            rep(l,0,n){
                // rep(r,l,n) {
                    int r=l+len-1;
                    rep(dd,l,r) {
                        //[l,dd] 原来有的 [dd+1,r] 新加上的
                        int na=f[u][l][dd]+f[v][dd+1][r];
                        // if(sz[v])
                        // if(l==0) na+=r+1;
                        g[u][l][r]=max(g[u][l][r],na); 
                    }


                    rep(dd,l,r) {
                        //[l,dd] 原来有的 [dd+1,r] 新加上的
                        int na=f[v][l][dd]+f[u][dd+1][r];
                        // if(sz[v])
                        // if(l==0) na+=r+1;
                        g[u][l][r]=max(g[u][l][r],na); 
                    }

                    g[u][l][r]=max(g[u][l][r],f[v][l][r]);
                // }
            }
        }
 

        rep(l,0,n) {
            rep(r,l,n) {
                f[u][l][r+1]=max(f[u][l][r+1],g[u][l][r]);
                if(l)
                f[u][l-1][r]=max(f[u][l-1][r],g[u][l][r]);
            }
        }
    }

        rep(l,0,n) {
            rep(r,l,n) {
                if(l==0) f[u][l][r]+=r+1;
            }
        }

}
int pl[11451]; 
signed main() {
   freopen("tree.in","r",stdin);                                                
   freopen("tree.out","w",stdout); 
   cin>>t; 
   while(t--) {
       memset(f,-0x3f,sizeof(f));
       rep(i,1,n) G[i].clear();
       cin>>n>>m;
       rep(i,2,n) {
           int p;
           cin>>p;
           G[i].pb(p);
           G[p].pb(i);
       }
    int ans=0;
    dfs(1,0); 
    
            dp(1,0);
    rep(l,0,n) {
        rep(r,l,n) {
            ans=max(ans,f[1][l][r]);
            // if(f[1][l][r]==12) {
            //     cout<<l<<' '<<r<<endl;
            // }
        }
    }
    // cout<<f[2][0][1]<<endl;
    // cout<<f[2][0][2]<<endl;
    // cout<<f[2][0][0]<<endl;
    cout<<ans-1<<'\n';
    memset(fl,0,sizeof(fl));
   }
    return 0;
} 