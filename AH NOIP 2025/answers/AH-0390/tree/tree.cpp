#include<bits/stdc++.h>
using namespace std;
const long long N=8e3+10;
long long t,n,m,x,s[N],ans[N],k[N],siz[N],d[N];
vector<long long>g[N];
void dfs1(long long u)
{
	siz[u]=1;
	for(auto v:g[u]){
		d[v]=d[u]+1;
		dfs1(v);
		siz[u]+=siz[v];
	}
	return;
}
void dfs(long long u)
{
	bool f=1;
	long long x=0,maxn=0;
	if(g[u].empty()){
		ans[u]=1;
		k[u]=0;
		return;
	}
	for(auto v:g[u]){
		dfs(v);
		if(ans[v]>=siz[v]*d[v]){
			ans[u]+=ans[v];
			x=max(x,k[v]+1);
			f=0;
		}else{
			k[u]+=siz[v];
		}
		maxn=max(maxn,s[v]);
	}
	k[u]=x+k[u];
	if(f)ans[u]++;
	ans[u]+=k[u]+1;
	s[u]=k[u]+1+maxn;
	return;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		memset(g,0,sizeof g);
		memset(ans,0,sizeof ans);
		memset(k,0,sizeof k);
		memset(s,0,sizeof s);
		cin>>n>>m;
		for(long long i=2;i<=n;i++){
			cin>>x;
			g[x].push_back(i);
		}
		d[1]=0;
		dfs1(1);
		dfs(1);
		cout<<ans[1]<<'\n';
	}
	return 0;
}
