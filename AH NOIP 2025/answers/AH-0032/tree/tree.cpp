#include<bits/stdc++.h>
using namespace std;
#define __MY_TEST__ 1
#define int long long
inline int read()
{
	int re=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
	while( isdigit(ch)) re=(re<<3)+(re<<1)+(ch^48),ch=getchar();
	return re*f;
}
const int N=8005;
int n,m;
int f[N][825],sze[N],tmp[N];
vector<int>gra[N];
void dfs(int u)
{
	for(int i=1;i<=m+10;i++) f[u][i]=-1e9;
	f[u][1]=1;
	for(auto v:gra[u])
	{
		dfs(v);
		for(int i=1;i<=m;i++) f[u][i+1]=max(f[u][i+1],f[v][i]+i+1);
	}
}
void work()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) gra[i].clear();
	for(int i=2;i<=n;i++) gra[read()].push_back(i);
	if(m<=2)
	{
		if(gra[1].size()==n-1)
		{
			cout<<n+1<<'\n';
			return ;
		}
		int ans=0,maxn=0;
		for(int i=2;i<=n;i++) ans+=gra[i].size()+(gra[i].size()!=0)*2,maxn=max(maxn,(int)gra[i].size()+1);
		cout<<ans+maxn+1<<'\n';
		return ;
	}
	dfs(1);
	cout<<*max_element(f[1]+1,f[1]+m+2)<<'\n';
}
signed main(){
#if __MY_TEST__
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t=read();
	while(t--) work();
}
