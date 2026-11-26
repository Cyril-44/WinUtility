#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long x,y,sum;
}c[1000010];
bool cmp1(const Node &a,const Node &b)
{
	return a.sum<b.sum;
}
bool cmp2(const Node &a,const Node &b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	return a.sum<b.sum;
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	long long n,m,num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i].x>>c[i].y;
		c[i].sum=c[i].x+c[i].y;
	}
	sort(c+1,c+1+n,cmp1);
	num=(m/c[1].sum)*2;
	m%=c[1].sum;
	sort(c+1,c+1+n,cmp2);
	for(int i=1;i<=n;i++)
	{
		while(c[i].x<=m&&m)
		{
			num++;
			m-=c[i].x;
			if((c[i].y<=c[i+1].x&&c[i].sum<c[i+1].sum)&&c[i].y<=m)
			{
				num++;
				m-=c[i].y;
			}
			else
				break;
		}
	}
	cout<<num;
	return 0;
}
