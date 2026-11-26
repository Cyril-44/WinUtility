#include<bits/stdc++.h>
using namespace std;

long long n,m;
const int M=100006;

struct node{
	long long x,y,num;
}a[M];

int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	int sum1=0,sum2=0,sm[M],t[M][2],minx=100000010;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		a[i].num=1;
		sm[i]=a[i].x+a[i].y;
		if(sm[i]<=minx)
		{
			//mind=i;
			minx=sm[i];
		}
		t[i][1]=a[i].x,t[i][0]=a[i].y;
		if(a[i].x>=a[i].y)
		{
			sum1++;
		}
		if(a[i].x==a[i].y)
		{
			sum2++;
		}
	}
	//cout<<mind<<' '<<minx<<endl<<endl;
	if(n==1)
	{
		int ans=0;
		ans=2*(m/sm[1]);
		if(a[1].x<=m%sm[1])
		{
			ans+=1;
		}
		cout<<ans;
		return 0;
	}
	if(sum2==n)
	{
		long long min1=2000000010;
		for(int i=1;i<=n;i++)
		{
			if(sm[i]<=min1)
			{
				min1=sm[i];
			}
		}	
		int ans1=0;
		ans1=2*(m/min1);
		if(m%min1>=min1/2)
		{
			ans1+=1;
		}
		cout<<ans1;
		return 0;
	}
	if(sum2!=sum1&&sum1==n)
	{
		long long min1=2000000010,min2=1000000010;
		for(int i=1;i<n;i++)
		{
			if(sm[i]<=min1)
			{
				min1=sm[i];
			}
			if(a[i].x<=min2)
			{
				min2=a[i].x;
			}
		}
		int ans1=0;
		ans1=2*(m/min1);
		if(m%min1>=min2)
		{
			ans1+=1;
		}
		cout<<ans1;
		return 0;
	}
	if(sum2!=n&&sum1!=n)
	{
		int ans=0;
		int adr=0;
		//int pre[M],tot;
		//pre[0]=0;
		while(m>=0)
		{
			//tot++;
			long long min2=1000000010;
			long long min1=1000000010;
			for(int i=1;i<=n;i++)
			{	
				if(t[i][a[i].num%2]<=min1)
				{
					min1=t[i][a[i].num%2];
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(t[i][a[i].num%2]==min1&&t[i][(a[i].num+1)%2]<=min2)
				{
					min2=t[i][(a[i].num+1)%2];
					adr=i;
					//cout<<i<<' ';
				}
			}
			/*if(t[adr][a[adr].num%2]+t[pre[tot-1]][a[pre[tot-1]].num%2]>=minx)
			{
				ans+=2*(m/minx);
				m-=(m/minx)*sm[mind];
			}*/
			/*if(t[adr][a[adr].num%2]+t[adr][(a[adr].num+1)%2]>=minx)
			{
				ans+=2*(m/minx);
				m-=(m/minx)*sm[mind];
			}*/
			//cout<<endl;
			//cout<<adr<<endl;
			if(m>=t[adr][a[adr].num%2])
			{
				m-=t[adr][a[adr].num%2];
				a[adr].num++;
				ans++;
				//cout<<adr<<' '<<ans<<' '<<t[adr][(a[adr].num-1)%2]<<' '<<m<<endl;
			}
			else
			{
				//cout<<endl;
				//cout<<m<<' '<<t[adr][a[adr].num%2]<<' ';
				cout<<ans;
				return 0;
			}
		}
		//pre[tot]=adr;
		return 0;
	}
	return 0;
}
