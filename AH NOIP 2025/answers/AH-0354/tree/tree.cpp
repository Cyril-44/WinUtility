#include<bits/stdc++.h>
using namespace std;
int read()
{
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
void write(long long x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
vector<int> g[8005];
int fa[8005],siz[8005];
void dfs1(int p)
{
	siz[p]=1;
	for(int i=0;i<(int)g[p].size();i++)
	{
		dfs1(g[p][i]);
		siz[p]+=siz[g[p][i]];
	}
}
long long ans;
int need[8005],cnt[8005];
bool cmp(int x,int y)
{
	if(siz[x]!=siz[y]) return siz[x]>siz[y];
	return x<y;
}
void dfs2(int p)
{
	if(!g[p].empty())
	{
		sort(g[p].begin(),g[p].end(),cmp);
		for(int i=0;i<(int)g[p].size();i++)
			dfs2(g[p][i]);
	}
	memset(cnt,0,sizeof cnt);
	int x=p;
	while(x) cnt[need[x]]++,x=fa[x];
	int maxi=0;
	for(int i=1;i<=8001;i++)
		if(cnt[i]>cnt[maxi]) maxi=i;
	x=p;
	while(x)
	{
		if(need[x]==maxi) need[x]=maxi+1,ans++;
		x=fa[x];
	}
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	int t=read();
	while(t--)
	{
		int n=read();
		read();
		for(int i=1;i<=n;i++)
		{
			g[i].clear();
			need[i]=siz[i]=0;
		}
		ans=0;
		for(int i=2;i<=n;i++)
		{	
			fa[i]=read();
			g[fa[i]].push_back(i);
		}
		dfs1(1);
		dfs2(1);
		write(ans);
		putchar('\n');
	}
	return 0;
}
