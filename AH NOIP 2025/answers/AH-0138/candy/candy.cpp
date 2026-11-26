#include<bits/stdc++.h>
using namespace std;
long long m;
int n,c,flag,minn=1000000010;
struct coupl
{
	int x,y,sum;
}a[100010];
int cmp(coupl p,coupl q)
{
	return p.x<q.x;
}
void bfs(int where,int number,int cnt,int sum)
{
	if(sum==0||where==n+1)
	{
		c=max(c,cnt);
		cout<<c<<" "<<sum<<endl;
		return;
	}
	if(number==1)
	{
		if(sum>=a[where].x)
		{
			sum-=a[where].x;
			cnt++;
		}
	}
	if(number==2)
	{
		if(sum>=a[where].y)
		{
			sum-=a[where].y;
			cnt++;
		}
	}
	bfs( where+1,1,cnt,sum);
	if(number==2) 
	{
		if(sum>=a[where].x)
		{
			bfs( where, 1,cnt,sum);
		}
	}
	if(number==1) 
	{
		if(sum>=a[where].y)
		{
			bfs( where, 2,cnt,sum);
		}
	}
	
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		minn=min(minn,a[i].x);
		if(a[i].x!=a[i].y)
		{
			flag=1;
		}
	}
	if(flag==0)
	{
		c=m/minn;
	}
	else
	{
		sort(a+1,a+1+n,cmp);
		bfs(1,1,0,m);
	}
	cout<<c;
}
