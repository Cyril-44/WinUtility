#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long sum=0;
long long a[100010],b;
long long c=LLONG_MAX-1,cx=0,cy=0;
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b;
		if(a[i]+b<c)
		{
			c=a[i]+b;
			cx=a[i];
			cy=b;
		}
	}
	sort(a+1,a+n+1);
	sum+=(m/c)*2;
	m=m%c;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=m)
		{
			m-=a[i];
			sum++;
		}
		else
		{
			break;
		}
	}
	if(cx<cy) sum++;
	cout<<sum;
	return 0;
}
