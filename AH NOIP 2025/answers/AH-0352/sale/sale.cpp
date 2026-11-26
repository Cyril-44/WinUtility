#include <bits/stdc++.h>
using namespace std;
int n,m;
const int kkj=50005;
long long w[10005],val[10005];
int cnt=0;
struct XB{
	long long price,value,good,number;
	}p[10005];
bool cmp(XB x,XB y)
{
	if(x.good==y.good)
	{
		if(x.price==y.price)return x.number<y.number;
		else return x.price>y.price;
	}
	else return x.good>y.good;
}
void work()
{
	for (int i=1;i<=n;i++)
	{
		p[i].price=w[i];
		p[i].value=val[i];
		p[i].good=w[i]/val[i];
		p[i].number=i;
	}
	sort(p+1,p+n+1,cmp);
	long long ans=0;
	int m1=m;
	for (int i=1;i<=n;i++)
	{
		if(m1>=p[i].value)
		{
			ans+=p[i].price;
			m1-=p[i].value;
		}
	}
	long long ans1=0;
	long long  w1[10000]={0};
	memset(w1,0,sizeof(w1));
	for (int i=1;i<=n;i++)
	{
		for (int j=m;j>=1;j--)
		{
			if(w1[j]>0&&(p[i].value+j)<=m)
			{
				w1[j+p[i].value]=max(w1[j+p[i].value],w1[j]+p[i].price);
			}
		}
		w1[p[i].value]=max(p[i].price,w1[p[i].value]);
	}
	for (int i=m;i>=1;i--)
	{
		ans1=max(ans1,w1[i]);
	}
	if(ans==ans1&&ans>0) cnt++;
}
void dfs(int k)
{
//	cout<<k<<endl;
	if(k>n)
	{
		work();
		return;
	}
	for(int i=1;i<=2;i++)
	{
		val[k]=i;
		dfs(k+1);
	}
}
int main()
{
	freopen("sale3.in","r",stdin);
	freopen("sale3.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		scanf("%d""%d",&n,&m);
		memset(w,0,sizeof(p));
		for (int i=1;i<=n;i++)
		{
			scanf("%lld",&w[i]);
		}
		cnt=0;
		dfs(1);
		printf("%d\n",cnt);
	}
	return 0;
	}
