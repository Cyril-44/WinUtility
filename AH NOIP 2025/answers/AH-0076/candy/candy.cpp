#include<bits/stdc++.h>
using namespace std;
struct candy
{
	long long x,y;
	double s;
}a[100005],fs[100005],db[100005],lg[100005];
bool cmp1(candy i,candy j)
{
	return i.x<j.x;
}
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	long long n,m;
	double sm=8e18;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		a[i].s=(a[i].x+a[i].y)*1.0/2;
		sm=min(sm,a[i].s);
	}
	long long f=0,d=0,l=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i].x<sm)
		{
			f++;
			fs[f].x=a[i].x;
		}
		else
		{
			l++;
			lg[l].x=a[i].x;
		}
		if (a[i].s==sm)
		{
			d++;
			db[d].x=a[i].x;
			db[d].y=a[i].y;
			db[d].s=a[i].s;
		}		
	}
	long long ans=0;
	sort(fs+1,fs+f+1,cmp1);
	sort(lg+1,lg+l+1,cmp1);
	for (int i=1;i<=f;i++)
	{
		if (m-fs[i].x>=0)
		{
			ans++;
			m-=fs[i].x;
		}
	}
	int k=m/sm;
	ans+=k;
	m-=k*sm;
	for (int i=1;i<=l;i++)
	{
		if (m-lg[i].x>=0)
		{
			ans++;
			m-=lg[i].x;
		}
	}
	cout<<ans;
	return 0;
}
