#include<bits/stdc++.h>
#define p 998244353
using namespace std;
long long n,m,ans=0,mins=1e10,minn=0,x1=1e10,jud=0;
int f[100005][2];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
int read()
{
	long long x=0,f=1;char ch=getchar();
	while(ch<'0' or ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' and ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		f[i][0]=read();
		f[i][1]=read();
		//q.push(make_pair(x,y));
		if((f[i][0]+f[i][1])<mins){mins=f[i][0]+f[i][1];minn=i;}
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=minn&&f[i][0]<x1)x1=f[i][0];
	}
	if(m>=mins)
	{
		ans+=2*(m/mins);
		m-=mins*(m/mins);
		if(f[minn][1]>x1)
		{
			ans--;
			m+=f[minn][1];
			q.push(make_pair(f[minn][1],f[minn][0]));
			for(int i=1;i<=n;i++)
			{
				if(i!=minn)q.push(make_pair(f[i][0],f[i][1]));
			}
			jud=1;
		}
		else
		{
			for(int i=1;i<=n;i++)q.push(make_pair(f[i][0],f[i][1]));
		}
	}
	if(jud==0)
	{
	while(m>=q.top().first)
	 {
		ans++;
		m-=q.top().first;
		q.pop();
	 }
    }
    else
    {
		int minx=q.top().first,miny=q.top().second;
		q.pop();
		if(m>=minx)
		{
			ans++;
			m-=minx;
		}
		int x2=q.top().first,y2=q.top().second;
		while(miny>x2)
		{
			if(m>=x2)
			{
				ans++;
				m-=x2;
				if(y2<miny)
				{
					miny=y2;
					minx=x2;
					q.pop();
					x2=q.top().first;
					y2=q.top().second;
				}
				else
				{
					q.pop();
					x2=q.top().first;
					y2=q.top().second;
				}
			}
			else break;
		}
		if(m>=miny)
		{
			ans++;
			m-=miny;
			q.push(make_pair(minx,miny));
			while(m>=q.top().first)
	        {
	           ans++;
		       m-=q.top().first;
	       	   q.pop();
	        }
		}
	}
	cout<<ans;
	return 0;
}
