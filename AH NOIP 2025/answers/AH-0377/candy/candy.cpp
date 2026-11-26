#include<bits/stdc++.h>
using namespace std;
struct candy
{
	long long x, y;
}a[100005];
bool cmp(candy a, candy b)
{
	return a.x+a.y<b.x+b.y; 
}
bool cmp1(candy a, candy b)
{
	return a.x<b.x; 
}
bool cmp2(candy a, candy b)
{
	return a.y<b.y; 
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n;
	scanf("%d",&n);
	long long m;
	scanf("%lld",&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i].x,&a[i].y);
	}
	sort(a+1,a+n+1,cmp);
	int x=a[1].x, y=a[1].y;
	sort(a+1,a+n+1,cmp1);
	long long ans=0;
	int id=0;
	for(int i=1;i<=n;i++)
	{
		if(m>=a[i].x && a[i].x*2<=x+y)
		{
			ans++;
			m-=a[i].x;
			id=i;
		}
		else
		{
			break;
		}
	}
	ans+=m/(x+y)*2;
	m=m%(x+y);
	for(int i=id;i>=1;i--)
	{
		if((m+a[i].x)>=(x+y))
		{
			ans++;
			m=m+a[i].x-(x+y);
			id=i;
		}
	}
	for(int i=1;i<=id;i++)
	{
		a[i].x=1000000000000000007;
	}
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n;i++)
	{
		if(m>=a[i].x)
		{
			ans++;
			m-=a[i].x;
		}
		else
		{
			break;
		}
	}
	printf("%lld",ans);
	return 0;
}
/*!noip@Nov29,2025:dream*/
