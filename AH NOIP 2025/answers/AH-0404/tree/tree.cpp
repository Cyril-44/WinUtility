#include<bits/stdc++.h>
using namespace std;
long long t,n,m,p[8005],a[8005],wybl,ans,now[8005],idp[8005];
vector<long long> v[8005];
long long dfs(long long w)
{
	long long mx=0;
	long long len=v[w].size();
	for (int i=0;i<len;i++)
	{
		long long to=v[w][i];
		mx=max(mx,dfs(to));
	}
	if (len==0)
	{
		a[w]=idp[p[w]];
		idp[p[w]]++;
	}
	else
	{
		a[w]=mx+1;
	}
	return a[w];
}
void ddfs(long long w)
{
	now[a[w]]=1;
	long long len=v[w].size();
	for (int i=0;i<len;i++)
	{
		long long to=v[w][i];
		ddfs(to);
	}	
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
	while(t--)
	{
		memset(idp,0,sizeof(idp));
		cin>>n>>m;
		for (int i=1;i<=n;i++)
		{
			v[i].clear();
		}
		for (int i=2;i<=n;i++)
		{
			cin>>p[i];
			v[p[i]].push_back(i);
		}
		ans=0;
		wybl=dfs(1);
		for (int i=1;i<=n;i++)
		{
			memset(now,0,sizeof(now));
			ddfs(i);
			for (int j=0;;j++)
			{
				if (!now[j])
				{
					ans+=j;
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
