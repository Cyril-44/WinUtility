#include<bits/stdc++.h>
using namespace std;
int n;
long long m,ans,summ,vis;
struct T
{
	int a,b;
	long long sum;
	bool pan;
}x[100009];
int last[100009];
bool cmp(T xx,T yy)
{
	return xx.sum<yy.sum;
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i].a>>x[i].b;
		x[i].sum=x[i].a+x[i].b;
	}
	sort(x+1,x+n+1,cmp);
	vis=(x[1].sum/2)+1;
	for(int i=2;i<=n;i++)
	{
		if(x[i].a<vis&&m>=x[i].a)
		{
			ans++;
			m-=x[i].a;
			x[i].pan=1;
		}
		else
		{
			x[i].pan=0;
		}
	}
	if(m>=x[1].sum)	
	{
		summ=m/x[1].sum;
		m-=summ*x[1].sum;
		ans+=summ*2;
	}
	last[1]=x[1].a;
	for(int i=2;i<=n;i++)
	{
		if(x[i].pan==1)  last[i]=x[i].b;
		else  last[i]=x[i].a;
	}
	sort(last+1,last+n+1);
	for(int i=1;i<=n;i++)
	{
		if(m>=last[i])
		{
			ans++;
			m-=last[i];
		}
	}
	cout<<ans;
	return 0;
}

