#include<bits/stdc++.h>
using namespace std;
const int N=10;
int t,n,m,ans,vis[4005],b[N][N],cnt,fa[4005],vfa[4005],d[4005];
vector<int> g[4005];
void dfs1(int u,int fa){
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==fa) continue;
        d[v]=d[u]+1;
        dfs1(v,u);
    }
}
void dfs(int u,int fa){
    b[u][vis[u]]=1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==fa) continue;
        dfs(v,u);
        for(int j=0;j<7;j++) b[u][j]=max(b[u][j],b[v][j]);
    }
    for(int i=0;i<7;i++) if(b[u][i]==0){cnt+=i;break;}
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>t;
    while(t--){
        memset(vfa,0,sizeof(vfa));
        memset(fa,0,sizeof(fa));
        cin>>n>>m;
        for(int i=1;i<=n;i++) while(g[i].size()>0) g[i].pop_back();
        for(int i=2;i<=n;i++){
            int x;
            fa[i]=x;
            cin>>x;
            g[i].push_back(x);
            g[x].push_back(i);
        }
        if(n<=7){
            ans=0;
            for(int i1=0;i1<7;i1++){
                for(int i2=0;i2<7;i2++){
                    for(int i3=0;i3<7;i3++){
                        for(int i4=0;i4<7;i4++){
                            for(int i5=0;i5<7;i5++){
                                for(int i6=0;i6<7;i6++){
                                    for(int i7=0;i7<7;i7++){
                                        cnt=0;
                                        vis[1]=i1,vis[2]=i2,vis[3]=i3,vis[4]=i4,vis[5]=i5,vis[6]=i6,vis[7]=i7;
                                        dfs(1,1);ans=max(ans,cnt);
                                        vis[1]=0,vis[2]=0,vis[3]=0,vis[4]=0,vis[5]=0,vis[6]=0,vis[7]=0;
                                        memset(b,0,sizeof(b));
                                    }
                                }
                            }
                        }
                    }
                }
            }
            cout<<ans<<endl;
        }else if(m<=2){
            cnt=0;
            int p=0;
            dfs1(1,1);
            for(int i=1;i<=n;i++){
                if(d[i]==0) continue;
                if(d[i]==1&&g[i].size()==1) cnt++;
                if(d[i]==1&&g[i].size()>1) cnt+=g[i].size();
                if(d[i]==2){
                    if(vfa[fa[i]]==0) cnt++;
                    vfa[fa[i]]++;
                    p=max(p,vfa[fa[i]]);
                }
            }
            cout<<cnt+p+2<<endl;
        }

    }
    return 0;
}
