#include<bits/stdc++.h>
using namespace std;
const int N=4005;
int t,n,m,ans,p[N],s[N],f[N][50];
int h[N],to[N],nt[N],cnt;
int check(int u){
	f[u][s[u]]=1;
    if(h[u]==0){
        if(s[u]==0) return 1;
        else return 0;
    }
    int sum=0;
    for(int i=h[u];i;i=nt[i]){
        sum+=check(to[i]);
        for(int j=0;j<=n;j++) f[u][j]=max(f[u][j],f[to[i]][j]);
    }
    for(int i=0;i<=n;i++)
        if(f[u][i]==0){sum+=i;break;}
    return sum;
}
void dfs(int u){
    if(u>n){
		ans=max(ans,check(1));
		return ;}
    for(int i=0;i<s[p[u]];i++){s[u]=i; dfs(u+1);}
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        memset(f,0,sizeof(f));
        memset(h,0,sizeof(h));cnt=0;
        for(int i=2;i<=n;i++){
            scanf("%d",&p[i]);
            to[++cnt]=i,nt[cnt]=h[p[i]],h[p[i]]=cnt;
        }
        for(int i=0;i<=n;i++){s[1]=i;dfs(2);}
        printf("%d\n",ans);
    }
    return 0;
}
