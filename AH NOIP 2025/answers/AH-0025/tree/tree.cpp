#include<bits/stdc++.h>
using namespace std;
int t,n,m,fa[8005],len[8005],sz[8005],ans,f[4005][4005][3],tmp[4005][30];
vector<int> g[8005];
void dfs(int x){
    len[x]=sz[x]=1;
    f[x][0][0]=0;
    for(int y:g[x]){
        dfs(y);
        memset(tmp,-0x3f,sizeof(tmp));
        for(int i=0;i<=sz[x];i++){
            for(int j=0;j<=sz[y];j++){
                for(int k=0;k<=len[y]&&max(i,j)+k<=n;k++){
                    for(int l=0;l<=len[x];l++){
                        tmp[max(i,j)+k][l]=max(tmp[max(i,j)+k][l],f[x][i][l]+f[y][j][k]);
                    }
                    tmp[max(i,j)][k]=max(tmp[max(i,j)][k],f[x][i][0]+f[y][j][k]);
                }
            }
        }
        sz[x]+=sz[y];
        len[x]=max(len[x],len[y]+1);
        for(int i=0;i<=sz[x];i++){
            for(int j=0;j<=len[x];j++){
                f[x][i][j]=tmp[i][j];
            }
        }
    }
    memset(tmp,-0x3f,sizeof(tmp));
    for(int i=0;i<=sz[x];i++){
        for(int j=0;j<=len[x];j++){
            if(i>=1) tmp[i][j]=f[x][i-1][j]+i;
            if(j>=1) tmp[i][j]=max(tmp[i][j],f[x][i][j-1]+i);
        }
    }
    for(int i=0;i<=sz[x];i++){
        for(int j=0;j<=len[x];j++){
            f[x][i][j]=tmp[i][j];
        }
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>t;
    while(t--){
        memset(f,-0x3f,sizeof(f));
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            g[i].clear();
        }
        for(int i=2;i<=n;i++){
            scanf("%d",&fa[i]);
            g[fa[i]].push_back(i);
        }
        dfs(1);
        ans=0;
        for(int i=0;i<=sz[1];i++){
            ans=max(ans,f[1][i][0]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
2
5 2
1 1 2 2
7 2
1 1 2 2 2 3
*/
