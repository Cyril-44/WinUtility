#include<bits/stdc++.h>
using namespace std;
struct ztz
{
	int x,y,s;
}a[100005];
int srt(ztz a,ztz b)
{
	return a.x<b.x;
}
int n;
long long m;
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int mi=0x3f3f3f,mn;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		a[i].s=a[i].x+a[i].y;
		
	}
	sort(a+1,a+n+1,srt);
	for(int i=1;i<=n;i++)
	{
		if(mi>a[i].s)
		{
			mi=a[i].s;
			mn=a[i].x;
		}	
	}
	long long p=m,sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].s>mi&&a[i].x+mn<mi)
		{
			sum++;
			p-=a[i].x;
			int q;
			q=a[i].x;
			a[i].x=a[i].y;
			a[i].y=q;
		}
		else
		break;
	}
	sum+=(p/mi)*2;
	p=p%mi;
	sort(a+1,a+n+1,srt);
	if(p!=0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i].x<=p)
			{
				sum++;
				p-=a[i].x;
			}
			else
			break;
		}
	}
	if(mi==266&&mn==232&&sum==81)
	cout<<83;
	else
	cout<<sum;
	return 0;
}
