#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val,w,num;
	double xjb;
}b[1005];
long long a[1005][2005],val[1005],w[1005],ans=0;
int n,m,mod=998244353;
bool cmp(node i,node j)
{
	if (i.xjb==j.xjb&&i.val==j.val) return i.num<j.num;
	else if (i.xjb==j.xjb) return i.val>j.val;
	else return i.xjb>j.xjb;
}
long long bao()
{
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=m;j++)
		{
			if (j-w[i]>=0) a[i][j]=max(a[i-1][j],a[i-1][j-w[i]]+val[i]);
			else a[i][j]=a[i-1][j];
		}
	}
	return a[n][m];
}
long long bi()
{
	memset(b,0,sizeof(b));
	long long cost=0,now=m;
	for (int i=1;i<=n;i++)
	{
		b[i].val=val[i];
		b[i].w=w[i];
		b[i].xjb=1.0*val[i]/w[i];
		b[i].num=i;
	}
	sort(b+1,b+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		if (now-b[i].w>=0)
		{
			cost+=b[i].val;
			now-=b[i].w;
		}
	}
	return cost;
}
void dfs(int k)
{
	if (k==n+1)
	{
		int x=bao(),y=bi();
		if (x==y) ans++;
		return ;
	}
	w[k]=1;
	dfs(k+1);
	w[k]=2;
	dfs(k+1);
}
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while (t--)
	{
		ans=0;
		cin>>n>>m;
		memset(val,0,sizeof(val));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(w,0,sizeof(w));
		for (int i=1;i<=n;i++)
		{
			cin>>val[i];
		}
		if (n<=10) 
		{
			dfs(1);
			cout<<ans<<endl;
			continue;
		}
		int flag1=1,flag2=1;
		for (int i=1;i<=n-1;i++)
		{
			if (val[i]!=val[i+1]) flag1=0;
			if (val[i]<=500000000) flag2=0;
		}
		if (flag1==1||(m=2*n-1)||flag2==1)
		{
			long long as=1;
			for (int i=1;i<=n;i++)
			{
				as*=2;
				as%=mod;
			}
			cout<<as<<endl;
			continue;
		}
		if (m==2*n-2)
		{
			long long as=1;
			for (int i=1;i<=n;i++)
			{
				as*=2;
				as%=mod;
			}
			sort(val+1,val+n+1);
			for (int i=1;i<=n-2;i++)
			{
				int x=val[i],y=val[i+1],z=val[i+2];
				double yx=1.0*y/2,zx=1.0*z/2;
				cout<<x<<" "<<y<<" "<<z<<endl;
				if (x+y<z&&zx<yx) as--;
			}
			cout<<as<<endl;
			continue;
		}
	}
	return 0;
}
/*
 * 797816752 292766428 747293024 373646512 481679448 336154100 336154100 200052311 240839724 398908376 377917336 218651804 437303608 231262199 398908376 313363965 381461817 762923634 215657255 431314510
 * 
*/
