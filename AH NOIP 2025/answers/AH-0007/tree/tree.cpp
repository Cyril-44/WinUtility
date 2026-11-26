#include <bits/stdc++.h>
using namespace std;
struct B
{
	int a[362];
	int z;
	void operator+=(B r)
	{
		if(z<0)
		{
			z=r.z;
			for(int i=0;i<=z;i++)
				a[i]=r.a[i];
			return;
		}
		if(r.z<0) return;
		z=max(z,r.z);
		for(int i=0;i<=z;i++)
			a[i]=max(a[i],r.a[i]);
	}
	void operator*=(B r)
	{
		if(z<0||r.z<0)
		{
			z=-1;
			return;
		}
		B q;
		q.z=z+r.z;
		for(int i=0;i<=q.z;i++)
			q.a[i]=-1;
		for(int i=0;i<=z;i++)
		{
			if(a[i]==-1) continue;
			for(int j=0;j<=r.z;j++)
			{
				if(r.a[j]==-1) continue;
				q.a[i+j]=max(q.a[i+j],a[i]+r.a[j]);
			}
		}
		z=q.z;
		for(int i=0;i<=z;i++)
			a[i]=q.a[i];
	}
	void operator+=(int k)
	{
		if(z<0) return;
		for(int i=0;i<=z;i++)
			if(a[i]!=-1) a[i]+=k;
	}
	B operator~()
	{
		B q;
		q.z=z-1;
		for(int i=0;i<=q.z;i++)
		{
			q.a[i]=a[i+1];
			if(q.a[i]!=-1) q.a[i]++;
		}
		return q;
	}
};
struct F
{
	int to[722],ns[362],fs[362],m;
	void adds(int x,int y)
	{
		m++;
		to[m]=y;
		ns[m]=fs[x];
		fs[x]=m;
	}
	void add(int x,int y)
	{
		adds(x,y);
		adds(y,x);
	}
};
#define f f123456[0]
B b[362][362],c1,c2,c3,c4;
F f123456[1];
int dfs(int x,int g)
{
	bool l=true;
	int ii=f.fs[x];
	int s=1;
	b[x][0].z=1;
	b[x][0].a[1]=0;
	b[x][0].a[0]=0;
	while(ii)
	{
		if(f.to[ii]!=g)
		{
			l=false;
			int v=dfs(f.to[ii],x);
			s+=v;
			c1=b[x][0];
			c2=b[f.to[ii]][0];
			for(int i=0;i<=max(v,s-v);i++)
			{
				c1+=b[x][i];
				c2+=b[f.to[ii]][i];
				c3=c1;
				c3*=b[f.to[ii]][i];
				c4=c2;
				c4*=b[x][i];
				c4+=c3;
				b[x][i]=c4;
			}
		}
		ii=f.ns[ii];
	}
	if(l)
	{
		b[x][1].z=0;
		b[x][1].a[0]=1;
		return s;
	}
	for(int i=1;i<=s;i++)
		b[x][i]+=i;
	for(int i=1;i<=s;i++)
		b[x][i]+=(~b[x][i-1]);
	return s;
}
int main()
{
	ios::sync_with_stdio(0);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		memset(b,-1,sizeof b);
		memset(f123456,0,sizeof f123456);
		int n,m;
		cin>>n>>m;
		for(int i=2;i<=n;i++)
		{
			int x;
			cin>>x;
			f.add(x,i);
		}
		dfs(1,0);
		int ans=0;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=b[1][i].z;j++)
				ans=max(ans,b[1][i].a[j]);
		cout<<ans<<endl;
	}
	return 0;
}
// 10:10 - 12:50, samples #1 - #3 passed (155 ms), [32, 48] points
