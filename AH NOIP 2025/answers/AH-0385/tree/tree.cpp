#include<bits/stdc++.h>
using namespace std;
int n,m,f[8010],t[8010],h[8010],ans,st[8010];
vector<int> p[8010];
int sum(int pt)
{
	int res=0;
	st[pt]=(1<<t[pt]);
	for(auto v:p[pt])
	{
		res+=sum(v);
		st[pt]|=st[v];
	}
	for(int i=0;i<n;i++)
		if(!(st[pt]&(1<<i)))
			return res+i;
}
void dfs(int d)
{
	if(d>n)
	{
		ans=max(ans,sum(1));
		return;
	}
	for(int i=0;i<t[f[d]];i++)
	{
		t[d]=i;
		dfs(d+1);
	}
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		for(int i=1;i<=8000;i++)p[i].clear();
		scanf("%d%d",&n,&m);
		m=0;
		for(int i=2;i<=n;i++)
		{
			scanf("%d",f+i);
			h[i]=h[f[i]]+1;
			m=max(m,h[i]);
			p[f[i]].push_back(i);
		}
		for(int i=m;i<=n;i++)
		{
			t[1]=i;
			dfs(2);
		}
		printf("%d\n",ans);
	}
	return 0;
}
