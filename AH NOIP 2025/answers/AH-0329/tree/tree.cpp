#include<bits/stdc++.h>
using namespace std;
const int N=100;
vector<int> e[N];
bool k[N][N];
int a[N];
int n,h,ans,maxl;
int read()
{
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}

void check(int fa,int u)
{
	k[u][a[u]]=true;
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		check(u,v);
		for(int i=0;i<=6;i++)
			if(k[v][i]) k[u][i]=true;
	}
	for(int i=0;i<=8;i++)
		if(!k[u][i]) {ans+=i;return;}
}

void dfs(int dep)
{
	if(dep>n) 
	{
		memset(k,false,sizeof(k));
		ans=0;
		check(0,1);
		maxl=max(maxl,ans);
		return;
	}
	for(int i=0;i<=6;i++)
	{
		a[dep]=i;
		dfs(dep+1);
	}
		
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T=read();
	while(T--)
	{
		n=read(),h=read();
		for(int i=2;i<=n;i++)
		{
			int x=read();
			e[x].push_back(i);
		}
		if(n<=13) dfs(1);
		cout<<maxl<<endl;
		memset(e,0,sizeof(e));
		ans=maxl=0;
	}
	return 0;
}
