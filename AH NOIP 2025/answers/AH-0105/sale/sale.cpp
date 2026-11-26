#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N=5010,mod=998244353;

int n,m;
int a[N];
int w[N];
LL f[N];
struct Node
{
	int w,a,id;
	double xjb;
};

bool cmp(Node x,Node y)
{
	if(x.xjb==y.xjb)
	{
		if(x.a==y.a)
		{
			return x.id<y.id;
		}
		else return x.a>y.a;
	}
	else return x.xjb>y.xjb;
}

LL work1()
{
	memset(f,0,sizeof f);
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=w[i];j--)
		{
			f[j]=max(f[j],f[j-w[i]]+a[i]);
		}
	}

	return f[m];
}

int qmi(int a,int k)
{
	int res=1;
	while(k)
	{
		if(k&1)res=(1ll*res*a)%mod;
		a=(1ll*a*a)%mod;
		k>>=1;
	}
	return res;
}

LL work2()
{
	int mm=m;
	vector<Node> q;
	for(int i=1;i<=n;i++)
	{
		q.push_back({w[i],a[i],i,(1.0*a[i]/w[i])});
	}

	sort(q.begin(),q.end(),cmp);

	LL res=0;
	for(int i=0;i<n;i++)
	{
		if(mm>=q[i].w)
		{
			mm-=q[i].w;
			res+=q[i].a;
		}
	}
	return res;
}

int C(int b,int a)
{
	int x=1,y=1;
	for(int i=0;i<a;i++)
	{
		x=((1ll*x)*(b-i))%mod;
	}
	for(int i=1;i<=a;i++)
	{
		y=((1ll*y)*i)%mod;
	}
	return x/y;
}


int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);

	int c,T;
	scanf("%d%d",&c,&T);
	while(T--)
	{
		bool flag=1;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(i>=2&&a[i]!=a[i-1])flag=0;
		}

		if(n<=10)
		{
			int cnt=0;
			for(int i=0;i<1<<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(i&(1<<j))
					{
						w[j+1]=1;
					}
					else w[j+1]=2;
				}

				LL ans=work1();//beibao
				LL res=work2();//shiji
				//cout<<res<<" "<<ans<<endl;
				if(res>=ans)cnt=(cnt+1)%mod;
			}

			printf("%d\n",cnt);
		}
		else if(m==2*n-1||flag==1)
		{
			printf("%d\n",qmi(2,n)%mod);
		}
		else if(m==2*n-2)
		{
			sort(a+1,a+1+n);
			if(a[1]==a[2]||a[1]*2<a[2])printf("%d\n",qmi(2,n)%mod);
			else printf("%d\n",qmi(2,n)%mod-1);
		}
		else if(m==2)
		{
			int res=2;
			sort(a+1,a+1+n);
			for(int i=1;i<=n;i++)
			{
				if(a[i]*2<=a[n])res++;
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(a[i]+a[j]>=a[n])
					{
						res=(res+qmi(2,i-1))%mod;
					}
				}
			}
			printf("%d\n",res);
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}