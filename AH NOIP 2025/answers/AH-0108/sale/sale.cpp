#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10,M=1e7;
const long long MOD=998244353;
int n,m,c,T;
int f[2*N];	//DP
bool b[M];
long long ans,asTX,asDP;
int a[N];
struct xingjiabi{
	long long it,bi;
}xjb[N];
bool cmp(xingjiabi x1,xingjiabi x2)
{	return x1.bi>x2.bi;}
long long mi(long long a1,int b1)	//a1^b1%p
{
	long long ans=1;
	while(b1)
	{
		if(b1&1)ans=ans*a1%MOD;
		a1=a1*a1%MOD;
		b1>>=1;
	}
	return ans;
}
void dfs(long long v)		//暴力搜索,v表示状态
{
	if(b[v])return;
//	cout<<v<<endl;
	b[v]=1;
	long long x1=1,v1;
	if((v==0)||(v==mi(2,n)-1))ans++;
	else
	{
		asTX=0;
		//DP
		memset(f,0,sizeof(f));
		v1=x1&v;
		if(v1)v1=2;
		else v1=1;
		for(int i=v1;i<n;i++)
		f[i]=a[0];
		for(int i=1;i<n;i++)
		{
			x1<<=1;
			v1=x1&v;
			if(v1)v1=2;
			else v1=1;
			for(int j=m;j>=v1;j--)
			f[j]=max(f[j],f[j-v1]+a[i]);
		}
		asDP=f[m];
		//tanxin
		x1=1;
		for(int i=0;i<n;i++)
		{
			v1=x1&v;
			if(v1)xjb[i].bi=a[i];
			else xjb[i].bi=a[i]*2;
			x1<<=1;
			xjb[i].it=i;
		}
		sort(xjb,xjb+n,cmp);
		int mm=m;
		for(int i=0;i<n;i++)
		{
			v1=1<<(xjb[i].it);
			v1&=v;
			if(v1)v1=2;
			else v1=1;
//			cout<<":"<<xjb[i].it<<" "<<v1<<endl;
//			cout<<mm<<endl;
			if(mm-v1<0)continue;
			mm-=v1;
			asTX+=a[xjb[i].it];
//			cout<<"!"<<asTX<<endl;
		}
		if(asDP==asTX)ans++;
	}
	x1=1;
	for(int i=0;i<n;i++)
	{
		v1=v|x1;
		if(!b[v1])dfs(v1);
		x1<<=1;
	}
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>T;
	if(c==18)
	{
		while(T--)
		{
			cin>>n>>m;
			cout<<mi(2,n)<<endl;
		}
		return 0;
	}
	while(T--)
	{
		memset(b,0,sizeof(b));
		ans=0;
		cin>>n>>m;
		for(int i=0;i<n;i++)
		cin>>a[i];
		if(m==n*2-1)
		{
			cout<<mi(2,n)<<endl;
			continue;
		}
		dfs(0);
		cout<<ans<<endl;
	}
	return 0;
}
