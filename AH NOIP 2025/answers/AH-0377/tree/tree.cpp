#include<bits/stdc++.h>
using namespace std;
struct node
{
	vector<int> ch;
	int val;
	vector<int> qu;
}tr[8005];
int in[8005];
long long Max=0;
int n, m;
void js(int p)
{
	if(tr[p].ch.empty()) return;
	for(int i=0;i<int(tr[p].ch.size());i++)
	{
		js(tr[p].ch[i]);
	}
	int vis[8005]={0};
	for(int i=0;i<int(tr[p].ch.size());i++)
	{
		for(int j=0;j<int(tr[tr[p].ch[i]].qu.size());j++)
		{
			vis[tr[tr[p].ch[i]].qu[j]]++;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(vis[i]==int(tr[p].ch.size()) && i!=tr[p].val)
		{
			tr[p].qu.push_back(i);
		}
	}
	return;
}
void dfs(int step)
{
	if(step>n)
	{
		js(1);
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			if(!tr[i].qu.empty()) ans+=tr[i].qu.front();
			else ans+=n;
		}
		for(int i=1;i<=n;i++)
		{
			if(in[i]!=0) tr[i].qu.clear();
		}
		Max=max(Max,ans);
		return;
	}
	for(int i=0;i<n;i++)
	{
		tr[step].val=i;
		if(in[step]==0)
		{
			tr[step].qu.clear();
			for(int j=0;j<n;j++)
			{
				if(j!=i) tr[step].qu.push_back(j);
			}
		}
		dfs(step+1);
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
		scanf("%d%d",&n,&m);
		for(int i=1;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			in[x]++;
			tr[x].ch.push_back(i+1);
		}
		dfs(1);
		printf("%lld\n",Max);
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
