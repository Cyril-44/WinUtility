#include<bits/stdc++.h>
using namespace std;
vector<int> g[8005];
int n,m;
long long f[8005];
long long dfs(int x)
{
	if(g[x].size()==0)
	{
		f[x]=-1;
		return 0;
	}
	long long ans=1,sizm=-1;
	for(int i=0;i<g[x].size();i++){
		ans+=dfs(g[x][i]);
		sizm=max(sizm,f[g[x][i]]);
	}
	f[x]=sizm+g[x].size();
	ans+=f[x]+1;
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)g[i].clear(),f[i]=0;
		for(int i=2;i<=n;i++){
			int x;
			cin>>x;
			g[x].push_back(i);
		}
		cout<<dfs(1)+1<<endl;
	}
	return 0;
}
