#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,ans;
struct fun
{
	double w;
	long long f;
}a[200005];
bool cmp(fun a,fun b)
{
	if (a.w!=b.w)
	return a.w<b.w;
	return !a.f;
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>x>>y;
		a[i*2-1].w=x;
		a[i*2-1].f=1;
		a[i*2].w=(x+y)*1.0/2;
		a[i*2].f=0;
	}
	sort(a+1,a+1+2*n,cmp);
	for (int i=1;i<=2*n;i++)
	{
		if (m==0)
		{
			break;
		}
		if (a[i].f==1)
		{
			if (a[i].w<=m)
			{
				m-=a[i].w;
				ans++;
			}			
		}
		else
		{
			long long tmp=(long long)(m*1.0/a[i].w);
			if (tmp==0)
			{
				continue;
			}
			if (tmp&1) tmp--;
			ans+=tmp;
			m-=tmp*a[i].w;
		}
	}
	cout<<ans;
	return 0;
}
