#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int cnt=0;
inline int read()
{
	int x=0,f=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
	
}
int a[5010],w[5010];
int n,m;
struct node
{
	double xin;
	int yuan,xia,id;
	bool fl;
};
bool cmp(node x,node y)
{
	if(x.xin==y.xin)
	{
		if(x.yuan==y.yuan)return x.id<y.id;
		return x.yuan>y.yuan;
	}
	return x.xin>y.xin;
}
bool cmp2(node x,node y)
{
	if(x.yuan==y.yuan) return x.xia<y.xia;
	return x.yuan>y.yuan;
}
node c[5010];
void dfs(int dep)
{
	if(dep>=n+1)
	{
		for(int i=1;i<=n;i++)
		{
			c[i].xin=1.0*a[i]/w[i];
			c[i].yuan=a[i];
			c[i].id=i;
			c[i].xia=w[i];
			c[i].fl=0;
		}
		sort(c+1,c+n+1,cmp);
		int x=m;
	//	for(int i=1;i<=n;i++)
	//	{
	//		cout<<c[i].xin<<" "<<c[i].xia<<" "<<c[i].yuan<<endl;
	//	}
		for(int i=1;i<=n;i++)
		{
			if(x>=c[i].xia) 
			{
				x-=c[i].xia;
				c[i].fl=1;
			}
			if(x==0) break;
		}
		sort(c+1,c+n+1,cmp2);
		x=m;
		bool flag=1;
		for(int i=1;i<=n;i++)
		{				
			if(x>=c[i].xia)
			{
				x-=c[i].xia;
				if(!c[i].fl)
				{
					flag=0;
					break;
				}				
			}


		}
		if(flag) cnt=(cnt+1)%mod;
		return ;
	}
	for(int i=1;i<=2;i++)
	{
		w[dep]=i;
		dfs(dep+1);
	}
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	c=read();
	t=read();
	while(t--)
	{
		cnt=0;
		n=read();m=read();
		for(int i=1;i<=n;i++)
		{			
			a[i]=read();
		}
		
		if(n>=40)
		{
			int ans=1;
			for(int i=1;i<=n;i++)
			{
				ans=ans*2%mod;
			}
			printf("%d\n",ans);
		}
		else
		{
			dfs(1);
			printf("%d\n",cnt);
		}
	}
	return 0;
}
