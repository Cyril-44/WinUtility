#include<bits/stdc++.h>
#define pb push_back
using namespace std;
void in(int &x){
	int f=1;char c=getchar();x=0;
	while((c>'9'||c<'0')&&c!='-')c=getchar();
	if(c=='-')c=getchar(),f=-1;
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	x*=f;
}
int t,n,m,k,x,y,a[100005],b[100005],pa[8005],siz[8005],B;
int f[405][405][405];
int F[4005][4005],sm[4005];
vector<int>g[8005];
void upd(int &x,int y){x=max(x,y);}
void dfs(int k){
	siz[k]=1;
	for(int v:g[k])dfs(v);
	if(n>=4000)B=1;else B=n;
	for(int v:g[k]){
		for(int i=0;i<=siz[k]+siz[v];i++)for(int j=0;j<=siz[k]+siz[v]-i&&j<=B;j++)F[i][j]=0;
		for(int x=0;x<=siz[v]&&x<=B;x++){
			for(int y=0;y<=siz[k]&&x+y<=B;y++){
				int s1=0,s2=0;
				for(int i=0;i<=siz[v]-x||i<=siz[k]-y;i++){
					if(i+x<=siz[v])upd(s1,f[v][i][x]),upd(F[i][x+y],s2+f[v][i][x]);
					if(i+y<=siz[k])upd(s2,f[k][i][y]),upd(F[i][x+y],s1+f[k][i][y]);
				}
			}
		}
		siz[k]+=siz[v];
		for(int i=0;i<=siz[k];i++)for(int j=0;j<=siz[k]-i&&j<=B;j++)f[k][i][j]=F[i][j];
	}
    for(int i=0;i<=siz[k];i++)for(int j=0;j<=siz[k]-i&&j<=B;j++)F[i][j]=0;
    for(int i=1;i<=siz[k];i++)upd(F[i+1][0],f[k][i][0]+i+1);
    for(int v:g[k])for(int i=0;i<=siz[v];i++)upd(F[i+siz[k]-siz[v]][0],f[v][i][0]+siz[k]-siz[v]);
    for(int i=0;i<=siz[k];i++)for(int j=0;j<=siz[k]-i&&j<=B;j++)for(int x=0;x<=j;x++)upd(F[i+x][j-x],f[k][i][j]+i+x);
    for(int i=0;i<=siz[k];i++)for(int j=0;j<=siz[k]-i&&j<=B;j++)f[k][i][j]=F[i][j];
}
void solve(){
	in(n);in(m);
	for(int i=1;i<=n;i++)g[i].clear(),sm[i]=1;
	for(int i=2;i<=n;i++)in(pa[i]),g[pa[i]].pb(i);
	for(int i=n;i>=2;i--)sm[pa[i]]+=sm[i];
    int s=0,d=g[1].size();for(int x:g[1])s=max(s,sm[x]);
    for(int x:g[1])if(sm[x]==1)d--;
    if(m<=2){printf("%d\n",n+d+s);return;}
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)for(int k=0;k<=n;k++)f[i][j][k]=0;
	dfs(1);
	int ans=0;for(int i=0;i<=n;i++)ans=max(ans,f[1][i][0]);
	printf("%d\n",ans);
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	in(t);
	while(t--)solve();
}